#ifndef SNAKECONTROL_H
#define SNAKECONTROL_H

#include <QTimer>
#include <QGraphicsScene>
#include "Snake.h"
#include "Food.h"

#include <QObject>

class SnakeControl:public QObject
{
    Q_OBJECT
public:
    SnakeControl(QGraphicsScene *scene, QObject *parent);
    ~SnakeControl();

public:
   bool eventFilter(QObject *object, QEvent * event);

public slots:
   void manageSnake();

private:
    QTimer *m_tmrAdvanceTimer;
    QGraphicsScene *m_ptrScene;\
    Food *m_ptrFood;
    Snake *m_ptrSnake;
};
#endif //
