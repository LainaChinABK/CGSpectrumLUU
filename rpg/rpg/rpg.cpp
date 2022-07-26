// rpg.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Player.h"
#include "Enemy.h"

// function declarations
void PlayGame(Player* player);
void Encounter(Player* player);
void Round(int round, Player* player, Enemy* enemy);

int main()
{
    // initialize new player
    Player* player = new Player();
    std::cout << "Player: " << player->GetName() << std::endl;
    player->DisplayInfo();
    
    // play game
    PlayGame(player);

    // free memory
    delete player;
}

void PlayGame(Player* player)
{
    // initialize variable
    char rest = 'n';

    // max 3 encounters
    for (int i = 0; i < 3; i++)
    {
        Encounter(player);

        if (!player->IsAlive())
        {
            std::cout << "You died." << std::endl;
            break;
        }

        // TODO: add option to exit

        // option to rest
        std::cout << "You have " << player->GetHealth() << " health." << std::endl;
        std::cout << "Would you like to rest before your next encounter? (y/n)" << std::endl;
        std::cin >> rest;

        if (tolower(rest) == 'y')
        {
            player->Rest();
        }
    }
}

void Encounter(Player* player)
{
    // face an enemy with 100 health
    Enemy* enemy = new Enemy();
    std::cout << "An enemy appeared!" << std::endl;
    enemy->DisplayInfo();

    // unlimited rounds
    for (int round = 1; player->IsAlive() && enemy->IsAlive(); round++)
    {
        Round(round, player, enemy);
    }

    // free memory
    delete enemy;
}

void Round(int round, Player* player, Enemy* enemy)
{
    std::cout << std::endl << "Round " << round << ":" << std::endl;
    player->TakeDamage(7);
    enemy->TakeDamage(10);

    // show player health and enemy health
    std::cout << "Your health: " << player->GetHealth() << std::endl;
    std::cout << "Enemy health: " << enemy->GetHealth() << std::endl << std::endl;
}
