#include "SnakeControl.h"
#include "Food.h"
#include "Snake.h"
#include "QEvent"
#include "QKeyEvent"
#include <QDebug>

SnakeControl::SnakeControl(QGraphicsScene *scene, QObject *parent):
    QObject(parent),
    m_tmrAdvanceTimer(new QTimer),
    m_ptrScene(scene),
    m_ptrSnake(new Snake(QPoint(30,30)))
{
    connect(m_tmrAdvanceTimer, SIGNAL(timeout()), m_ptrScene, SLOT(advance()));
    m_tmrAdvanceTimer->setInterval(200);
    m_tmrAdvanceTimer->start(200);

    m_ptrFood = new Food(QPoint(0,0));
    m_ptrScene->addItem(m_ptrFood);
//    ptr_Snake = new Snake(QPoint(30,30));
    m_ptrScene->addItem(m_ptrSnake);
    m_ptrScene->installEventFilter(this);
    connect(m_ptrSnake, SIGNAL(signalSnakeMove()), this, SLOT(manageSnake()));
}

SnakeControl::~SnakeControl()
{
}

bool SnakeControl::eventFilter(QObject *object, QEvent *event)
{
    if(event->type() == QEvent::KeyRelease)
    {
        QKeyEvent *key = static_cast<QKeyEvent*>(event);
        switch (key->key())
        {
         case Qt::Key_Up:
            m_ptrSnake->setMoveDirection(Snake::MoveUp);
            break;
        case Qt::Key_Down:
            m_ptrSnake->setMoveDirection(Snake::MoveDown);
            break;
        case Qt::Key_Left:
            m_ptrSnake->setMoveDirection(Snake::MoveLeft);
            break;
        case Qt::Key_Right:
            m_ptrSnake->setMoveDirection(Snake::MoveRight);
            break;

        }
        return true;
    }
    else
    {
    }
        return QObject::eventFilter(object, event);
    }

void SnakeControl::manageSnake()
{
    QPointF snakePoint = m_ptrSnake->mapToScene(m_ptrSnake->boundingRect().topLeft());
    QRectF snakeRect(snakePoint.x(), snakePoint.y(), m_ptrSnake->boundingRect().width(), m_ptrSnake->boundingRect().height());

    if(m_ptrFood == NULL)
    {
        return;
    }
    QPointF foodPoint = m_ptrFood->mapToScene(m_ptrFood->boundingRect().topLeft());
    QRectF foodRect(foodPoint.x(), foodPoint.y(), m_ptrFood->boundingRect().width(), m_ptrFood->boundingRect().height());
    if(snakeRect.contains(foodRect))
    {
        qDebug()<<"snake eat food...";
        m_ptrSnake->eatFood();
        m_ptrScene->removeItem(m_ptrFood);
//        delete m_ptrFood;
//        m_ptrFood = NULL;

        int x, y;
        do {
            x = (int) (qrand() % 100) / 10;
            y = (int) (qrand() % 100) / 10;

            x *= 10;
            y *= 10;
        } while (m_ptrSnake->shape().contains(m_ptrSnake->mapFromScene(QPointF(x + 5, y + 5))));

        m_ptrFood->setPos(x,y);
        m_ptrScene->addItem(m_ptrFood);
    }
}
