#ifndef GRID_H
#define GRID_H

#include "cell.h"
#include "minheap.h"
#include <queue>

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
    bool dijkstras(Cell& Source, Cell& dest);
    bool Astar(Cell& Source, Cell& dest);

    Grid() = delete;
private:
    const short rows_;
    const short cols_;
    Cell** grid_;
};
#endif // GRID_H
