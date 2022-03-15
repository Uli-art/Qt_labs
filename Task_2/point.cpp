#include "point.h"

Point::Point()
{

}

Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;
}

void Point::move(double addX, double addY){
    x+=addX;
    y+=addY;
}

