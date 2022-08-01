// rpg.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Player.h"
#include "Enemy.h"

// function declarations
void Continue();

void PlayGame(Player* player);
void Encounter(Player* player);
void Round(int round, Player* player, Enemy* enemy);

int main()
{
    // initialize new player
    Player* player = new Player();
    std::cout << std::endl << "Player: " << player->GetName() << std::endl;
    player->DisplayInfo();
    std::cout << std::endl;
    Continue();
    
    // play game
    PlayGame(player);

    // free memory
    delete player;
}

// from Ather's github ; doesn't seem to be working
void Continue()
{
    std::cout << "Press any key to continue" << std::endl;
    std::cin.ignore();
    std::cin.get();
}

void PlayGame(Player* player)
{
    // initialize variable
    char rest = 'n';

    // max 3 encounters
    for (int i = 0; i < 3; i++)
    {
        std::cout << "Encounter #" << i + 1 << std::endl << std::endl;
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
        Continue();
    }

    // free memory
    delete enemy;
}

void Round(int round, Player* player, Enemy* enemy)
{
    std::cout << std::endl << "Round " << round << ":" << std::endl;

    int pDamage = 10;
    int eDamage = 7;
    player->TakeDamage(eDamage);
    enemy->TakeDamage(pDamage);

    // print damage taken and inflicted
    std::cout << player->GetName() << " deals " << pDamage << " damage!" << std::endl;
    std::cout << "Enemy deals " << eDamage << " damage!" << std::endl;

    // show player health and enemy health
    std::cout << std::endl << "Your health: " << player->GetHealth() << std::endl;
    std::cout << "Enemy health: " << enemy->GetHealth() << std::endl << std::endl;
}