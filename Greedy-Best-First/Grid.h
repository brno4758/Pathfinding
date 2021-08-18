#include <vector>
#include <utility>
class Grid
{
    public:
        Grid();
        ~Grid();
        std::vector<std::vector<std::pair<int,int>>> v;
        float euclidianDistance(std::pair<int,int> p1, std::pair<int,int> p2);
    private:

};