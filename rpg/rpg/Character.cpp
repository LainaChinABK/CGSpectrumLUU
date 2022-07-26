#include "Character.h"
#include <iostream>

Character::Character(int weapon, int armor)
	: m_curHealth(100)
	, m_maxHealth(100)
	, m_alive(true)
	, m_minDamage(0)
	, m_maxDamage(0)
	, m_weapon(new Weapon(weapon))
	, m_armor(new Armor(armor))
{

}

Character::~Character()
{
	delete m_weapon;
	delete m_armor;
}

void Character::DisplayInfo()
{
	std::cout << "Health: " << m_curHealth << std::endl;
	std::cout << "Weapon: " << GetWeaponName() << std::endl;
	std::cout << "Armor: " << GetArmorName() << std::endl;
}

void Character::SetWeapon(int weapon)
{
	delete m_weapon;
	m_weapon = new Weapon(weapon);
}

void Character::SetArmor(int armor)
{
	delete m_armor;
	m_armor = new Armor(armor);
}

void Character::TakeDamage(int damage)
{
	if (damage >= m_curHealth)
	{
		m_curHealth = 0;
		m_alive = false;
	}
	else
	{
		m_curHealth -= damage;
	}
}