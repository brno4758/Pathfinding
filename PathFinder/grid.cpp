#include "grid.h"

Grid::Grid(short rows, short cols) : rows_(rows), cols_(cols), grid_(new Cell*[rows_])
{
    for(short i = 0; i < rows_; i++)
    {
        grid_[i] = new Cell[cols_];
    }

    for(short i = 0; i < rows_; i++)
        for(short j = 0; j < cols_; j++)
        {
            grid_[i][j].set_x(j);
            grid_[i][j].set_y(i);
        }
}

Grid::~Grid()
{
    for(short i = 0; i < rows_; i++)
        delete grid_[i];
    delete[] grid_;
}

Cell* Grid::get_cell(short x, short y)
{
    if(x >= cols_ || y >= rows_ || x < 0 || y < 0) //Make sure we dont go out of bounds
    {
        QMessageBox error;
        error.setText("Attempted to get out of bounds cell. Exiting application");
        error.exec();
        exit(1);
    }
    return &grid_[y][x];
}

std::vector<Cell*> Grid::get_neighbors(Cell& c) const
{
    short x = c.get_x();
    short y = c.get_y();
    std::vector<Cell*> v;
    if( (y+1) < rows_ ) //Down
        v.push_back(&grid_[y+1][x]);
    if( (x+1) < cols_ ) //Right
        v.push_back(&grid_[y][x+1]);
    if( (y-1) >= 0 ) //Up
        v.push_back(&grid_[y-1][x]);
    if( (x-1) >= 0 ) //Left
        v.push_back(&grid_[y][x-1]);

    return v;
}

bool Grid::depth_first_search(Cell& source, Cell& dest)
{
    source.set_cell_type(CellType::Visited);
    source.update();
    QApplication::processEvents();
    Sleep(50);
    if(source == dest)
        return true;

    bool flag = false;
    for(Cell*& i : get_neighbors(source))
    {
        if(i->get_cell_type() == CellType::Visited || i->get_cell_type() == CellType::Wall)
            continue;
        i->set_prev(&source);
        flag = depth_first_search(*i, dest);
        if(flag)
            break;
    }
    return flag;
}

bool Grid::breadth_first_search(Cell& source, Cell& dest)
{
    std::queue<Cell*> q;
    q.push(&source);

    while(!q.empty())
    {
        Cell* currCell = q.front();
        q.pop();

        currCell->set_cell_type(CellType::Visited);
        currCell->update();
        QApplication::processEvents();
        Sleep(50);
        if(*currCell == dest)
            return true;

        for(Cell*& i : get_neighbors(*currCell))
        {
            if(i->get_cell_type() == CellType::Visited || i->get_cell_type() == CellType::Wall)
                continue;
            i->set_cell_type(CellType::Visited);
            q.push(i);
        }
    }
    return false;
}

bool Grid::dijkstras(Cell& source, Cell& dest)
{
    //Could represent inQueue_ as an array instead of a bool carried around by each cell
    //If this ends up being only algo that uses inQueue_, switch to the array of bools

    //Maybe I can just do one big sweep of all cells, calculating their distance from source and pushing them onto the heap, then uusing that to traverse

    Cell* currCell = nullptr;
    MinHeap heap;
    heap.insert(&source);
    source.set_distance(0);
    source.set_prev(currCell);
    while(!heap.empty())
    {
        Sleep(25);
        currCell = heap.pop();
        currCell->set_cell_type(CellType::Visited);
        currCell->update();
        QApplication::processEvents();
        qDebug() << "My distance from source is: " << currCell->get_distance();
        for(Cell*& i : get_neighbors(*currCell))
        {
            if(i->get_cell_type() == CellType::Visited || i->get_cell_type() == CellType::Wall || i->get_enqueued() || i->get_distance() < currCell->get_distance() + distanceUnit)
                continue;
            i->set_enqueued(true);
            i->set_distance(currCell->get_distance() + distanceUnit);
            i->set_prev(currCell);
            heap.insert(i);
            if(*i == dest)
                return true;
        }
    }
    return false;
}
