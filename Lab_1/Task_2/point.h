#ifndef POINT_H
#define POINT_H


class Point
{
public:
    Point();
    Point(double x, double y);
    void move(double addX, double addY);
private:
    double x;
    double y;
};

#endif // POINT_H
