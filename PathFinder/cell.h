#ifndef CELL_H
#define CELL_H
enum class CellType{Visited, Unvisited, Wall, Path};

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

class Cell : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    Cell() : type_(CellType::Unvisited), x_(0), y_(0), distance_(SHRT_MAX), prev_(nullptr), inQueue_(false) {};
    Cell(short x, short y) : type_(CellType::Unvisited), x_(x), y_(y), distance_(SHRT_MAX), prev_(nullptr), inQueue_(false) {};

    void set_x(short x) {x_ = x;}
    void set_y(short y) {y_ = y;}
    void set_cell_type(CellType type) {type_ = type;}
    void set_distance(short dist) {distance_ = dist;}
    void set_prev(Cell* prev) {prev_ = prev;}
    void set_enqueued(bool flag) {enqueued_ = flag;}

    short get_x() const {return x_;}
    short get_y() const {return y_;}
    CellType get_cell_type() const {return type_;}
    static short get_width() {return width_;}
    short get_distance() const {return distance_;}
    Cell* get_prev() const {return prev_;}
    bool get_enqueued() const {return enqueued_;}

    QRectF boundingRect() const override; //adds clickable area to the object of the ui
    QPainterPath shape() const override; //allows us to draw standard shapes
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override; //allows us to add color to object we are drawing
    bool operator==(const Cell& c) const {return x_ == c.x_ && y_ == c.y_;}
    bool operator<(const Cell& c) const {return distance_ < c.distance_;}

private:
    const static short width_ = 20;
    CellType type_;
    short x_;
    short y_;
    short distance_;
    Cell* prev_;
    bool enqueued_;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

signals:
    void cell_selected(Cell& c);
};

#endif // CELL_H
