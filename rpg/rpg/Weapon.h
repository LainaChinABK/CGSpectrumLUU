#pragma once
#include "Item.h"

class Weapon :
    public Item
{
public:
    Weapon(int id);
    ~Weapon();
};