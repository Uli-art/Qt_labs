#include "romb.h"

Romb::Romb()
{

}

void Romb::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setPen(Qt::black);
    QPolygon polygon;
    polygon << QPoint(0,-40) << QPoint(25,0) << QPoint(0,40) << QPoint(-25,0);
    painter->drawPolygon(polygon);
}

double Romb::square(){
    return size * size * sin(angel*3.14 /180) * this->getK() * this->getK();
}

double Romb::perimetr(){
    return 4 * getK() * size;
}
