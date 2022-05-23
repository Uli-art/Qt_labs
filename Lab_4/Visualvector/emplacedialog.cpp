#include "emplacedialog.h"
#include "ui_emplacedialog.h"

EmplaceDialog::EmplaceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmplaceDialog)
{
    ui->setupUi(this);
}

EmplaceDialog::~EmplaceDialog()
{
    delete ui;
}

int EmplaceDialog::getElement(){
    return ui->lineEdit->text().toInt();
}

int EmplaceDialog::getPosition(){
    return ui->lineEdit_2->text().toInt();
}
