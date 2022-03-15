#include "hexagon.h"

Hexagon::Hexagon()
{

}

void Hexagon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setPen(Qt::black);
    QPolygon polygon;
    polygon << QPoint(-radius,0) << QPoint(-radius / 2, radius * sqrt(3) / 2) << QPoint(radius / 2,radius * sqrt(3) / 2) << QPoint(radius,0) << QPoint(radius / 2,-radius * sqrt(3) / 2) << QPoint(-radius/2,-radius * sqrt(3)/2);
    painter->drawPolygon(polygon);
}

double Hexagon::square(){
    return this->getK() * this->getK() * 3 * radius * radius * sqrt(3) / 2;
}

double Hexagon::perimetr(){
    return 6 * radius * this->getK();
}
