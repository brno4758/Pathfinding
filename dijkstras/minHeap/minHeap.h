#pragma once

class MinHeap{
    public:
        MinHeap(int capacity);
        ~MinHeap();
        void push(int k);
        int pop();
        int peek() { return heap[0]; }
        void printHeap();
    private:
        int *heap;
        int capacity;
        int currentSize;
        int parent(int i) { return (i-1)/2; }
        int left(int i) { return (2*i+1); }
        int right(int i) { return (2*i+2); }
        void swap(int &x, int &y);
        void minHeapifyUp(int index);
        void minHeapifyDown(int index);
}  ;