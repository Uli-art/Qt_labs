#include "findbytitleyeardialog.h"
#include "ui_findbytitleyeardialog.h"

FindByTitleYearDialog::FindByTitleYearDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindByTitleYearDialog)
{
    ui->setupUi(this);
}

FindByTitleYearDialog::~FindByTitleYearDialog()
{
    delete ui;
}
void FindByTitleYearDialog::accept(){
    int year = ui->year->text().toInt();
    if(year <= 0 || year > 10000){
        return;
    }
    QDialog::accept();
}

QString FindByTitleYearDialog::getTitle(){
    return ui->title->text();
}
int FindByTitleYearDialog::getYear(){
    return ui->year->text().toInt();
}
