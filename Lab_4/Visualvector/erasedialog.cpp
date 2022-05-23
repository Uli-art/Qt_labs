#include "erasedialog.h"
#include "ui_erasedialog.h"

EraseDialog::EraseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EraseDialog)
{
    ui->setupUi(this);
}

EraseDialog::~EraseDialog()
{
    delete ui;
}

int EraseDialog::getFirst(){
    return ui->lineEdit->text().toInt();
}

int EraseDialog::getLast(){
    return ui->lineEdit_2->text().toInt();
}

