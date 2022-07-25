#pragma once
#include "Item.h"
#include <string>

class Weapon :
    public Item
{
public:
    Weapon(int id);
    ~Weapon();
};