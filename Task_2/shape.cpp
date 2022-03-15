#include "shape.h"

Shape::Shape()
{

}

QRectF Shape::boundingRect() const
{
    return QRectF(-500,-500,1000,1000);   // Ограничиваем область, в которой лежит фигура
}

bool Shape::getUnivers()
{
    return shp;
}

void Shape::setUnivers(bool rot)
{
    shp = rot;
}

void Shape::move_up(){
    this->setPos(this->x(), this->y() - 3);

    if (this->y() < -500){
        this->setPos(this->x(), 500);
    }
}

void Shape::size(){
    if(this->getUnivers()){
        if(k < 14)
            k += 0.02;
        //if (k > 14) k = 0;
    }
    else {
        if(k > 0.5)
            k -= 0.02;
        //if (k < 0) k = 14;
    }

    this->setScale(k);
}

void Shape::moveRight()
{
    this->setPos(this->x() + 3, this->y());
    if (this->x() > 1000){
        this->setPos(-1000, this->y());
    }
}

void Shape::moveLeft()
{
    this->setPos(this->x() - 3, this->y());
    if (this->x() < -1000){
        this->setPos(1000, this->y());
    }
}

void Shape::moveDown()
{
    this->setPos(this->x(), this->y() + 3);
    if (this->y() > 500){
        this->setPos(this->x(), -500);
    }
}

void Shape::rotate()
{
    if(this->getUnivers()) ++a;
    else --a;

    this->setRotation(a);
}

QPoint Shape::getCenter()
{
    return QPoint(this->x(), this->y());
}

double Shape::square(){
    return -1;
}

double Shape::perimetr(){
    return -1;
}

double Shape::getK(){
    return k;
}

void Shape::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
}

