#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include "Food.h"
#include "Snake.h"
#include "SnakeControl.h"
#include "Constant.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
  , m_ptrView(new QGraphicsView(this))
  , m_ptrScene(new QGraphicsScene(this))
{
    ui->setupUi(this);
    setGeometry(100,100,800,800);
    setCentralWidget(m_ptrView);
    initScene();
    m_ptrView->setScene(m_ptrScene);

//    Food* food = new Food(QPoint(0,0));
//    m_ptrScene->addItem(food);
//    Snake * snake = new Snake(QPoint(30,30));
//    m_ptrScene->addItem(snake);
    SnakeControl *sc = new SnakeControl(m_ptrScene, this);

    //    m_ptrView->setGeometry(0,0,800,800);
    QTimer::singleShot(0, this, SLOT(initView()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initView()
{
    m_ptrView->fitInView(m_ptrScene->sceneRect());
}

void MainWindow::initScene()
{
    m_ptrScene->setSceneRect(-100, -100, 200,200);
    QPixmap pic(RectSize,RectSize);
    QPainter painter(&pic);
    painter.setBrush(QBrush(Qt::gray));
    painter.drawRect(QRect(0,0,RectSize,RectSize));
    m_ptrScene->setBackgroundBrush(QBrush(pic));
}
