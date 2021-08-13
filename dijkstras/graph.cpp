#include "graph.h"
#include <iostream>


void graph::initialize()
{
    for(char i = 'a'; i <= 'e'; i++)
    {
        node* newNode = new node;
        newNode->name = i;
        vertices.push_back(newNode);
    }
    //A neighbors: {(B,5),(C,7),(D,5)}
    vertices[0]->neighbors.push_back(make_pair(vertices[1],5));
    vertices[0]->neighbors.push_back(make_pair(vertices[2],7));
    vertices[0]->neighbors.push_back(make_pair(vertices[3],5));

    //B neighbors: {(A,5),(C,5)}
    vertices[1]->neighbors.push_back(make_pair(vertices[0],5));
    vertices[1]->neighbors.push_back(make_pair(vertices[2],5));

    //C neighbors: {(A,7),(D,5), (B,5), (E,5)}
    vertices[2]->neighbors.push_back(make_pair(vertices[0],7));
    vertices[2]->neighbors.push_back(make_pair(vertices[3],5));
    vertices[2]->neighbors.push_back(make_pair(vertices[1],5));
    vertices[2]->neighbors.push_back(make_pair(vertices[4],5));

    //D neighbors: {(A,5),(C,5)}
    vertices[3]->neighbors.push_back(make_pair(vertices[0],5));
    vertices[3]->neighbors.push_back(make_pair(vertices[2],5));

    //E neighbors: {(C,5)}
    vertices[4]->neighbors.push_back(make_pair(vertices[2],5));
}
void graph::deleteGraph()
{
    for(auto i : vertices)
    {
        delete i;
    }

    vertices.clear();
}


void graph::printNodes()
{
    for(auto currNode : vertices)
    {
        cout << currNode->name << endl;
    }
}

void graph::printNeighbors()
{
    if(vertices.empty())
    {
        cout << "graph is empty" << endl;
        return;
    }

    for(auto i : vertices)
    {
        cout << i->name << " : ";
        for(auto j : i->neighbors)
            cout << j.first->name << " ";
        cout << endl;
    }
}

void graph::printNeighborsDistances()
{
    if(vertices.empty())
    {
        cout << "graph is empty" << endl;
        return;
    }
    
    for(auto i : vertices)
    {
        cout << i->name << " : ";
    for(auto j : i->neighbors)
         cout << "(" << j.first->name << "," << j.second << ")";
        cout << endl;
    }
}