#ifndef DATE_H
#define DATE_H
#include <QString>
#include <QDate>

class Date : public QDate
{
public:
    Date();
    Date(int day, int month, int year);
    bool isLeap(Date newdate);
    short WeekNumber(Date date);
    int DaysTillYourBithday(Date bithdaydate);
    int Dutation(Date date);
    QDate NextDay(Date newdate);
    QDate PreviousDay(Date newdate);

private:
    int day;
    int month;
    int year;
};

#endif // DATE_H
