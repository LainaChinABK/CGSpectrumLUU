#include "Player.h"

// diff weapon options and their IDs
constexpr int sword = 1;
constexpr int axe = 2;

// diff armor options and their IDs
constexpr int light = 1;
constexpr int medium = 2;
constexpr int heavy = 3;

// constructor calls functions to choose name, weapon, and armor
Player::Player()
	: Character()
{
    m_minDamage = 5;
    m_maxDamage = 10;

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
        std::cout << "   (" << sword << ") sword" << std::endl;
        std::cout << "   (" << axe << ") axe" << std::endl;

        std::cin >> weapon;
    } while (weapon < 1 || weapon > 2);

    SetWeapon(weapon);
}

void Player::ChooseArmor()
{
    int armor = 0;

    // loop until player selects valid armor
    do
    {
        std::cout << "Choose your armor:" << std::endl;
        std::cout << "   (" << light << ") light" << std::endl;
        std::cout << "   (" << medium << ") medium" << std::endl;
        std::cout << "   (" << heavy << ") heavy" << std::endl;

        std::cin >> armor;
    } while (armor < 1 || armor > 3);

    SetArmor(armor);
}