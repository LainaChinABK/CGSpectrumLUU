// arrayMax.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <assert.h>
using namespace std;

void populate(int arr[], int n);
int getMax(int arr[], int n);

int main()
{
    const int n = 5;
    int arr[n];
    populate(arr, n);

    int max = getMax(arr, n);
    cout << "the biggest number in the array is " << max << endl;
}

void populate(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "index " << i << ": ";
        cin >> arr[i];
        assert(!cin.fail());
    }
}

int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}