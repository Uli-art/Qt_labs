#include "circle.h"

Circle::Circle()
{

}

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setPen(Qt::black);
    painter->drawEllipse(-radius / 2,- radius / 2,radius,radius);
}

double Circle::square(){
    return this->getK() * this->getK() * 3.14  * radius * radius;
}

double Circle::perimetr(){
    return 2 * 3.14 * radius * this->getK();
}
