#pragma once
#include "Vehicle.h"
class Car :
    public Vehicle
{
public:
    Car();
    virtual void Drive() override;
};
