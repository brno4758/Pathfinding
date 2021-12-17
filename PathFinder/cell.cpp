#include "cell.h"

QRectF Cell::boundingRect() const
{
    return QRectF(x_+(x_*width_), y_+(y_*width_), width_, width_);
}

QPainterPath Cell::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

void Cell::paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget)
{
    Q_UNUSED(widget);
    Q_UNUSED(item);
    if(visited_)
        painter->setBrush(visited);
    else
        painter->setBrush(unvisited);
    painter->drawRect(x_+(x_*width_), y_+(y_*width_),width_,width_);
}

void Cell::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << x_ << "," << y_;
    emit cell_selected(*this);

}

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
    if( (y+1) < rows_ ) //Up
        v.push_back(&grid_[y+1][x]);
    if( (x+1) < cols_ ) //Right
        v.push_back(&grid_[y][x+1]);
    if( (y-1) >= 0 ) //Down
        v.push_back(&grid_[y-1][x]);
    if( (x-1) >= 0 ) //Left
        v.push_back(&grid_[y][x-1]);

    return v;
}

bool Grid::depth_first_search(Cell& source, Cell& dest)
{
    qDebug() << "searching on:" << source.get_x() << "," << source.get_y();
    source.set_visited(true);
    source.update();
    QApplication::processEvents();
    Sleep(500);
    if(source == dest)
        return true;

    bool flag = false;
    for(Cell*& i : get_neighbors(source))
    {
        if(i->get_visited())
            continue;
        flag = depth_first_search(*i, dest);
        if(flag)
            break;
    }

    return flag;
}

bool Grid::breadth_first_search(Cell& source, Cell& dest){
    std::queue<Cell*> q;
    q.push(source);

    while(!q.empty())
    {
        Cell* currCell = q.front();
        for(Cell*& i : get_neighbors(*currCell))
        {
            q.push(i);
        }
    }
}
