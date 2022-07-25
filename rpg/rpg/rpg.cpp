// rpg.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Player.h"
#include "Enemy.h"

constexpr int g_rounds = 5;

void PlayGame(Player* player, Enemy* enemy);
void Encounter(Player* player, Enemy* enemy);
void Round(Player* player, Enemy* enemy);

int main()
{
    Player* player = new Player();

    // print name, weapon, and armor
    std::cout << player->GetName() << ", you will be using weapon #" << player->GetWeapon() << " and armor #" << player->GetArmor() << std::endl;

    // face an enemy with 100 health
    Enemy* enemy = new Enemy();
    std::cout << "Enemy has weapon #" << enemy->GetWeapon() << " and armor #" << enemy->GetArmor() << std::endl;

    PlayGame(player, enemy);
    // deal damage to enemy 5 times
    // deal 10 damage with each hit
    // take 7 damage from each hit

    // show player health and enemy health

    delete player;
    delete enemy;
}

void PlayGame(Player* player, Enemy* enemy)
{
    for (int i = 0; i < 3; i++)
    {
        Encounter(player, enemy);
    }
}

void Encounter(Player* player, Enemy* enemy)
{
    for (int i = 0; i < g_rounds; i++)
    {
        Round(player, enemy);
    }
}

void Round(Player* player, Enemy* enemy)
{
    player->TakeDamage(7);
    enemy->TakeDamage(10);

    std::cout << "Player health: " << player->GetHealth() << std::endl;
    std::cout << "Enemy health: " << enemy->GetHealth() << std::endl;
}
