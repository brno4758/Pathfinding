#include "graph.h"
#include <iostream>
using namespace std;

graph initialize();

int main()
{
    graph* Graph = new graph;

    Graph->initialize();
    
    //Graph->printNodes();
    //Graph->printNeighborsDistances();

    Graph->origin = Graph->vertices[0];
    Graph->origin->originDistance = 0;

    vector<node*> visited;
    vector<node*> unvisited = Graph->vertices;

    for(auto i : unvisited)
    {
        cout << i->name << " : ";
        for(auto j : i->neighbors)
            cout << j.first->name;
        cout << endl;
    }    
    Graph->deleteGraph();
    cout << Graph->vertices.empty();
}