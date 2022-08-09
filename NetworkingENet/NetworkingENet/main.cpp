#include <enet/enet.h>
#include <iostream>
#include <thread>
#include "Message.h"

ENetAddress address;
ENetHost* server = nullptr;
ENetHost* client = nullptr;
ENetPeer* peer = nullptr;

bool CreateServer();
bool CreateClient();

std::string GetName();

int main(int argc, char** argv)
{
    if (enet_initialize() != 0)
    {
        fprintf(stderr, "An error occurred while initializing ENet.\n");
        std::cout << "An error occurred while initializing ENet." << std::endl;
        return EXIT_FAILURE;
    }
    atexit(enet_deinitialize);

    std::cout << "1) Create server" << std::endl;
    std::cout << "2) Create client" << std::endl;
    
    int input = 0;
    std::cin >> input;

    if (input == 1)
    {
        if (!CreateServer())
        {
            fprintf(stderr,
                "An error occurred while trying to create an ENet server host.\n");
            exit(EXIT_FAILURE);
        }

        std::string serverName = GetName();

        while (1)
        {
            ENetEvent event;
            ENetPacket* packet;
            std::string serverMessage;

            if (peer)
            {
                std::cin >> serverMessage;

                Message message = Message(serverName, serverMessage);

                packet = enet_packet_create(&message,
                    sizeof(Message) + 1,
                    ENET_PACKET_FLAG_RELIABLE);

                enet_peer_send(peer, 0, packet);
                enet_host_flush(server);
            }

            /* Wait up to 1000 milliseconds for an event. */
            while (enet_host_service(server, &event, 1000) > 0)
            {
                switch (event.type)
                {
                case ENET_EVENT_TYPE_CONNECT:
                    std::cout << "A new client connected from " << event.peer->address.host << ":" << event.peer->address.port << "." << std::endl;
                    event.peer->data = (void*)("Client information");
                    peer = event.peer;
                    break;

                case ENET_EVENT_TYPE_DISCONNECT:
                    std::cout << event.peer->data << " disconnected." << std::endl;
                    event.peer->data = nullptr;
                    break;

                case ENET_EVENT_TYPE_RECEIVE:
                    Message* message = (Message*)event.packet->data;
                    message->DisplayContent();

                    enet_packet_destroy(event.packet);
                }
            }
        }

    }
    else if (input == 2)
    {
        if (!CreateClient())
        {
            fprintf(stderr,
                "An error occurred while trying to create an ENet client host.\n");
            exit(EXIT_FAILURE);
        }

        std::string clientName = GetName();

        ENetEvent event;
        ENetPacket* packet;
        std::string clientMessage;

        enet_address_set_host(&address, "127.0.0.1");
        address.port = 1234;
        peer = enet_host_connect(client, &address, 2, 0);
        if (peer == nullptr)
        {
            fprintf(stderr,
                "No available peers for initiating an ENet connection.\n");
            exit(EXIT_FAILURE);
        }

        if (enet_host_service(client, &event, 5000) > 0 && event.type == ENET_EVENT_TYPE_CONNECT)
        {
            std::cout << "Connection to 127.0.0.1:1234 succeeded." << std::endl;
        }
        else
        {
            enet_peer_reset(peer);
            std::cout << "Connection to 127.0.0.1:1234 failed." << std::endl;
        }

        while (1)
        {
            if (peer)
            {
                std::cin >> clientMessage;

                Message message = Message(clientName, clientMessage);

                packet = enet_packet_create(&message,
                    sizeof(Message) + 1,
                    ENET_PACKET_FLAG_RELIABLE);

                enet_peer_send(peer, 0, packet);
                enet_host_flush(client);
            }

            while (enet_host_service(client, &event, 1000) > 0)
            {
                switch (event.type)
                {
                case ENET_EVENT_TYPE_RECEIVE:
                    Message* message = (Message*)event.packet->data;

                    message->DisplayContent();
                    enet_packet_destroy(event.packet);
                }
            }
        }
    }
    else
    {
        std::cout << "Invalid input!" << std::endl;
    }
        

    if (server != nullptr)
    {
        enet_host_destroy(server);
    }

    if (client != nullptr)
    {
        enet_host_destroy(client);
    }

    return EXIT_SUCCESS;
}

bool CreateServer()
{
    address.host = ENET_HOST_ANY;
    address.port = 1234;
    server = enet_host_create(&address, 32, 2, 0, 0);

    return server != nullptr;
}

bool CreateClient()
{
    client = enet_host_create(NULL, 1, 2, 0, 0);

    return client != nullptr;
}

std::string GetName()
{
    std::string name;
    std::cout << "What is your name? ";
    std::cin >> name;
    return name;
}