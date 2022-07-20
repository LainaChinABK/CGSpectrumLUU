// rpg.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

// function declarations
string getName();
int getWeapon();
int getArmor();

int main()
{
    // ask player for name
    string name = getName();
 
    // start with 100 health
    int health = 100;
 
    // select weapon and armor
    int weapon = getWeapon();
    int armor = getArmor();

    // print name, weapon, and armor
    cout << name << ", you will be using weapon #" << weapon << " and armor #" << armor << endl;

    // face an enemy with 100 health

    // deal damage to enemy 5 times
    // deal 10 damage with each hit
    // take 7 damage from each hit

    // show player health and enemy health
}

string getName()
{
    string name;
    cout << "What is your name? ";
    cin >> name;

    return name;
}

// pick a weapon:
//     (1) bow
//     (2) sword
//     (3) axe
int getWeapon()
{
    int weapon = 0;

    // loop until player selects valid weapon
    do
    {
        cout << "Choose your weapon:" << endl;
        cout << "   (1) bow" << endl;
        cout << "   (2) sword" << endl;
        cout << "   (3) axe" << endl;

        cin >> weapon;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(100, '\n');
        }

        else if (weapon > 0 && weapon < 4)
        {
            return weapon;
        }
    } while (true);
}

// pick armor:
//     (1) light
//     (2) medium
//     (3) heavy
int getArmor()
{
    int armor = 0;

    // loop until player selects valid armor
    do
    {
        cout << "Choose your armor:" << endl;
        cout << "   (1) light" << endl;
        cout << "   (2) medium" << endl;
        cout << "   (3) heavy" << endl;

        cin >> armor;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(100, '\n');
        }

        else if (armor > 0 && armor < 4)
        {
            return armor;
        }
    } while (true);
}