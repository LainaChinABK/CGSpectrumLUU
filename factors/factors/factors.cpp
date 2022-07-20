// factors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void factors(int n);

int main()
{
    // initialize variable
    int n = 0;

    // get input from user
    do
    {
        cout << "Please enter a positive integer: ";
        cin >> n;

        if (cin.fail())
        {
            cout << "That's not a number!" << endl;
            cin.clear();
            cin.ignore(100, '\n');
        }

        else if (n > 0)
        {
            break;
        }
    } while (true);

    factors(n);
}

void factors(int n)
{
    // loop through factors of n
    for (int i = 1; i <= n; i++)
    {
        // check that i is a factor of n
        if (n % i == 0)
        {
            cout << i << " ";
        }
    }

    cout << endl;
}