#include "graph.h"
#include <iostream>
#include "list.h"


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
        cout << "Graph is empty" << endl;
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

node* graph::getNode(char name)
{
    //Linear search, could be improved if we sort vertices by char name by...
    //...either initializing the vertices in a sorted order or sorting after initialization
    for(auto currNode : vertices)
        if(currNode->name == name)
            return currNode;

    return nullptr;
}

node* graph::dijkstras(char origin, char destination)
{
    node* start = getNode(origin);
    node* finish = getNode(destination);
    if(!start)
    {
        cout << "Origin node " << origin << " not found" << endl;
        return nullptr;
    };
    if(!finish)
    {
        cout << "Destination node " << destination << " not found" << endl;
        return nullptr;
    }
    start->originDistance = 0;
    start->prevNode = nullptr;

    int minDist = 0;

    DLL nodes;
    nodes.insertNode(start);

    //de-bugging prints
    cout << "BEGIN:" << endl;
    cout << "Starting node: " << start->name << endl;
    cout << "Current list: "; 
    nodes.printList();
    cout << endl;

    while(!(nodes.empty()))
    {
        node* currNode = nodes.findMinDistNode()->graphNode;
        if(currNode->visited){
            nodes.deleteNode(currNode->name);
            continue;
        }
            
        currNode->visited = true;

        for(auto neighbor : currNode->neighbors)
        {
            //if the neighbor is already visited, or the current originDistance of neighbor is less than new calculated distance
            //move on to the next neighbor
            if(neighbor.first->visited == true)
                continue;

            nodes.insertNode(neighbor.first);
            cout << "Inserted: " << neighbor.first->name << endl;
            cout << "Current list: ";
            nodes.printList();
            cout << endl;
            if(neighbor.first->originDistance < (neighbor.second + currNode->originDistance))
                continue;
            
            neighbor.first->originDistance = neighbor.second + currNode->originDistance;
            neighbor.first->prevNode = currNode;
        }
        nodes.deleteNode(currNode->name);
    }
    cout << "PATH:" << endl;
    node* crawler = getNode(destination);
    while(crawler != nullptr)
    {
        cout << crawler->name << "->";
        crawler = crawler->prevNode;
    }

    return nullptr;
}