#include "rectangle.h"

Rectangle::Rectangle()
{

}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setPen(Qt::black);
    painter->drawRect(-length / 2,-width / 2,length,width);
}

double Rectangle::square(){
    return this->getK() * this->getK() * length * width;
}

double Rectangle::perimetr(){
    return (2 * getK() * length + 2 * getK() * width);
}
