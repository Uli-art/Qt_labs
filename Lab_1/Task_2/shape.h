#ifndef SHAPE_H
#define SHAPE_H

#include <QGraphicsItem>
#include <QPainter>

class Shape : public QGraphicsItem
{
private:
    bool shp;
    double k = 1;
    int a = 0;
public:
    Shape();
    bool getUnivers();
    void setUnivers(bool uni);
    double getK();

    void move_up();
    void size();
    void moveRight();
    void moveLeft();
    void moveDown();
    void rotate();
    QPoint getCenter();

    virtual double square();
    virtual double perimetr();
protected:
    QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // SHAPE_H
