#pragma once
#include "graph.h"

struct listNode{
    node* graphNode = nullptr;
    listNode* next = nullptr;
    listNode* prev = nullptr;
};


class DLL{
    public:
        DLL();
        ~DLL();
        listNode* head;
        listNode* tail;
        listNode* findNode(char name);
        listNode* findMinDistNode();
        void insertNode(node* node);
        void deleteNode(char name);
        bool empty();
        void printList();
};