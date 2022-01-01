#include "graph.h"
#include <iostream>
using namespace std;

graph initialize();

//do more tests, but I think this is all working, move minHeapNode.cpp & minHeapNode.h back into /dijkstras before running
//set up make file
int main()
{
    graph* Graph = new graph;

    Graph->initialize();
    
    Graph->printNodes();
    Graph->printNeighborsDistances();

    
    //Graph->deleteGraph();
    //cout << Graph->vertices.empty();
    
    Graph->dijkstras('e', 'a');
    Graph->deleteGraph();
}
