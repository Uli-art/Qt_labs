#include "data.h"

Data::Data()
{

}

Data::Data(QString expression,
           double a,
           double b,
           double c,
           double d,
           double e,
           QString converted,
           double result): expression(expression), a(a), b(b), c(c), d(d), e(e), converted(converted), result(result){
    }

Data::Data(QString expression,
           double a,
           double b,
           double c,
           double d,
           double e): expression(expression), a(a), b(b), c(c), d(d), e(e){
    }
