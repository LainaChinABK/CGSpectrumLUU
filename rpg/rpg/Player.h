#pragma once
#include "Character.h"

class Player :
    public Character
{
public:
    Player();
    ~Player();

    void ChooseName();
    void ChooseWeapon();
    void ChooseArmor();

    std::string GetName() const { return m_name; }

    void Rest() { m_curHealth = std::min(m_curHealth + 20, m_maxHealth); }

private:
    std::string m_name;
};