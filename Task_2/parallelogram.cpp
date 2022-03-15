#include "parallelogram.h"

Parallelogram::Parallelogram()
{

}

void Parallelogram::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::black);
    QPolygon polygon;
    polygon << QPoint(-80,40) << QPoint(-30,-40) << QPoint(70,-40) << QPoint(20, 40);
    painter->drawPolygon(polygon);
}

double Parallelogram::square(){
    return this->getK() * this->getK() * sin(angel*3.14 /180) * FirstLen * SecondLen;
}

double Parallelogram::perimetr(){
    return (2 * getK() * FirstLen + 2 * getK() * SecondLen);
}
