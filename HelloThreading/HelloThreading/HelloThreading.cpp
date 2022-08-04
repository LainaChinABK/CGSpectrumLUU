// HelloThreading.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>

int num1 = 0;
int num2 = 0;
bool done = false;

void HelloThread1()
{
    while (!done)
    {
        num1++;
        if (num1 > 1000)
        {
            num1 = 0;
        }
    }
}

void HelloThread2()
{
    while (!done)
    {
        num2++;
        if (num2 > 1000)
        {
            num2 = 0;
        }
    }
}

int main()
{
    std::cout << "Hello World!\n";

    char ch;
    std::thread Thread1(HelloThread1);
    std::thread Thread2(HelloThread2);

    while (!done)
    {
        std::cout << "Enter any key to display numbers or q to quit" << std::endl;
        std::cin >> ch;
        done = (tolower(ch) == 'q');
        std::cout << "num1 = " << num1 << std::endl;
        std::cout << "num2 = " << num2 << std::endl;
    }

    Thread1.join();
    Thread2.join();
}