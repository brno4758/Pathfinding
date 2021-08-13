#include <utility>
#include <vector>
#include <limits>

using namespace std;

const int int_max = 2147483647;

struct node{
    char name;
    int originDistance = int_max;
    char prevNode;
    vector<pair<node*,int>> neighbors;
};


class graph{
    

    public:
        void printNodes();
        void deleteGraph();
        void initialize();
        void printNeighbors();
        void printNeighborsDistances();

        vector<node*> vertices;
        node* origin;
};