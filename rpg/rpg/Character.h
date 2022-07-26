#pragma once
#include "Weapon.h"
#include "Armor.h"
#include <iostream>

class Character
{
protected:
	int m_curHealth;
	int m_maxHealth;
	bool m_alive;

	int m_minDamage;
	int m_maxDamage;
	
	Weapon* m_weapon;
	Armor* m_armor;

public:
	Character(int weapon = 0, int armor = 0);
	~Character();

	void DisplayInfo();

	int GetHealth() const { return m_curHealth; }
	bool IsAlive() const { return m_alive; }

	void SetWeapon(int weapon);
	void SetArmor(int armor);

	std::string GetWeaponName() const { return m_weapon->GetName(); }
	int GetWeaponID() const { return m_weapon->GetID(); }

	std::string GetArmorName() const { return m_armor->GetName(); }
	int GetArmorID() const { return m_armor->GetID(); }

	void TakeDamage(int damage);
};

