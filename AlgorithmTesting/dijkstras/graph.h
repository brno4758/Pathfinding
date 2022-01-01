#pragma once
#include <utility>
#include <vector>

using namespace std;

//max 32-bit signed integer value
const int int_max = 2147483647;

struct node{
    node* prevNode = nullptr;
    vector<pair<node*,int>> neighbors;
    int originDistance = int_max;
    char name;
    bool visited = false;
};


class graph{
    

    public:
        void printNodes();
        void deleteGraph();
        void initialize();
        void printNeighbors();
        void printNeighborsDistances();
        node* dijkstras(char source, char destination);
        node* getNode(char name);
        void printPath();

        vector<node*> vertices;
};