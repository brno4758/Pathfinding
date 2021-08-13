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

    
    //Graph->deleteGraph();
    //cout << Graph->vertices.empty();
    
    
    Graph->deleteGraph();
}