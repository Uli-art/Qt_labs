#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "infoaboutfigure.h"
//#import QtQuick 2.5
#include <QMouseEvent>
#include <QPainter>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    addscene = new paintScene();
    time = new QTimer();
    EnabledActions(false);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene->setSceneRect(-250,-250,500,500);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onCleanClicked(){
    scene->removeItem(universal);
    scene->clear();
    addscene->clear();
    this->EnabledActions(false);
}

void MainWindow::onInfoClicked(){
    InfoAboutFigure* infoWindow = new InfoAboutFigure(this);
    infoWindow->setInfo(universal->perimetr(), universal->square(), universal->getCenter());
    infoWindow->show();
}

void MainWindow::onCircleClicked(){
    ui->graphicsView->setScene(scene);
    scene->removeItem(universal);
    universal = new Circle;
    this->EnabledActions(true);
    scene->addItem(universal);
    universal->setPos(0,0);
}

void MainWindow::onEightStarClicked(){
    ui->graphicsView->setScene(scene);
    if (universal != nullptr){
        scene->removeItem(universal);
    };
    universal = new EightStar;
    this->EnabledActions(true);
    scene->addItem(universal);
    universal->setPos(0,0);
}

void MainWindow::onMyFigureClicked(){

    scene->removeItem(universal);

        ui->graphicsView->setScene(addscene);
        ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        this->EnabledActions(false);
}

void MainWindow::onTriangleClicked(){
    ui->graphicsView->setScene(scene);
    scene->removeItem(universal);
    universal = new Triangle;
    this->EnabledActions(true);
    scene->addItem(universal);
    universal->setPos(0,0);
}

void MainWindow::onSquareClicked(){
    ui->graphicsView->setScene(scene);
    scene->removeItem(universal);
    universal = new Square;
    this->EnabledActions(true);
    scene->addItem(universal);
    universal->setPos(0,0);
}

void MainWindow::onSixStarClicked(){
    ui->graphicsView->setScene(scene);
    scene->removeItem(universal);
    universal = new SixStar;
    this->EnabledActions(true);
    scene->addItem(universal);
    universal->setPos(0,0);
}

void MainWindow::onRombClicked(){
    ui->graphicsView->setScene(scene);
    scene->removeItem(universal);
    universal = new Romb;
    this->EnabledActions(true);
    scene->addItem(universal);
    universal->setPos(0,0);
}

void MainWindow::onRectangleClicked(){
    ui->graphicsView->setScene(scene);
    scene->removeItem(universal);
    universal = new Rectangle;
    this->EnabledActions(true);
    scene->addItem(universal);
    universal->setPos(0,0);
}

void MainWindow::onParallelogramClicked(){
    ui->graphicsView->setScene(scene);
    scene->removeItem(universal);
    universal = new Parallelogram;
    this->EnabledActions(true);
    scene->addItem(universal);
    universal->setPos(0,0);
}

void MainWindow::onHexagonClicked(){
    ui->graphicsView->setScene(scene);
    scene->removeItem(universal);
    universal = new Hexagon;
    this->EnabledActions(true);
    scene->addItem(universal);
    universal->setPos(0,0);
}

void MainWindow::onFiveStarClicked(){
    ui->graphicsView->setScene(scene);
    scene->removeItem(universal);
    universal = new FiveStar;
    this->EnabledActions(true);
    scene->addItem(universal);
    universal->setPos(0,0);
}

void MainWindow::onDecreaseClicked(){
    disconnecnTimers();
    universal->setUnivers(false);
    connect(time, SIGNAL(timeout()), this, SLOT(size_slot()));
    time->start(10);
    QTimer::singleShot(70,time, SLOT(stop()));
}

void MainWindow::onDownClicked(){
    disconnecnTimers();
    connect(time, SIGNAL(timeout()), this, SLOT(move_down_slot()));
    time->start(10);
    QTimer::singleShot(70,time, SLOT(stop()));
}

void MainWindow::onIncreaseClicked(){
    disconnecnTimers();
    universal->setUnivers(true);
    connect(time, SIGNAL(timeout()), this, SLOT(size_slot()));
    time->start(10);
    QTimer::singleShot(70,time, SLOT(stop()));
    //QTimer::singleShot(30, SLOT(disconnect(time, SIGNAL(timeout()), this, SLOT(size_slot()));));
}

void MainWindow::onLeftClicked(){
    disconnecnTimers();
    connect(time, SIGNAL(timeout()), this, SLOT(move_left_slot()));
    time->start(10);
    QTimer::singleShot(70,time, SLOT(stop()));
}

void MainWindow::onLeftTurnClicked(){
    disconnecnTimers();
    universal->setUnivers(false);
    connect(time, SIGNAL(timeout()), this, SLOT(rotate_slot()));
    time->start(10);
    QTimer::singleShot(70,time, SLOT(stop()));
}

void MainWindow::onRightClicked(){
    disconnecnTimers();
    connect(time, SIGNAL(timeout()), this, SLOT(move_right_slot()));
    time->start(10);
    QTimer::singleShot(70,time, SLOT(stop()));
}

void MainWindow::onRightTurnClicked(){
    disconnecnTimers();
    universal->setUnivers(true);
    connect(time, SIGNAL(timeout()), this, SLOT(rotate_slot()));
    time->start(10);
    QTimer::singleShot(70,time, SLOT(stop()));
}

void MainWindow::onUpClicked(){
    disconnecnTimers();
    connect(time, SIGNAL(timeout()), this, SLOT(move_up_slot()));
    time->start(10);
    QTimer::singleShot(70,time, SLOT(stop()));
}

void MainWindow::size_slot(){
    universal->size();
}

void MainWindow::move_up_slot(){
    universal->move_up();
}

void MainWindow::move_down_slot(){
    universal->moveDown();
}

void MainWindow::move_left_slot(){
    universal->moveLeft();
}

void MainWindow::move_right_slot(){
    universal->moveRight();
}

void MainWindow::rotate_slot(){
    universal->rotate();
}

void MainWindow::EnabledActions(bool turn){
    ui->actionDecrease->setEnabled(turn);
    ui->actionDown->setEnabled(turn);
    ui->actionIncrease->setEnabled(turn);
    ui->actionInfo_about_figure->setEnabled(turn);
    ui->actionLeft->setEnabled(turn);
    ui->actionLeft_turn->setEnabled(turn);
    ui->actionRight->setEnabled(turn);
    ui->actionRight_turn->setEnabled(turn);
    ui->actionUp->setEnabled(turn);
}

void MainWindow::disconnecnTimers(){
    disconnect(time, SIGNAL(timeout()), this, SLOT(size_slot()));
    disconnect(time, SIGNAL(timeout()), this, SLOT(move_up_slot()));
    disconnect(time, SIGNAL(timeout()), this, SLOT(move_down_slot()));
    disconnect(time, SIGNAL(timeout()), this, SLOT(move_right_slot()));
    disconnect(time, SIGNAL(timeout()), this, SLOT(move_left_slot()));
    disconnect(time, SIGNAL(timeout()), this, SLOT(rotate_slot()));
}
