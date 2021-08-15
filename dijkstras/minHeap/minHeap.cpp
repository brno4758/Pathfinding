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

    minHeapifyUp(currentSize);
}
int MinHeap::pop()
{
    swap(heap[0], heap[currentSize-1]);
    currentSize--;
    minHeapifyDown(currentSize-1);
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
    int parentIndex = 0;

    while((parentIndex=parent(index)) >= 0 &&  heap[parentIndex] > heap[index])
    {
        swap(heap[parentIndex], heap[index]);
        index = parentIndex;
    }
    
}

void MinHeap::minHeapifyDown(int index)
{
    if(index >= currentSize || index < 0)
    {
        std::cout << "Invalid index, exiting" << std::endl;
        exit(1);
    }
    int currIndex = index;
    int l = left(index);
    int r = right(index);
    int minIndex = 0;

    if(heap[index] > heap[l])
        minIndex = l;
    if(heap[index] > heap[r])
        minIndex = r;

}

void MinHeap::swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}