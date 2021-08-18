#pragma once
#include "graph.h"
class MinHeap{
    public:
        MinHeap(int capacity);
        ~MinHeap();
        void push(node* k);
        node* pop();
        node* peek() { return heap[0]; }
        void printHeap();
        auto getSize();
        bool empty();
    private:
        node* *heap;
        int capacity;
        int currentSize;
        int parent(int i) { return (i-1)/2; }
        int left(int i) { return (2*i+1); }
        int right(int i) { return (2*i+2); }
        void swap(node* &x, node* &y);
        void minHeapifyUp(int index);
        void minHeapifyDown(int index);
}  ;