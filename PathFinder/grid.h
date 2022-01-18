#ifndef GRID_H
#define GRID_H

#include "cell.h"
#include <queue>
#define distanceUnit 1

class Grid
{
public:
    Grid(short rows, short cols);
    ~Grid();
    short get_num_rows() const {return rows_;}
    short get_num_cols() const {return cols_;}
    Cell* get_cell(short x, short y);
    std::vector<Cell*> get_neighbors(Cell& c) const;


    bool depth_first_search(Cell& source, Cell& dest);
    bool breadth_first_search(Cell& source, Cell& dest);
    bool dijkstra(Cell& source, Cell& dest);
    bool Astar(Cell& source, Cell& dest);
    bool greedy(Cell& source, Cell& dest);

    Grid() = delete;
private:
    void set_heuristic(Cell& dest);
    const short rows_;
    const short cols_;
    Cell** grid_;
};
#endif // GRID_H
