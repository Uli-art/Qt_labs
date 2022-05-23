#include "assigndialog.h"
#include "ui_assigndialog.h"

AssignDialog::AssignDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AssignDialog)
{
    ui->setupUi(this);
}

AssignDialog::~AssignDialog()
{
    delete ui;
}

int AssignDialog::getFirst(){
    return ui->lineEdit->text().toInt();
}

int AssignDialog::getLast(){
    return ui->lineEdit_2->text().toInt();
}
