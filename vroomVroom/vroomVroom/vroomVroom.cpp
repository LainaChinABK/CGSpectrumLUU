// vroomVroom.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Boat.h"
#include "Car.h"
#include "Airplane.h"

using namespace std;

int main()
{
    Boat* boat = new Boat;
    cout << "boat mileage: " << boat->getMiles() << endl;
    boat->Drive();
    cout << "boat mileage: " << boat->getMiles() << endl;
    delete boat;

    Car* car = new Car;
    cout << "car mileage: " << car->getMiles() << endl;
    car->Drive();
    cout << "car mileage: " << car->getMiles() << endl;
    delete car;

    Airplane* airplane = new Airplane;
    cout << "airplane mileage: " << airplane->getMiles() << endl;
    airplane->Drive();
    cout << "airplane mileage: " << airplane->getMiles() << endl;
}