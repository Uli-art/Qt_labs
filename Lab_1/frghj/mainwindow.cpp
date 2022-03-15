#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Rect.h"
#include "truck.h"
#include <QPainter>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
static int count = 0;
void MainWindow::paintEvent(QPaintEvent *) {
    Truck truck;
    QPainter* painter = new QPainter;
    painter->begin(this);
    if(button == 1){

        Rect rect;
        rect.doDrawing(painter);
        painter->end();
        delete painter;

    } else if(button == 2){


        truck.doDrawing(painter);
        painter->end();
        delete painter;

    } else if(button == 3){

        //Truck truck;
        truck.liftingBucket(painter, count % 2);
        painter->end();
        delete painter;


    }
    update();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    button = 1;
}


void MainWindow::on_pushButton_2_clicked()
{
    button = 2;
}


void MainWindow::on_pushButton_3_clicked()
{
    ++count;
    button = 3;
}

