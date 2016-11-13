#ifndef FOOD_H
#define FOOD_H
#include <QGraphicsItem>

class Food:public QGraphicsItem
{
public:
    Food();
     explicit Food(QPointF point);
    ~Food();

    virtual QPainterPath shape();
    virtual QRectF boundingRect() const;
    virtual void advance(int phase);
    virtual void	paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0);
};
#endif //FOOD_H
