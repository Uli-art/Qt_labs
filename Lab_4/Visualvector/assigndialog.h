#ifndef ASSIGNDIALOG_H
#define ASSIGNDIALOG_H

#include <QDialog>

namespace Ui {
class AssignDialog;
}

class AssignDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AssignDialog(QWidget *parent = nullptr);
    ~AssignDialog();
    int getFirst();
    int getLast();
private:
    Ui::AssignDialog *ui;
};

#endif // ASSIGNDIALOG_H
