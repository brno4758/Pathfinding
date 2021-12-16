#ifndef CELL_H
#define CELL_H
enum class cellType{Empty, Wall};

#include <QColor>
#include <QGraphicsItem>
#include <QtWidgets>
#include <QDebug>
class Cell : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    Cell() : type_(cellType::Empty), x_(0), y_(0) {};
    Cell(short x, short y) : type_(cellType::Empty), x_(x), y_(y) {};

    void set_x(short x) {x_ = x;}
    void set_y(short y) {y_ = y;}

    short get_x() const {return x_;}
    short get_y() const {return y_;}

    static short get_width() {return width_;}

    QRectF boundingRect() const override; //adds clickable area to the object of the ui
    QPainterPath shape() const override; //allows us to draw standard shapes
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override; //allows us to add color to object we are drawing

private:
    const static short width_ = 20;
    cellType type_;
    short x_;
    short y_;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};


class Grid
{
public:
    Grid(short rows, short cols);
    ~Grid();
    short get_num_rows() const {return rows_;}
    short get_num_cols() const {return cols_;}


    Cell* get_cell(short x, short y);
    Grid() = delete;
private:
    const short rows_;
    const short cols_;
    Cell** grid_;

};

#endif // CELL_H
