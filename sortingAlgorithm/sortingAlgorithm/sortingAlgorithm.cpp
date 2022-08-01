// sortingAlgorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <chrono>
#include <iostream>

// define array sizes
#define SMALL 10
#define MEDIUM 100
#define LARGE 1000

// function declarations
void fillArray(int arr[], int size);
uint32_t getNanos();
void selectionSort(int arr[], int size);

int main()
{
    // seed random generator
    srand(time(nullptr));

    // create and fill datasets
    int smallData[SMALL];
    fillArray(smallData, SMALL);
    //for (int i = 0; i < SMALL; ++i)
    //{
    //    std::cout << smallData[i] << std::endl;
    //}
    //std::cout << std::endl;

    int mediumData[MEDIUM];
    fillArray(mediumData, MEDIUM);
    //for (int i = 0; i < SMALL; ++i)
    //{
    //    std::cout << mediumData[i] << std::endl;
    //}
    //std::cout << std::endl;

    int largeData[LARGE];
    fillArray(largeData, LARGE);
    //for (int i = 0; i < SMALL; ++i)
    //{
    //    std::cout << largeData[i] << std::endl;
    //}
    //std::cout << std::endl;

    // sort arrays
    uint32_t start = getNanos();
    selectionSort(smallData, SMALL);
    uint32_t end = getNanos();
    std::cout << "Selection sort for array with " << SMALL << " elements: " << end - start << "ns\n\n";
    //for (int i = 0; i < SMALL; ++i)
    //{
    //    std::cout << smallData[i] << std::endl;
    //}
    //std::cout << std::endl;

    start = getNanos();
    selectionSort(mediumData, MEDIUM);
    end = getNanos();
    std::cout << "Selection sort for array with " << MEDIUM << " elements: " << end - start << "ns\n\n";
    //for (int i = 0; i < SMALL; ++i)
    //{
    //    std::cout << mediumData[i] << std::endl;
    //}
    //std::cout << std::endl;

    start = getNanos();
    selectionSort(largeData, LARGE);
    end = getNanos();
    std::cout << "Selection sort for array with " << LARGE << " elements: " << end - start << "ns\n\n";
    //for (int i = 0; i < SMALL; ++i)
    //{
    //    std::cout << largeData[i] << std::endl;
    //}
    //std::cout << std::endl;
}

void fillArray(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        // populate array with random numbers between 1 and 500
        arr[i] = rand() % 500 + 1;
    }
}

// copied function from CGS vid
uint32_t getNanos()
{
    using namespace std::chrono;
    return static_cast<uint32_t>(duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count());
}

void selectionSort(int arr[], int size)
{
    // initialize variable to keep track of smallest element in array
    int minIndex = 0;

    // iterate through array
    for (int i = 0; i < size; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            if (arr[minIndex] > arr[j])
            {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}