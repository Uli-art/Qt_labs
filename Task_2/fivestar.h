#ifndef FIVESTAR_H
#define FIVESTAR_H

#include <shape.h>

class FiveStar : public Shape
{
private:
    int Radius = 60;
    int radius = 40;
    int top = 5;
public:
    FiveStar();
    double square() override;
    double perimetr() override;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // FIVESTAR_H
