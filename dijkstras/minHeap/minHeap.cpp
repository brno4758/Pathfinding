#include "minHeap.h"
#include <iostream>

MinHeap::MinHeap(int capacity):capacity(capacity)
{
    heap = new int[capacity];
}

MinHeap::~MinHeap()
{
    delete[] heap;
    heap = nullptr;
}

void MinHeap::push(int k)
{
    if(currentSize = capacity)
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

}
void MinHeap::minHeapifyUp(int index)
{
    if(index >= currentSize || index < 0)
    {
        std::cout << "Invalid index, exiting" << std::endl;
        exit(1);
    }
    if(currentSize == 1)
    {
        std::cout << "1 element in heap, no need to repair" << std::endl;
        return;
    }

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
    {
        std::cout << "Heap is empty, no need to fix" << std::endl;
        return;
    }


    int minIndex = 0;
    while(minIndex != -1)
    {
        int l = left(index);
        int r = right(index);
        minIndex = -1;

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