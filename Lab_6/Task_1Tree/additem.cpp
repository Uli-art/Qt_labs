#include "additem.h"
#include "ui_additem.h"

AddItem::AddItem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddItem)
{
    ui->setupUi(this);
}

AddItem::~AddItem()
{
    delete ui;
}

int AddItem::getKey(){
    return ui->key->text().toInt();
}
QString AddItem::getData(){
    return ui->data->text();
}
