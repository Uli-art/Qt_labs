#ifndef CALLS_H
#define CALLS_H
#include <QDate>

class Calls
{
private:
    QDate dateOfCall;
    int codeOfCity;
    QString city;
    QTime time;
    QString rate;
    QString phoneNumberCity;
    QString phoneNumber;
public:
    Calls();
    Calls(QDate dateOfCall,
    int codeOfCity,
    QString city,
    QTime time,
    QString rate,
    QString phoneNumberCity,
    QString phoneNumber);
    void operator = (Calls anotherCall);

    QDate getDateOfCall();
    int getCodeOfCity();
    QString getCity();
    QTime getTime();
    QString getRate();
    QString getPhoneNumberCity();
    QString getPhoneNumber();
};

#endif // CALLS_H
