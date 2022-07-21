#include "Player.h"
#include <iostream>

Player::Player()
	: Character()
{
    ChooseName();
    ChooseWeapon();
    ChooseArmor();
}

Player::~Player()
{

}

void Player::ChooseName()
{
    std::string name;
    std::cout << "What is your name? ";
    std::cin >> name;

    m_name = name;
}

void Player::ChooseWeapon()
{
    int weapon = 0;

    // loop until player selects valid weapon
    do
    {
        std::cout << "Choose your weapon:" << std::endl;
        std::cout << "   (1) bow" << std::endl;
        std::cout << "   (2) sword" << std::endl;
        std::cout << "   (3) axe" << std::endl;

        std::cin >> weapon;
    } while (weapon < 1 || weapon > 3);

    m_weapon = weapon;
}

void Player::ChooseArmor()
{
    int armor = 0;

    // loop until player selects valid armor
    do
    {
        std::cout << "Choose your armor:" << std::endl;
        std::cout << "   (1) light" << std::endl;
        std::cout << "   (2) medium" << std::endl;
        std::cout << "   (3) heavy" << std::endl;

        std::cin >> armor;
    } while (armor < 1 || armor > 3);

    m_armor = armor;
}