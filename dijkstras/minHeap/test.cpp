#include <iostream>
#include "minHeap.h"
#include <random>

using namespace std;

//Houstin we have a bug.
//Insert sequence 14 42 66 3 49 21 98 71 93 1 59 94 52 19 29
//Output sequence 1 3 14 19 21 42 49 29 52 59 66 71 93 94 98

//Push function functions correctly for the above input sequence
int main()
{
    srand(time(NULL));

    MinHeap heap(15);

    int currNum = 0;
    while(currNum != -1)
    {
        cin >> currNum;
        heap.push(currNum);

        heap.printHeap();
        cout << "--------------------------" << "\n";
    }
}