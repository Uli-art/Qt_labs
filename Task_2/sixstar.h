#ifndef SIXSTAR_H
#define SIXSTAR_H

#include <shape.h>

class SixStar : public Shape
{
private:
    int Radius = 80;
    int radius = 80;
    int top = 6;
public:
    SixStar();
    double square() override;
    double perimetr() override;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // SIXSTAR_H
