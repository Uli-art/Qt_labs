#include "windowforinfo.h"
#include "ui_windowforinfo.h"

WindowForInfo::WindowForInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WindowForInfo)
{
    ui->setupUi(this);
}

WindowForInfo::~WindowForInfo()
{
    delete ui;
}
