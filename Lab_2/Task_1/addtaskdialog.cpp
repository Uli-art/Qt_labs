#include "addtaskdialog.h"
#include "ui_addtaskdialog.h"
#include <QMessageBox>
AddTaskDialog::AddTaskDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTaskDialog)
{
    ui->setupUi(this);
}

AddTaskDialog::~AddTaskDialog()
{
    delete ui;
}

Book AddTaskDialog::getBook() const{
    return Book(ui->Number->text(),ui->Author->text(), ui->Title->text(),ui->year->text().toInt(), ui->publisher->text(), ui->pages->text().toInt());
}

bool AddTaskDialog::accept(QString* booksRegistrNumber, int size){
    if(ui->Number->text() == "" ||  ui->Author->text() == "" || ui->Title->text() == "" || ui->year->text() == "" || ui->publisher->text() == "" || ui->pages->text() == ""){
        QMessageBox::warning(this,"title","Fill in all the fields");
        return false;
    }
    if(ui->pages->text().toInt() <= 0 || ui->year->text().toInt() <= 0){
        QMessageBox::warning(this,"title","Enter correct pages or year");
        return false;
    }
    for(int i = 0; i < size; ++i){
        if(ui->Number->text().compare(booksRegistrNumber[i]) == 0){
            QMessageBox::warning(this,"title","Registration number should be unique");
            return false;
        }
    }
    QDialog::accept();
    return true;

}

bool AddTaskDialog::accept(QString* booksRegistrNumber, int size, int index){
    for(int i = 0; i < size; ++i){
        if(ui->Number->text().compare(booksRegistrNumber[i]) == 0 && i != index){
            QMessageBox::warning(this,"title","Registration number should be unique");
            return false;
        }
    }
    QDialog::accept();
    return true;
}

void AddTaskDialog::accept(){
    if(ui->Number->text() == "" ||  ui->Author->text() == "" || ui->Title->text() == "" || ui->year->text() == "" || ui->publisher->text() == "" || ui->pages->text() == ""){
        QMessageBox::warning(this,"title","Fill in all the fields");
        return ;
    }
    if(ui->pages->text().toInt() <= 0 || ui->year->text().toInt() <= 0){
        QMessageBox::warning(this,"title","Enter correct pages or year");
        return ;
    }

    QDialog::accept();
}

void AddTaskDialog::setCurrentTask(Book &changeBook) const{
    ui->Number->setText(changeBook.getRegistrationNumber());
    ui->Author->setText(changeBook.getAuthor());
    ui->Title->setText(changeBook.getTitle());
    ui->year->setText(QString::number(changeBook.getYear()));
    ui->publisher->setText(changeBook.getPublisher());
    ui->pages->setText(QString::number(changeBook.getPages()));
}
