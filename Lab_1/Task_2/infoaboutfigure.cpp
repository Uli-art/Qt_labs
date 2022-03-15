#include "infoaboutfigure.h"
#include "ui_infoaboutfigure.h"

InfoAboutFigure::InfoAboutFigure(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoAboutFigure)
{
    ui->setupUi(this);
}

InfoAboutFigure::~InfoAboutFigure()
{
    delete ui;
}

void InfoAboutFigure::setInfo(double perimeter, double area, QPoint gravity){
    QString per = QString::number(perimeter);
    QString are = QString::number(area);
    ui->perimeter->setText(per);
    ui->area->setText(are);
    ui->gravity->setText("(" + QString::number(gravity.x()) + ";" + QString::number(gravity.y()) + ")");
}
