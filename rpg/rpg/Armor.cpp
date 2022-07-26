#include "Armor.h"

// diff armor options and their IDs
constexpr int light = 1;
constexpr int medium = 2;
constexpr int heavy = 3;

Armor::Armor(int id)
	: Item(id)
{
	switch (id)
	{
	case light:
		m_name = "Light";
		break;

	case medium:
		m_name = "Medium";
		break;

	case heavy:
		m_name = "Heavy";
		break;
		
	default:
		m_id = 0;
		m_name = "None";
	}
}

Armor::~Armor()
{

}