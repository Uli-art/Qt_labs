#ifndef ADDCALL_H
#define ADDCALL_H

#include <QDialog>
#include "calls.h"
namespace Ui {
class AddCall;
}

class AddCall : public QDialog
{
    Q_OBJECT

public:
    explicit AddCall(QWidget *parent = nullptr);
    ~AddCall();
    Calls getCall();
    void setCurrentCall(Calls &call);
    void accept();
private:
    Ui::AddCall *ui;
};

#endif // ADDCALL_H
