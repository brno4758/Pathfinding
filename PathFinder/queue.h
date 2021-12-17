#ifndef QUEUE_H
#define QUEUE_H

#include "cell.h"



class Queue
{
public:
    Queue();
    Queue(Cell& c) : head_(&c){};
    void insert(Cell& c);
    void pop();



private:
    Cell* head_;

};

#endif // QUEUE_H
