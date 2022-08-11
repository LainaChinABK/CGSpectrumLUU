#include <enet/enet.h>
#include <string>
#include <iostream>
#include <thread>

using namespace std;

ENetHost* NetHost = nullptr;
ENetPeer* Peer = nullptr;
bool IsServer = false;
thread* PacketThread = nullptr;

int maxNum = 10;
bool GameOver = false;
bool CanGuess = false;
int players = 0;
int num = 0;
int guess = 0;

// some function declarations
void CheckGuess(int guess);
void BroadcastGameOverPacket();

enum PacketHeaderTypes
{
    PHT_Invalid = 0,
    PHT_IsDead,
    PHT_Position,
    PHT_Count,
    PHT_Prompt,
    PHT_Guess,
    PHT_Check,
    PHT_GameOver
};

struct GamePacket
{
    GamePacket() {}
    PacketHeaderTypes Type = PHT_Invalid;
};

struct IsDeadPacket : public GamePacket
{
    IsDeadPacket()
    {
        Type = PHT_IsDead;
    }

    int playerId = 0;
    bool IsDead = false;
};

struct PositionPacket : public GamePacket
{
    PositionPacket()
    {
        Type = PHT_Position;
    }

    int playerId = 0;
    int x = 0;
    int y = 0;
};

struct PromptGuessPacket : public GamePacket
{
    PromptGuessPacket()
    {
        Type = PHT_Prompt;
    }
};

struct GuessNumPacket : public GamePacket
{
    GuessNumPacket()
    {
        Type = PHT_Guess;
    }

    int val = 0;
};

struct CheckGuessPacket : public GamePacket
{
    CheckGuessPacket()
    {
        Type = PHT_Check;
    }

    bool correct = false;
};

struct GameOverPacket : public GamePacket
{
    GameOverPacket()
    {
        Type = PHT_GameOver;
    }
};

//can pass in a peer connection if wanting to limit
bool CreateServer()
{
    ENetAddress address;
    address.host = ENET_HOST_ANY;
    address.port = 1234;
    NetHost = enet_host_create(&address /* the address to bind the server host to */,
        32      /* allow up to 32 clients and/or outgoing connections */,
        2      /* allow up to 2 channels to be used, 0 and 1 */,
        0      /* assume any amount of incoming bandwidth */,
        0      /* assume any amount of outgoing bandwidth */);

    return NetHost != nullptr;
}

bool CreateClient()
{
    NetHost = enet_host_create(NULL /* create a client host */,
        1 /* only allow 1 outgoing connection */,
        2 /* allow up 2 channels to be used, 0 and 1 */,
        0 /* assume any amount of incoming bandwidth */,
        0 /* assume any amount of outgoing bandwidth */);

    return NetHost != nullptr;
}

bool AttemptConnectToServer()
{
    ENetAddress address;
    /* Connect to some.server.net:1234. */
    enet_address_set_host(&address, "127.0.0.1");
    address.port = 1234;
    /* Initiate the connection, allocating the two channels 0 and 1. */
    Peer = enet_host_connect(NetHost, &address, 2, 0);
    return Peer != nullptr;
}

void HandleReceivePacket(const ENetEvent& event)
{
    GamePacket* RecGamePacket = (GamePacket*)(event.packet->data);
    if (RecGamePacket)
    {
        cout << "Received Game Packet " << endl;

        if (RecGamePacket->Type == PHT_IsDead)
        {
            cout << "u dead?" << endl;
            IsDeadPacket* DeadGamePacket = (IsDeadPacket*)(event.packet->data);
            if (DeadGamePacket)
            {
                string response = (DeadGamePacket->IsDead ? "yeah" : "no");
                cout << response << endl;
            }
        }
        if (RecGamePacket->Type == PHT_Prompt)
        {
            cout << "I'm thinking of a number between 1 and " << maxNum << " (inclusive)..." << endl;
            CanGuess = true;
        }
        if (RecGamePacket->Type == PHT_Guess)
        {
            GuessNumPacket* GuessPacket = (GuessNumPacket*)(event.packet->data);
            if (GuessPacket)
            {
                if (IsServer)
                {
                    CheckGuess(GuessPacket->val);
                    // this if statement is probably redundant and/or needs to go somewhere else
                    if (GuessPacket->val == num)
                    {
                        BroadcastGameOverPacket();
                    }
                }
                else
                {
                    // TODO: figure out why this statement isn't printing
                    cout << "Player guessed " << GuessPacket->val << endl;
                    CanGuess = false;
                }
            }
        }
        if (RecGamePacket->Type == PHT_Check)
        {
            CheckGuessPacket* CheckPacket = (CheckGuessPacket*)(event.packet->data);
            if (CheckPacket)
            {
                if (CheckPacket->correct)
                {
                    cout << "You got it!" << endl;
                    GameOver = true;
                }
                else
                {
                    cout << "Incorrect. Please try again." << endl;
                    CanGuess = true;
                }
            }
        }
        if (RecGamePacket->Type == PHT_GameOver)
        {
            cout << "The game is now over. Goodbye!" << endl;
        }
    }
    else
    {
        cout << "Invalid Packet " << endl;
    }

    /* Clean up the packet now that we're done using it. */
    enet_packet_destroy(event.packet);
    {
        enet_host_flush(NetHost);
    }
}

void BroadcastIsDeadPacket()
{
    IsDeadPacket* DeadPacket = new IsDeadPacket();
    DeadPacket->IsDead = true;
    ENetPacket* packet = enet_packet_create(DeadPacket,
        sizeof(IsDeadPacket),
        ENET_PACKET_FLAG_RELIABLE);

    /* One could also broadcast the packet by         */
    enet_host_broadcast(NetHost, 0, packet);
    //enet_peer_send(event.peer, 0, packet);

    /* One could just use enet_host_service() instead. */
    //enet_host_service();
    enet_host_flush(NetHost);
    delete DeadPacket;
}

