#include "adddialog.h"
#include "ui_adddialog.h"
#include "stack.h"
#include <QMessageBox>
AddDialog::AddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDialog)
{
    ui->setupUi(this);
}

AddDialog::~AddDialog()
{
    delete ui;
}

Data AddDialog::getData(){
    return Data(ui->InfForm->text(),ui->a->valueFromText(ui->a->text()), ui->b->valueFromText(ui->b->text()),ui->c->valueFromText(ui->c->text()),ui->d->valueFromText(ui->d->text()),ui->e->valueFromText(ui->e->text()));
}

void AddDialog::setData(Data &data){
    ui->InfForm->setText(data.expression);
    ui->a->setValue(data.a);
    ui->b->setValue(data.b);
    ui->c->setValue(data.c);
    ui->d->setValue(data.d);
    ui->e->setValue(data.e);
}

void AddDialog::accept(){
    QString exp = ui->InfForm->text();
    if(exp == "" ){
        QMessageBox::warning(this,"title","Fill in infix form");
        return ;
    }
    for(int i = 0; i < exp.size();++i){
        if(isItRightLetter(QString(exp[i]))){
            if(!isItNumber(QString(exp[i]))){
                QMessageBox::warning(this,"title","Use only letters a,b,c,d,e");
                return ;
            }
        }
    }
    for(int i = 0; i < exp.size() - 1; ++i){
        if(isItNumber(QString(exp[i])) && isItNumber(QString(exp[i+1]))){
            QMessageBox::warning(this,"title","Enter correct infix form");
            return ;
        }
    }
    if(!Check(exp)){
        QMessageBox::warning(this,"title","Enter correct brakets");
        return;
    }
    QDialog::accept();
}
bool AddDialog::isItRightLetter(QString element){
    QRegExp reg("[a-z]");
    return reg.indexIn(element) != -1;
}
bool AddDialog::isItNumber(QString element){
    QRegExp reg("[a-e]");
    return reg.indexIn(element) != -1;
}

bool AddDialog::Check(QString exp){
    Stack stack;
    Stack stack2;
    for(int j = 0; j < exp.size(); ++j){
        if(exp[j] == '[' || exp[j] == '(' || exp[j] == '{'){
                stack.push(QString(exp[j]));
            }
            else if(exp[j] == ']' || exp[j] == ')' || exp[j] == '}'){
                if(stack.getSize() == 0 || exp[j] != getPair(stack.getValue())){
                    stack2.push(QString(exp[j]));
                    return false;
                }
             stack.pop();
         }
     }

    if(stack.getSize() != 0){
        for(int i = 0; i < stack.getSize() - 1; ++i){
            stack.pop();
        }
        return false;
    }
    return true;
}

QString AddDialog::getPair(QString braket){
    if(braket == "(")
        return ")";
    if(braket == "[")
        return "]";
    return "}";
}
