#pragma once
#include "Item.h"

class Weapon :
    public Item
{
public:
    Weapon(int id);
    ~Weapon();

    int GetDamage();

private:
    int m_minDamage;
    int m_maxDamage;
};