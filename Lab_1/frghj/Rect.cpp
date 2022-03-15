#include "Rect.h"
#include <QPainter>
#include "mainwindow.h"
#include "truck.h"
Rect::Rect(QWidget *parent) : QWidget(parent)
{

}


void Rect::doDrawing(QPainter *painter) {
    static double x;
    QBrush brush(Qt::gray, Qt::SolidPattern);
    painter->fillRect(point_x + x,point_y,width,heigth,brush);
    x+= 0.1;
    if(x >=900){
        x = 0;
    }
}