void PromptPlayers()
{
    PromptGuessPacket* PromptPacket = new PromptGuessPacket();
    ENetPacket* packet = enet_packet_create(PromptPacket,
        sizeof(PromptGuessPacket),
        ENET_PACKET_FLAG_RELIABLE);

    enet_host_broadcast(NetHost, 0, packet);

    enet_host_flush(NetHost);
    delete PromptPacket;
}

void SendGuess(int guess)
{
    GuessNumPacket* GuessPacket = new GuessNumPacket();
    GuessPacket->val = guess;
    ENetPacket* packet = enet_packet_create(GuessPacket,
        sizeof(GuessNumPacket),
        ENET_PACKET_FLAG_RELIABLE);

    // might want to figure out how to only send to server
    enet_host_broadcast(NetHost, 0, packet);

    enet_host_flush(NetHost);
    delete GuessPacket;
}

void CheckGuess(int guess)
{
    CheckGuessPacket* CheckPacket = new CheckGuessPacket();
    CheckPacket->correct = (guess == num);
    ENetPacket* packet = enet_packet_create(CheckPacket,
        sizeof(CheckGuessPacket),
        ENET_PACKET_FLAG_RELIABLE);

    enet_host_broadcast(NetHost, 0, packet);

    enet_host_flush(NetHost);
    delete CheckPacket;
}

void BroadcastGameOverPacket()
{
    GameOverPacket* EndPacket = new GameOverPacket();
    ENetPacket* packet = enet_packet_create(EndPacket,
        sizeof(EndPacket),
        ENET_PACKET_FLAG_RELIABLE);

    enet_host_broadcast(NetHost, 0, packet);

    enet_host_flush(NetHost);
    delete EndPacket;
}

void ServerProcessPackets()
{
    while (!GameOver)
    {
        ENetEvent event;
        while (enet_host_service(NetHost, &event, 1000) > 0)
        {
            switch (event.type)
            {
            case ENET_EVENT_TYPE_CONNECT:
                cout << "A new client connected from "
                    << event.peer->address.host
                    << ":" << event.peer->address.port
                    << endl;
                /* Store any relevant client information here. */
                event.peer->data = (void*)("Client information");
                BroadcastIsDeadPacket();
                players++;

                // Wait for two players to start game
                // Potential issue if player(s) disconnect and then rejoin?
                if (players == 2)
                {
                    num = rand() % maxNum + 1;
                    // TODO: broadcast message below instead of just printing to server
                    cout << "Let the game begin!" << endl;
                    PromptPlayers();
                }
                break;
            case ENET_EVENT_TYPE_RECEIVE:
                HandleReceivePacket(event);
                break;

            case ENET_EVENT_TYPE_DISCONNECT:
                cout << (char*)event.peer->data << "disconnected." << endl;
                /* Reset the peer's client information. */
                event.peer->data = NULL;
                players--;
                //notify remaining player that the game is done due to player leaving
                if (players < 2)
                {
                    GameOver = true;
                    BroadcastGameOverPacket();
                }
            }
        }
    }
}

void ClientProcessPackets()
{
    while (!GameOver)
    {
        if (CanGuess)
        {
            cin >> guess;
            SendGuess(guess);
            CanGuess = false;
        }
        ENetEvent event;
        /* Wait up to 1000 milliseconds for an event. */
        while (enet_host_service(NetHost, &event, 1000) > 0)
        {
            switch (event.type)
            {
            case  ENET_EVENT_TYPE_CONNECT:
                cout << "Connection succeeded " << endl;
                break;
            case ENET_EVENT_TYPE_RECEIVE:
                HandleReceivePacket(event);
                break;
            }
        }
    }
}

int main(int argc, char** argv)
{
    srand(time(NULL));

    if (enet_initialize() != 0)
    {
        fprintf(stderr, "An error occurred while initializing ENet.\n");
        cout << "An error occurred while initializing ENet." << endl;
        return EXIT_FAILURE;
    }
    atexit(enet_deinitialize);

    cout << "1) Create Server " << endl;
    cout << "2) Create Client " << endl;
    int UserInput;
    cin >> UserInput;

    if (UserInput == 1)
    {
        //How many players?

        if (!CreateServer())
        {
            fprintf(stderr,
                "An error occurred while trying to create an ENet server.\n");
            exit(EXIT_FAILURE);
        }

        IsServer = true;
        cout << "waiting for players to join..." << endl;
        PacketThread = new thread(ServerProcessPackets);
    }
    else if (UserInput == 2)
    {
        if (!CreateClient())
        {
            fprintf(stderr,
                "An error occurred while trying to create an ENet client host.\n");
            exit(EXIT_FAILURE);
        }

        ENetEvent event;
        if (!AttemptConnectToServer())
        {
            fprintf(stderr,
                "No available peers for initiating an ENet connection.\n");
            exit(EXIT_FAILURE);
        }

        PacketThread = new thread(ClientProcessPackets);

        //handle possible connection failure
        {
            //enet_peer_reset(Peer);
            //cout << "Connection to 127.0.0.1:1234 failed." << endl;
        }
    }
    else
    {
        cout << "Invalid Input" << endl;
    }


    if (PacketThread)
    {
        PacketThread->join();
    }
    delete PacketThread;
    if (NetHost != nullptr)
    {
        enet_host_destroy(NetHost);
    }

    return EXIT_SUCCESS;
}