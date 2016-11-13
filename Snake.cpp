#include "Snake.h"
#include <QPainter>
#include "Constant.h"
#include <QDebug>

Snake::Snake(QPoint point, QObject *parent):
//    QObject(parent),
    m_newPos(point)
  , m_iMove(0)
{
    m_eMoveDir = DonotMove;
}

QPainterPath Snake::shape() const
{
    QPainterPath path;
    path.setFillRule(Qt::WindingFill);

//    path.addRect(QRectF(m_newPos.x(),m_newPos.y() , RectSize,RectSize));
    path.addRect(QRectF(0,0,RectSize,RectSize));
    QList<QPoint>::const_iterator it;
    for(it = m_listSnakeBody.begin(); it != m_listSnakeBody.end(); it ++)
    {
        QPointF itemp = mapFromScene(QPoint(*it));
        path.addRect(itemp.x(), itemp.y(), RectSize,RectSize);
    }
    return path;
}

void Snake::advance(int phase)
{
    if(phase == 0)
    {
        return ;
    }
    if(m_iMove > 0)
    {
        m_listSnakeBody.push_front(m_newPos);
        switch(m_eMoveDir)
        {
        case MoveDown:
                    m_newPos.setY(m_newPos.y()  + RectSize);
                break;
        case MoveUp:
                    m_newPos.setY(m_newPos.y() - RectSize);
                break;
        case MoveLeft:
                    m_newPos.setX(m_newPos.x() - RectSize);
                break;
        case MoveRight:
                    m_newPos.setX(m_newPos.x() + RectSize);
                break;
        }
        m_iMove--;
    }
    else
    {
        m_listSnakeBody.push_front(m_newPos);
        if(!m_listSnakeBody.isEmpty())
        {
            m_listSnakeBody.pop_back();
        }
        switch(m_eMoveDir)
        {
        case MoveDown:
                    m_newPos.setY(m_newPos.y()  + RectSize);
                break;
        case MoveUp:
                    m_newPos.setY(m_newPos.y() - RectSize);
                break;
        case MoveLeft:
                    m_newPos.setX(m_newPos.x() - RectSize);
                break;
        case MoveRight:
                    m_newPos.setX(m_newPos.x() + RectSize);
                break;
        }
    }
    qDebug()<<"snake pos:"<<m_newPos.x() << m_newPos.y();
    setPos(m_newPos);
    emit signalSnakeMove();
}

QRectF Snake::boundingRect() const
{
    qreal minx = m_newPos.x();
    qreal miny = m_newPos.y();
    qreal maxx = m_newPos.x();
    qreal maxy = m_newPos.y();
    foreach(QPointF point, m_listSnakeBody)
    {
       minx = minx < point.x() ? minx : point.x();
       miny = miny < point.y() ? miny : point.y();
       maxx = maxx > point.x() ? maxx : point.x();
       maxy = maxy > point.y() ? maxy: point.y();
    }

//    return QRectF(minx, miny, maxx - minx, maxy - maxy);
//    return (QRectF(m_newPos.x(), m_newPos.y(), RectSize, RectSize));

    QPointF minPoint = mapFromScene(QPointF(minx, miny));
    QPointF maxPoint = mapFromScene(QPointF(maxx, maxy));

    return QRectF(minPoint.x(), minPoint.y(), maxPoint.x() - minPoint.x() + RectSize, maxPoint.y() - minPoint.y() + RectSize);

}

void Snake::paint(QPainter * painter, const QStyleOptionGraphicsItem * , QWidget * )
{
    painter->save();
    painter->fillPath(shape(), QBrush(Qt::yellow));
    painter->restore();
}

void Snake::setMoveDirection(MoveDirection direction)
{
    m_eMoveDir = direction;
}

void Snake::eatFood()
{
    m_iMove = 1;
}
