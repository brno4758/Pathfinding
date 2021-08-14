#pragma once
#include "graph.h"

struct listNode{
    node* graphNode = nullptr;
    listNode* next = nullptr;
    listNode* prev = nullptr;
};


class DLL{
    public:
        listNode* head = nullptr;
        listNode* tail = nullptr;
        listNode* findNode(char name);
        listNode* findMinDistNode();
        void insertNode(node* node);
        void deleteNode(char name);
        void deleteList();
        bool empty();
        void printList();
};