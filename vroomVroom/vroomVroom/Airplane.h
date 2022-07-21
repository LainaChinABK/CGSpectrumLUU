#pragma once
#include "Vehicle.h"
class Airplane :
    public Vehicle
{
public:
    Airplane();
    virtual void Drive() override;
};

