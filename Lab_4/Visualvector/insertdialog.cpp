#include "insertdialog.h"
#include "ui_insertdialog.h"

InsertDialog::InsertDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InsertDialog)
{
    ui->setupUi(this);
}

InsertDialog::~InsertDialog()
{
    delete ui;
}

int InsertDialog::getElement(){
    return ui->lineEdit->text().toInt();
}

int InsertDialog::getPosition(){
    return ui->lineEdit_2->text().toInt();
}
