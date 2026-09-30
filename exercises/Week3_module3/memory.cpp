#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

void memoryLeak()
{
    // Large memory allocation
    int *leakyArray = new int[100000];
    for (int i = 0; i < 100000; ++i)
    {
        leakyArray[i] = i; // Simulate usage
    }
    // comment out the delete to see the memory leak!
    delete[] leakyArray;
}
