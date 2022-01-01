#include "Grid.h"
#include <math.h>


float euclidianDistance(std::pair<int,int> p1, std::pair<int,int> p2)
{
    //Might want to assign the subtractions to a variable and then use that instead
    return sqrt(((p2.first-p1.first)*(p2.first - p1.first)) + ((p2.second-p1.second)*(p2.second-p1.second)));
}