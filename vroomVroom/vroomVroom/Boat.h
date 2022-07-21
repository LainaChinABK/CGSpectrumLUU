#pragma once
#include "Vehicle.h"
class Boat :
    public Vehicle
{
public:
    Boat();
    virtual void Drive() override;
};