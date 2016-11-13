#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QGraphicsView>
#include <QGraphicsScene>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void initView();
private:
    void initScene();

private:
    Ui::MainWindow *ui;
    QGraphicsView *m_ptrView;
    QGraphicsScene *m_ptrScene;

};

#endif // MAINWINDOW_H
