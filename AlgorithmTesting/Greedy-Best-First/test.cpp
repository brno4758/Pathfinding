#include <vector>
#include <utility>
#include <iostream> 
using namespace std;

int main()
{
    vector<vector<pair<int,int>>> v;


    for(int y = 5; y >= 0; y--)
    {
        vector<pair<int,int>> row;
        for(int x = 0; x <= 5; x++)
        {
            row.push_back(make_pair(x,y));
            cout << '(' << x << ',' << y << ')';
        }
        v.push_back(row);
        cout << endl;
    }
}