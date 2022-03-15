#include "date.h"
Date::Date(){

}
Date::Date(int day, int month, int year)
{
    this->day =day;
    this->month = month;
    this->year = year;
}

bool Date::isLeap(Date newdate){
    QDate date;
    //int year = date.year();
    return date.isLeapYear(newdate.year);
}
short Date::WeekNumber(Date date){
    QDate newdate(date.year, date.month, date.day);
    //newdate = date.currentDate();
    return newdate.weekNumber();
};

int Date::DaysTillYourBithday(Date bithdaydate){
    QDate date;
    date = date.currentDate();
    QDate Bday(date.year(), bithdaydate.month, bithdaydate.day);
    int days = date.daysTo(Bday);
    days = days % 365;
    if(days < 0){
        int year = date.year();
        days += 365;
        if(date.isLeapYear(year)){
            days += 1;
        }
    }
    return days;
};

int Date::Dutation(Date date){
    QDate curDate;
    curDate = curDate.currentDate();
    int days = curDate.daysTo(date);
    if(days < 0){
        days = -days;
    }
    return days;
};

QDate Date::NextDay(Date newdate){
    QDate date(newdate.year, newdate.month, newdate.day);
    //date = date.currentDate();
    date = date.addDays(1);
    //Date newDate(date.day(), date.month(), date.year());
    return date;
};

QDate Date::PreviousDay(Date newdate){
    QDate date(newdate.year, newdate.month, newdate.day);
    //date = date.currentDate();
    //date = date.currentDate();
    date = date.addDays(-1);
    //Date newDate(date.day(), date.month(), date.year());
    return date;
};
