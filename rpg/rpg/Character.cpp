#include "Character.h"

Character::Character(int weapon, int armor)
	: m_health(100)
	, m_weapon(weapon)
	, m_armor(armor)
	, m_alive(true)
{

}

Character::~Character()
{

}

void Character::TakeDamage(int damage)
{
	if (damage >= m_health)
	{
		m_health = 0;
		m_alive = false;
	}
	else
	{
		m_health -= damage;
	}
}