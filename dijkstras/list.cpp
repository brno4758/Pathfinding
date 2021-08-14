#include "list.h"
#include <iostream>

listNode* DLL::findNode(char name)
{
    listNode* crawler = head;
    while(crawler != nullptr && crawler->graphNode->name != name)
    {
        crawler = crawler->next;
    }

    if(!crawler)
    {
        std::cout << "Node not found" << std::endl;
        return nullptr;
    }
    return crawler;
}

listNode* DLL::findMinDistNode()
{
    int minDist = int_max;

    listNode* crawler = head;
    listNode* currMin = nullptr;

    while(crawler)
    {
        if(crawler->graphNode->originDistance < minDist)
            currMin = crawler;
        crawler = crawler->next;
    }
    return currMin;
}

void DLL::insertNode(node* node)
{
    listNode* newNode = new listNode;
    newNode->graphNode = node;

    if(!head){
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail->next->prev = tail;
    tail = newNode;
}

void DLL::deleteNode(char name)
{
    cout << "Deleting: " << name << endl;
    listNode* currNode = head;
    if(head->graphNode->name == name)
    {
        if(head->next == nullptr)
        {
            delete head;
            head = nullptr;
            cout << "Current list: ";
            printList();
            cout << endl;

            return;
        }    
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
        cout << "Current list: ";
        printList();
        cout << endl;
        return;
    }
    if(tail->graphNode->name == name)
    {
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
        cout << "Current list: ";
        printList();
        cout << endl;
        return;
    }

    while(currNode != nullptr && currNode->graphNode->name != name)
        currNode = currNode->next;
    
    if(currNode == nullptr)
    {
        cout << "Node not found" << endl;
        return;
    }
    currNode->prev->next = currNode->next;
    currNode->next->prev = currNode->prev;
    delete currNode;
    currNode = nullptr;
    cout << "Current list: ";
    printList();
    cout << endl;
    return;
}

void DLL::deleteList()
{
    listNode* crawler = head;
    while(head)
    {
        crawler = head;
        head = head->next;
        delete crawler;
    }
}

bool DLL::empty()
{
    return head==nullptr;
}

void DLL::printList()
{
    listNode* crawler = head;
    while(crawler)
    {
        cout << crawler->graphNode->name << "->";
        crawler = crawler->next;
    }
    cout << "null" << endl;
    return;
}