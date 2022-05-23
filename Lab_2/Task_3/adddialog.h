#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>
#include "data.h"
namespace Ui {
class AddDialog;
}

class AddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDialog(QWidget *parent = nullptr);
    ~AddDialog();
    Data getData();
    void setData(Data &data);
    void accept();
    bool isItNumber(QString element);
    bool Check(QString exp);
    QString getPair(QString braket);
    bool isItRightLetter(QString element);
private:
    Ui::AddDialog *ui;
};

#endif // ADDDIALOG_H
