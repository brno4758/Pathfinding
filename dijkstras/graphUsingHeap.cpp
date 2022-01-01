#include "graph.h"
#include <iostream>
#include "minHeapNode.h"


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

    //E neighbors: {(C,2), (D,3)}
    vertices[4]->neighbors.push_back(make_pair(vertices[2],2));
    vertices[4]->neighbors.push_back(make_pair(vertices[3],3));
}
void graph::deleteGraph()
{
    for(auto i : vertices)
    {
        delete i;
        i = nullptr;
    }

    vertices.clear();
}


void graph::printNodes()
{
    for(auto currNode : vertices)
    {
        std::cout << currNode->name << endl;
    }
}

void graph::printNeighbors()
{
    if(vertices.empty())
    {
        std::cout << "graph is empty" << endl;
        return;
    }

    for(auto i : vertices)
    {
        std::cout << i->name << " : ";
        for(auto j : i->neighbors)
            std::cout << j.first->name << " ";
        std::cout << endl;
    }
}

void graph::printNeighborsDistances()
{
    if(vertices.empty())
    {
        std::cout << "Graph is empty" << endl;
        return;
    }
    
    for(auto i : vertices)
    {
        std::cout << i->name << " : ";
        for(auto j : i->neighbors)
            std::cout << "(" << j.first->name << "," << j.second << ")";
        std::cout << endl;
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

//
//start with all nodes in the list, and then remove them as we go, visiting in sequence the node with the min distance from source
node* graph::dijkstras(char origin, char destination)
{
    node* start = nullptr;
    node* finish = nullptr;
    if(!(start=getNode(origin)))
    {
        std::cout << "Origin node " << origin << " not found" << endl;
        return nullptr;
    };
    if(!(finish=getNode(destination)))
    {
        std::cout << "Destination node " << destination << " not found" << endl;
        return nullptr;
    }
    start->originDistance = 0;
    start->prevNode = nullptr;

    MinHeap nodes(vertices.size());
    nodes.push(start);


    while(!(nodes.empty()))
    {
        node* currNode = nodes.pop();
        
        if(currNode->visited == true)
            continue;

        currNode->visited = true;

        for(auto neighbor : currNode->neighbors)
        {
            //if the neighbor is already visited, or the current originDistance of neighbor is less than new calculated distance
            //move on to the next neighbor
            if(neighbor.first->visited == true)
                continue;
            if(neighbor.first->originDistance < (neighbor.second + currNode->originDistance))
                continue;
            
            neighbor.first->originDistance = neighbor.second + currNode->originDistance;
            neighbor.first->prevNode = currNode;

            nodes.push(neighbor.first);
        }
    }
    std::cout << "PATH:" << endl;
    while(finish != nullptr)
    {
        std::cout << finish->name << "->";
        finish = finish->prevNode;
    }

    return nullptr;
}