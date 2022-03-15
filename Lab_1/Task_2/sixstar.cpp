#include "sixstar.h"

SixStar::SixStar()
{

}

void SixStar::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::black);
    int a = 0;
    QPoint p[6 * 2 + 1]; //Массив для хранения координат вершин звезды

    //Цикл расчета вершин звезды
    for (int i = 1; i < top * 2 + 1; ++i) {
        if (!(i % 2)) {//При выполнении условия четности следующие формулы
            p[i].rx() = radius / 2 * cos(a * 3.14  / 180);
            p[i].ry() = radius / 2 * sin(a * 3.14  / 180);
        }
        else {//При невыполнении условия четности следующие формулы
            p[i].rx() = Radius * cos(a * 3.14  / 180);
            p[i].ry() = Radius * sin(a * 3.14  / 180);
        }
        a = a + 180 / top;
    }
    //Соединяем конец с начальной точкой
    p[top * 2 + 1].rx() = p[1].rx();
    p[top * 2 + 1].ry() = p[1].ry();

    //Последовательное соединение точек массива, хранящего вершины звезды
    for (int i = 1; i < top * 2 + 1; ++i) {
        painter->drawLine(p[i].rx(),p[i].ry(), p[i + 1].rx(),p[i + 1].ry());
    }

    //delete []p;
}

double SixStar::square(){
    return this->getK() * this->getK() * (3.14  * radius * radius + (3.14  * Radius * Radius - 3.14  * radius * radius) / 5);
}

double SixStar::perimetr(){
    return radius * top + Radius * top * this->getK();
}

