#include "truck.h"
#include "mainwindow.h"
#include <QPainter>
Truck:: Truck()
{

}
//void MainWindow::paintEvent(QPaintEvent *) {
//    QPainter* painter = new QPainter;
//    painter->begin(this);
//    Truck truck;
//    truck.doDrawing(painter);
//    painter->end();
//    delete painter;
//    update();
//}
double centerCoord;
double angleRoutate;
void Truck::doDrawing(QPainter *painter) {
    static double center;
    center+= 0.1;
    if(center > 900){
        center = 0;
    }
    painter->translate(QPoint(center,0));
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setPen(QPen(Qt::black,2));

    painter->setBrush(QBrush(Qt::blue));
    painter->drawRect(10,135,120,50);
    painter->setBrush(QBrush(Qt::blue));
    painter->drawRoundRect(QRect(130,95,70,90), 30,30);
    painter->setBrush(QBrush(Qt::white));
    painter->setPen(QPen(Qt::black,12));
    painter->drawEllipse(40,185,30,30);
    painter->drawEllipse(150,185,30,30);
    painter->setPen(QPen(Qt::black,2));
    painter->rotate(angleRoutate);
    painter->setBrush(QBrush(Qt::yellow));
    painter->drawRect(10,85,100,50);
    centerCoord = center;
}

void Truck::liftingBucket(QPainter *painter, int direction){
    static double angle = 0;

    if(angle > -10 && direction){
    angle -=0.01;} else if(angle <= 0){angle += 0.01;}
    QPainter* painterRect = painter;
    painter->translate(QPoint(centerCoord,0));
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setPen(QPen(Qt::black,2));
    painter->setBrush(QBrush(Qt::blue));
    painter->drawRect(10,135,120,50);
    painter->setBrush(QBrush(Qt::blue));
    painter->drawRoundRect(QRect(130,95,70,90), 30,30);
    painter->setBrush(QBrush(Qt::white));
    painter->setPen(QPen(Qt::black,12));
    painter->drawEllipse(40,185,30,30);
    painter->drawEllipse(150,185,30,30);
    painter->setPen(QPen(Qt::black,2));
    painterRect->rotate(angle);
    painterRect->setBrush(QBrush(Qt::yellow));
    painterRect->drawRect(10,85,100,50);
    angleRoutate = angle;
}

