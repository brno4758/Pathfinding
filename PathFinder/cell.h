#ifndef CELL_H
#define CELL_H
enum class CellType{Visited, Unvisited, Wall, Path, Source, Destination};

#include <QColor>
#include <QGraphicsItem>
#include <QtWidgets>
#include <QDebug>
#include <vector>
#include <queue> //WRITE YOUR OWN IMPLEMENTATION LAZY!

const QColor wallColor(0,0,0);
const QColor visitedColor(255,0,0);
const QColor unvisitedColor(255,255,255);
const QColor pathColor(0,255,0);
const QColor sourceColor(0,0,255);
const QColor destColor(0,0,255);

class Cell : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    Cell() : type_(CellType::Unvisited), x_(0), y_(0), distanceSource_(SHRT_MAX), prev_(nullptr) {};
    Cell(short x, short y) : type_(CellType::Unvisited), x_(x), y_(y), distanceSource_(SHRT_MAX), prev_(nullptr) {};

    void set_x(short x) {x_ = x;}
    void set_y(short y) {y_ = y;}
    void set_cell_type(CellType type) {type_ = type;}
    void set_distance(short dist) {distanceSource_ = dist;}
    void set_prev(Cell* prev) {prev_ = prev;}
    void set_dest_distance(short dist) {distanceDest_ = dist;}

    short get_x() const {return x_;}
    short get_y() const {return y_;}
    CellType get_cell_type() const {return type_;}
    static short get_width() {return width_;}
    short get_distance() const {return distanceSource_;}
    Cell* get_prev() const {return prev_;}
    short get_dest_distance() const {return distanceDest_;}

    QRectF boundingRect() const override; //adds clickable area to the object of the ui
    QPainterPath shape() const override; //allows us to draw standard shapes
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override; //allows us to add color to object we are drawing
    bool operator==(const Cell& c) const {return x_ == c.x_ && y_ == c.y_;}
    bool operator()(const Cell& c1, const Cell& c2) const {return c1.distanceSource_ < c2.distanceSource_;}
    bool operator<(const Cell& c) const {return distanceSource_ < c.distanceSource_;}

private:
    const static short width_ = 20;
    CellType type_;
    short x_;
    short y_;
    short distanceSource_;
    short distanceDest_;
    Cell* prev_;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

signals:
    void cell_selected(Cell& c);
};

class dijkstraComparator {
public:
    bool operator()(const Cell* a, const Cell* b)
    {
        return (a->get_distance() > b->get_distance());
    }
};


class aStarComparator {
public:
    bool operator()(const Cell* a , const Cell* b)
    {
        return(a->get_distance() + a->get_dest_distance() > b->get_distance() + b->get_dest_distance());
    }
};

#endif // CELL_H
