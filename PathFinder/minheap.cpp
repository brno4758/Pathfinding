#include "minheap.h"

MinHeap::~MinHeap()
{
    delete[] heap_;
}

Cell* MinHeap::peek()
{
    return heap_[0];
}


Cell* MinHeap::pop()
{
    if(size_ == 0)
        return nullptr;
    swap(0, size_-1);
    size_--;
    minHeapifyDown(0);
    return heap_[size_];
}

bool MinHeap::insert(Cell* element)
{
    if(size_ == capacity_)
        doubleSize();

    heap_[size_] = element;
    minHeapifyUp(size_);
    size_++;
    return true;
}

void MinHeap::minHeapifyUp(short index)
{
    while(parent(index) >= 0 && *heap_[index] < *heap_[parent(index)])
    {
        swap(index, parent(index));
        index = parent(index);
    }
}


void MinHeap::minHeapifyDown(short index)
{
    short smallest = index;
    if(leftChild(index) < size_ && *heap_[leftChild(index)] < *heap_[smallest])
        smallest = leftChild(index);
    if(rightChild(index) < size_ && *heap_[rightChild(index)] < *heap_[smallest])
        smallest = rightChild(index);
    if(smallest != index)
    {
        swap(smallest, index);
        minHeapifyDown(smallest);
    }
}

void MinHeap::swap(short indexa, short indexb)
{
    Cell* temp = heap_[indexa];
    heap_[indexa] = heap_[indexb];
    heap_[indexb] = temp;
}

void MinHeap::doubleSize()
{
    qDebug() << "size is :" << size_;
    Cell** newArr = new Cell*[capacity_*2];

    for(int i = 0; i < capacity_; i++)
    {
        newArr[i] = heap_[i];
    }
    capacity_ *= 2;
    delete[] heap_;
    heap_ = newArr;
}
