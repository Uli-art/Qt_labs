#ifndef EIGHTSTAR_H
#define EIGHTSTAR_H

#include <shape.h>

class EightStar : public Shape
{
private:
    int Radius = 80;
    int radius = 60;
    int top = 8;
public:
    EightStar();
    double square() override;
    double perimetr() override;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // EIGHTSTAR_H
