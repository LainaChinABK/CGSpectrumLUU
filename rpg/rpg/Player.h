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

private:
    std::string m_name;
};