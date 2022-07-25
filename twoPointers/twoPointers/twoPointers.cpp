// twoPointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    // initialize variables
    int a = 0;
    int b = 0;

    // get input from user
    std::cout << "Please pick two integers" << std::endl;
    std::cin >> a >> b;

    // assign values to pointers
    int* ptrA = &a;
    int* ptrB = &b;

    // print values using pointers
    std::cout << "*ptrA: " << *ptrA << std::endl;
    std::cout << "*ptrB: " << *ptrB << std::endl;
}