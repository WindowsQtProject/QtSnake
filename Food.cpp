#include "Food.h"
#include <QPainter>
#include "Constant.h"


Food::Food()
{

}

Food::Food(QPointF point)
{
   setPos(point);
}

Food::~Food()
{

}

QPainterPath Food::shape()
{
    QPainterPath path;
    path.addEllipse(QPoint(RectSize/2, RectSize/2), Radius, Radius);
    return path;
}

QRectF Food::boundingRect() const
{
    return QRectF(0,0,RectSize,RectSize);
}

void Food::advance(int phase)
{
    QGraphicsItem::advance(phase);
}

void Food::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->save();
    painter->setRenderHint(QPainter::Antialiasing);
    painter->fillPath(shape(), Qt::red);  //fillPath() do not draw outline, drawPath() will draw outline.
    painter->restore();
}
