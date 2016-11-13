#ifndef SNAKE_H
#define SNAKE_H

#include <QGraphicsItem>
#include <QList>
#include <QObject>

class Snake:public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    enum MoveDirection{
        DonotMove,
        MoveRight,
        MoveLeft,
        MoveUp,
        MoveDown,
    };
    Snake(QPoint point, QObject *parent=0);
    QPainterPath shape() const;
    QRectF boundingRect() const;
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * , QWidget * );

    void setMoveDirection(MoveDirection direction);
    void eatFood();
protected:
    virtual void advance(int phase);

signals:
  void signalSnakeMove();

private:
    QPoint m_newPos;
    QList<QPoint> m_listSnakeBody;
    MoveDirection m_eMoveDir;
    int m_iMove;
};
#endif //SNAKE_H
