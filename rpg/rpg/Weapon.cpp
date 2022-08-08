#include "Weapon.h"

// diff weapon options and their IDs
constexpr int sword = 1;
constexpr int axe = 2;

Weapon::Weapon(int id)
	: Item(id)
{
	switch (id)
	{
	case sword:
		m_name = "Sword";
		m_minDamage = 4;
		m_maxDamage = 6;
		break;

	case axe:
		m_name = "Axe";
		m_minDamage = 2;
		m_maxDamage = 8;
		break;

	default:
		m_id = 0;
		m_name = "None";
		m_minDamage = 1;
		m_maxDamage = 5;
		break;
	}
	
}

Weapon::~Weapon()
{

}

int Weapon::GetDamage()
{
	return m_minDamage + (rand() % (m_maxDamage - m_minDamage + 1));
}