#ifndef INFOABOUTFIGURE_H
#define INFOABOUTFIGURE_H

#include <QDialog>

namespace Ui {
class InfoAboutFigure;
}

class InfoAboutFigure : public QDialog
{
    Q_OBJECT

public:
    explicit InfoAboutFigure(QWidget *parent = nullptr);
    ~InfoAboutFigure();
    void setInfo(double perimeter, double area, QPoint gravity);

private:
    Ui::InfoAboutFigure *ui;
};

#endif // INFOABOUTFIGURE_H
