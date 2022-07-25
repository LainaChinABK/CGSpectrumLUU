#include "Weapon.h"

constexpr int bow = 1;
constexpr int sword = 2;
constexpr int axe = 3;

Weapon::Weapon(int id)
	: Item(id)
{
	switch (id)
	{
	case bow:
		m_name = "Bow";
		break;

	case sword:
		m_name = "Sword";
		break;

	case axe:
		m_name = "Axe";
		break;

	default:
		m_name = "None";
		break;
	}
	
}

Weapon::~Weapon()
{

}