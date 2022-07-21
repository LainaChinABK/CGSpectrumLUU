#pragma once

class Character
{
protected:
	int m_health;
	int m_weapon;
	int m_armor;

public:
	Character(int weapon = 0, int armor = 0);
	~Character();

	void SetWeapon(int weapon) { m_weapon = weapon; }
	void SetArmor(int armor) { m_armor = armor; }

	int GetHealth() { return m_health; }
	int GetWeapon() { return m_weapon; }
	int GetArmor() { return m_armor; }
};

