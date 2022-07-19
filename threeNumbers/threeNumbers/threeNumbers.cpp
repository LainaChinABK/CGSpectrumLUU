// threeNumbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
    // Get three numbers from user
    int a, b, c;

    cout << "First number: ";
    cin >> a;

    cout << "Second number: ";
    cin >> b;

    cout << "Third number: ";
    cin >> c;

    // Calculate sum
    int sum = a + b + c;

    // Calculate average
    float avg = sum / 3.f;

    // Print results
    cout << "Sum: " << sum << endl;
    cout << "Average: " << avg << endl;
}