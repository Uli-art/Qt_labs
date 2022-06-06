#include "adddialog.h"
#include "ui_adddialog.h"

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

int AddDialog::getKey(){
    return ui->key->text().toInt();
}

int AddDialog::getValue(){
    return ui->value->text().toInt();
}
