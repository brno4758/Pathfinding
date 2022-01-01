#include <iostream>
#include <random>
#include "minHeapNode.h"

using namespace std;

int main()
{
    srand(time(NULL));
    MinHeap heap(50);

    for(int i = 0; i < 50; i++)
    {
        node* newNode = new node;
        newNode->originDistance = rand() % 100;
        heap.push(newNode);
    }

    for(int i = 0; i < 50; i++)
    {
        node* temp = heap.pop();
        cout << temp->originDistance << " ";
        delete temp;
    }
}