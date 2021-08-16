#include "minHeap.h"
#include <iostream>



//Houstin we have a bug.
//Insert sequence 14 42 66 3 49 21 98 71 93 1 59 94 52 19 29
//Output sequence 1 3 14 19 21 42 49 29 52 59 66 71 93 94 98
MinHeap::MinHeap(int capacity):capacity(capacity),heap(new int[capacity]), currentSize(0)
{
}

MinHeap::~MinHeap()
{
    delete[] heap;
    heap = nullptr;
}

void MinHeap::push(int k)
{
    if(currentSize == capacity)
    {
        std::cout << "current size is at capacity" << std::endl;
        return;
    }
    heap[currentSize] = k;
    currentSize++;

    minHeapifyUp(currentSize-1);
}
int MinHeap::pop()
{
    swap(heap[0], heap[currentSize-1]);
    currentSize--;
    minHeapifyDown(0);
    return heap[currentSize];
}
void MinHeap::printHeap()
{
    for(auto i = 0; i < currentSize; i++)
    {
        int l = left(i);
        int r = right(i);
        std::cout << "Node: " << heap[i];
        if(l < currentSize)
            std::cout << " Left Child: " << heap[l];
        if(r < currentSize)
            std::cout << " Right Child: " << heap[r];
        std::cout << '\n';
    }
}
void MinHeap::minHeapifyUp(int index)
{
    if(index >= currentSize || index < 0)
    {
        std::cout << "Invalid index, exiting" << std::endl;
        exit(1);
    }
    if(currentSize == 1)
        return;

    int parentIndex = 0;
    while((parentIndex=parent(index)) >= 0 &&  heap[parentIndex] > heap[index])
    {
        swap(heap[parentIndex], heap[index]);
        index = parentIndex;
    }

    return;
}

//do a walkthrough to verify this is correct, current work is in blue scratch notebook
void MinHeap::minHeapifyDown(int index)
{
    if(index > currentSize || index < 0)
    {
        std::cout << "Invalid index, exiting" << std::endl;
        exit(1);
    }
    if(currentSize == 0)
        return;
    


    int minIndex = 0;
    while(minIndex != -1)
    {
        int l = left(index);
        int r = right(index);
        minIndex = -1;

        //find a better way to do this
        //What if I sum the bools and then use a switch statement
        if(l < currentSize && heap[index] > heap[l])
            minIndex = l;
        if(r < currentSize && heap[index] > heap[r])
            minIndex = r;
        if((l < currentSize && r < currentSize) && heap[l] < heap[r])
            minIndex = l;
        if(minIndex != -1)
        {
            swap(heap[index], heap[minIndex]);
            index = minIndex;
        }
    }
}

void MinHeap::swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

auto MinHeap::getSize()
{
    return currentSize;
}