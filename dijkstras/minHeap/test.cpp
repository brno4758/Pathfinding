#include <iostream>
#include <random>
#include "minHeap.h"

using namespace std;

int main()
{
    int numElements = 100;
    int arr[numElements];
    int arr2[numElements];
    srand(time(NULL));
    for(int i = 0; i < numElements; i++)
    {
        arr[i] = rand() % 100;
    }
    MinHeap heap(numElements);
    for(auto i : arr)
    {
        cout << i << ", ";
        heap.push(i);   
    }
    cout << '\n';
    for(int i = 0; i < numElements; i++)
    {
        arr2[i] = heap.pop();
    }

    for(auto i : arr2)
        cout << i << ", ";
    cout << '\n';
}