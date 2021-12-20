#ifndef MINHEAP_H
#define MINHEAP_H

#define distanceUnit 1
#include "cell.h"

class MinHeap
{
public:
    MinHeap() : heap_(new Cell*[50]), size_(0), capacity_(50) {};
    ~MinHeap();
    Cell* peek();
    Cell* pop();
    bool insert(Cell* element);
    bool empty() {return size_ == 0;}
    void minHeapifyUp(short index);
    void minHeapifyDown(short index);
    short leftChild(short index) {return 2*index + 1;}
    short rightChild(short index) {return 2*index + 2;}
    short parent(short index) {return (index-1)/2;} //https://cs.stackexchange.com/questions/130167/why-does-the-formula-floori-1-2-find-the-parent-node-in-a-binary-heap
    void swap(short indexa, short indexb);
private:
    void doubleSize();
    Cell** heap_;
    int size_;
    int capacity_;

};

#endif // MINHEAP_H
