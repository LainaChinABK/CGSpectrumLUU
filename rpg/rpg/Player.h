#pragma once
#include "Character.h"
#include <string>

class Player :
    public Character
{
public:
    Player();
    ~Player();

    void ChooseName();
    void ChooseWeapon();
    void ChooseArmor();

    std::string GetName() { return m_name; }

    void Rest() { m_curHealth = std::min(m_curHealth + 20, m_maxHealth); }

private:
    std::string m_name;
};