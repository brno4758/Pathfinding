#include "minHeapNode.h"
#include <iostream>

MinHeap::MinHeap(int capacity):capacity(capacity),heap(new node*[capacity]), currentSize(0)
{
}

MinHeap::~MinHeap()
{
    delete[] heap;
    heap = nullptr;
}

void MinHeap::push(node* k)
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
node* MinHeap::pop()
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
        std::cout << "Node: " << heap[i]->name;
        if(l < currentSize)
            std::cout << " Left Child: " << heap[l]->name;
        if(r < currentSize)
            std::cout << " Right Child: " << heap[r]->name;
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
    while((parentIndex=parent(index)) >= 0 &&  heap[parentIndex]->originDistance > heap[index]->originDistance)
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

        leftLess = l < currentSize && heap[index]->originDistance > heap[l]->originDistance;
        rightLess = r < currentSize && heap[index]->originDistance > heap[r]->originDistance;

        if(leftLess && rightLess)
        {
            if(heap[r]->originDistance < heap[l]->originDistance)
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

void MinHeap::swap(node* &x, node* &y)
{
    node* temp = x;
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