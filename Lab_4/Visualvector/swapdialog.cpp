#include "swapdialog.h"
#include "ui_swapdialog.h"

SwapDialog::SwapDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SwapDialog)
{
    ui->setupUi(this);
}

SwapDialog::~SwapDialog()
{
    delete ui;
}


QString SwapDialog::getLine(){
    return ui->lineEdit->text();
}
