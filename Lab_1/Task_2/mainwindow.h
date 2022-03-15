#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <triangle.h>
#include <rectangle.h>
#include <shape.h>
#include <circle.h>
#include <romb.h>
#include <square.h>
#include <hexagon.h>
#include <fivestar.h>
#include <sixstar.h>
#include <eightstar.h>
#include <parallelogram.h>
#include <QMouseEvent>
#include "paintScene.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
     void EnabledActions(bool turn);

private slots:
    void onCleanClicked();
    void onInfoClicked();
    void onCircleClicked();
    void onEightStarClicked();
    void onMyFigureClicked();
    void onTriangleClicked();
    void onSquareClicked();
    void onSixStarClicked();
    void onRombClicked();
    void onRectangleClicked();
    void onParallelogramClicked();
    void onHexagonClicked();
    void onFiveStarClicked();
    void onDecreaseClicked();
    void onDownClicked();
    void onIncreaseClicked();
    void onLeftClicked();
    void onLeftTurnClicked();
    void onRightClicked();
    void onRightTurnClicked();
    void onUpClicked();
    void size_slot();
    void move_up_slot();
    void move_down_slot();
    void move_left_slot();
    void move_right_slot();
    void rotate_slot();
    void disconnecnTimers();
private:
    Ui::MainWindow *ui;
    paintScene *addscene;
    QGraphicsScene *scene;
    QTimer *time;
    Shape *universal = nullptr;
    QPointF PreviousPoint;
    QPointF FirstPoint;
    bool RightClicked = false;
    bool CanveMod = false;
    bool FirstP = false;

//    void mousePressEvent(QGraphicsSceneMouseEvent * event);
//    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};
#endif // MAINWINDOW_H
