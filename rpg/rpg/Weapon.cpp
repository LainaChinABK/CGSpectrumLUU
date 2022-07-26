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
		break;

	case axe:
		m_name = "Axe";
		break;

	default:
		m_id = 0;
		m_name = "None";
		break;
	}
	
}

Weapon::~Weapon()
{

}