#include "addcall.h"
#include "ui_addcall.h"
#include <QMessageBox>
AddCall::AddCall(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCall)
{
    ui->setupUi(this);
}

AddCall::~AddCall()
{
    delete ui;
}

Calls AddCall::getCall(){
    QDate dateOfCall = ui->Date->date();
    int codeOfCity = ui->Code->text().toInt();
    QString city =  ui->City->text();
    QTime time = ui->Time->time();
    QString rate = ui->Rate->text();
    QString phoneNumberCity = ui->CityNum->text();
    QString phoneNumber =  ui->SubNum->text();
    return Calls(dateOfCall,codeOfCity ,city, time,rate ,phoneNumberCity ,phoneNumber );
}

void AddCall::setCurrentCall(Calls &call){
    ui->Date->setDate(call.getDateOfCall());
    ui->Code->setText(QString::number(call.getCodeOfCity()));
    ui->City->setText(call.getCity());
    ui->Time->setTime(call.getTime());
    ui->Rate->setText(call.getRate());
    ui->CityNum->setText(call.getPhoneNumberCity());
    ui->SubNum->setText(call.getPhoneNumber());
}
void AddCall::accept(){
    if(ui->Code->text() == "" || ui->City->text() == "" || ui->Rate->text() == "" || ui->CityNum->text() == "" || ui->SubNum->text() == ""){
        QMessageBox::warning(this,"title","Fill in all the fields");
        return ;
    }
    int i = 0;
    while (i != ui->Code->text().size()){
        if (!ui->Code->text()[i].isNumber()) return;
            ++i;
    }
    i = 0;
    while (i != ui->City->text().size()) {
        if (!ui->City->text()[i].isLetter()) return;
            ++i;
    }
    if (ui->CityNum->text().size() != 17) return;

    if (ui->SubNum->text().size() != 17) return;

    QDialog::accept();
}
