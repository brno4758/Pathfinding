#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    while(!q.empty())
    {
        int a = q.front();
        cout << a << endl;
        q.pop();

        if(a == 2)
            q.push(5);
    }


}