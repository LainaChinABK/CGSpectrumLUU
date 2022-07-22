// leapYear.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

// function declaration
bool leap(int year);

int main()
{
    // initialize to current year
    int year = 2022;

    // prompt user for year
    cout << "What year is it? ";
    cin >> year;

    // call function and print result
    if (leap(year))
    {
        cout << year << " is a leap year!" << endl;
    }
    else
    {
        cout << year << " is not a leap year." << endl;
    }
}

// function definition
bool leap(int year)
{
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
    {
        return true;
    }
    return false;
}