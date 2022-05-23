#ifndef DATA_H
#define DATA_H
#include <QString>

struct Data
{
public:
    Data();
    Data(QString expression,
        double a,
        double b,
        double c,
        double d,
        double e,
        QString converted,
        double result);
    Data(QString expression,
        double a,
        double b,
        double c,
        double d,
        double e);
    QString expression;
    double a;
    double b;
    double c;
    double d;
    double e;
    QString converted;
    double result;
};

#endif // DATA_H
