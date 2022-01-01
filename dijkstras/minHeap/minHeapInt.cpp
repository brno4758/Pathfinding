#include "minHeapInt.h"
#include <iostream>

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

//Find better way to evaluate the current situation, i.e. is left less or right less or both
void MinHeap::minHeapifyDown(int index)
{
    if(index > currentSize || index < 0)
    {
        std::cout << "Invalid index, exiting" << std::endl;
        exit(1);
    }
    if(currentSize == 0)
        return;
    
    bool leftLess = true;
    bool rightLess = true;
    while(leftLess || rightLess)
    {
        int l = left(index);
        int r = right(index);

        leftLess = l < currentSize && heap[index] > heap[l];
        rightLess = r < currentSize && heap[index] > heap[r];

        if(leftLess && rightLess)
        {
            if(heap[r] < heap[l])
            {
                swap(heap[index], heap[r]);
                index = r;
            }
            else
            {
                swap(heap[index], heap[l]);
                index = l;
            }
        }
        else if(leftLess)
        {
            swap(heap[index], heap[l]);
            index = l;
        }
        else if(rightLess)
        {
            swap(heap[index], heap[r]);
            index = r;
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

bool MinHeap::empty()
{
    return currentSize == 0;
}