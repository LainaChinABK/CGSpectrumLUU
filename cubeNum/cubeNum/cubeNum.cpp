// cubeNum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int cube(int n);

int main()
{
    // Get number from user
    int n = 0;
    cout << "Number: ";
    cin >> n;

    // Print answer
    cout << n << " cubed is " << cube(n) << endl;
}

int cube(int n)
{
    return n * n * n;
}