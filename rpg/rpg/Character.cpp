#include "Character.h"

// diff weapon options and their IDs
constexpr int sword = 1;
constexpr int axe = 2;

// diff armor options and their IDs
constexpr int light = 1;
constexpr int medium = 2;
constexpr int heavy = 3;

Character::Character(int weapon, int armor)
	: m_curHealth(100)
	, m_maxHealth(100)
	, m_weapon(new Weapon(weapon))
	, m_armor(new Armor(armor))
{

}

Character::~Character()
{
	delete m_weapon;
	m_weapon = nullptr;

	delete m_armor;
	m_armor = nullptr;
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

	switch (armor)
	{
	case light:
		m_curHealth += 10;
		m_maxHealth += 10;
	
	case medium:
		m_curHealth += 25;
		m_maxHealth += 25;

	case heavy:
		m_curHealth += 50;
		m_maxHealth += 50;

	// default is no armor so no extra health
	}
}

void Character::TakeDamage(int damage)
{
	if (damage >= m_curHealth)
	{
		m_curHealth = 0;
	}
	else
	{
		m_curHealth -= damage;
	}
}