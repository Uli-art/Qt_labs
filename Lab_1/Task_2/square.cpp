#include "square.h"

Square::Square()
{

}

void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setPen(Qt::black);
    painter->drawRect(-size/2,-size/2,size,size);
}

double Square::square(){
    return this->getK() * this->getK() * size * size;
}

double Square::perimetr(){
    return 4 * getK() * size;
}
