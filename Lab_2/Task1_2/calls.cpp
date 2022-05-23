#include "calls.h"

Calls::Calls()
{}

Calls::Calls(QDate dateOfCall,int codeOfCity, QString city,QTime time,QString rate,QString phoneNumberCity,QString phoneNumber)
    : dateOfCall(dateOfCall),codeOfCity(codeOfCity),city(city),time(time),rate(rate),phoneNumberCity(phoneNumberCity),phoneNumber(phoneNumber){}

QDate Calls::getDateOfCall(){
    return dateOfCall;
}
int Calls::getCodeOfCity(){
    return codeOfCity;
}
QString Calls::getCity(){
    return city;
}
QTime Calls::getTime(){
    return time;
}
QString Calls::getRate(){
    return rate;
}
QString Calls::getPhoneNumberCity(){
    return phoneNumberCity;
}
QString Calls::getPhoneNumber(){
    return phoneNumber;
}

void Calls::operator=(Calls anotherCall){
    this->dateOfCall = anotherCall.dateOfCall;
     this->codeOfCity = anotherCall.codeOfCity;
     this->city = anotherCall.city;
     this->time = anotherCall.time;
     this->rate = anotherCall.rate;
     this->phoneNumberCity = anotherCall.phoneNumberCity;
     this->phoneNumber = anotherCall.phoneNumber;
}
