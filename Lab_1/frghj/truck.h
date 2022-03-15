#ifndef TRUCK_H
#define TRUCK_H
#include "Rect.h"

class Truck : public Rect
{
public:
    Truck();
    void doDrawing(QPainter *painter) override;
    void liftingBucket(QPainter *painter, int direction);
};

#endif // TRUCK_H
