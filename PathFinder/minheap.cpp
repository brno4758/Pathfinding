#include "minheap.h"
//MinHeap() : heap_(new Cell[50]), size_(0), capacity_(0) {};

Cell* MinHeap::peek()
{
    return heap_[0];
}


Cell* MinHeap::pop()
{
    swap(0, size_-1);
    minHeapifyDown(0);
    size_--;
}

bool MinHeap::insert(Cell* element)
{
    if(size_ == capacity_)
        return false;

    heap_[size_] = element;
    size_++;
    return true;
}

void MinHeap::minHeapifyUp(short index)
{
    while(parent(index) >= 0 && heap_[index] > heap_[parent(index)])
    {
        swap(index, parent(index));
    }
}


void MinHeap::minHeapifyDown(short index)
{
    while(parent(index) >= 0 && heap_[index] > heap_[parent(index)])
    {
      swap(index, parent(index));
    }
}

void MinHeap::swap(short indexa, short indexb)
{
    Cell* temp = heap_[indexa];
    heap_[indexa] = heap_[indexb];
    heap_[indexb] = temp;
}
