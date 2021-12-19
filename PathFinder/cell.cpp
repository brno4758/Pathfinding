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

    switch(type_)
    {
    case(CellType::Wall):
        painter->setBrush(wallColor);
        break;
    case(CellType::Visited):
        painter->setBrush(visitedColor);
        break;
    case(CellType::Unvisited):
        painter->setBrush(unvisitedColor);
        break;
    default:
        painter->setBrush(unvisitedColor);
    }
    painter->drawRect(x_+(x_*width_), y_+(y_*width_),width_,width_);
}

void Cell::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->buttons() == Qt::RightButton)
    {
        set_cell_type(CellType::Wall);
        update();
    }
    else
        emit cell_selected(*this);
}

