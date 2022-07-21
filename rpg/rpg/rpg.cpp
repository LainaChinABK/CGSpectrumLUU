// rpg.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Player.h"

int main()
{
    Player* player = new Player;

    // print name, weapon, and armor
    std::cout << player->GetName() << ", you will be using weapon #" << player->GetWeapon() << " and armor #" << player->GetArmor() << std::endl;

    // face an enemy with 100 health

    // deal damage to enemy 5 times
    // deal 10 damage with each hit
    // take 7 damage from each hit

    // show player health and enemy health

    delete player;
}