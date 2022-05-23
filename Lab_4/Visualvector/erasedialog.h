#ifndef ERASEDIALOG_H
#define ERASEDIALOG_H

#include <QDialog>

namespace Ui {
class EraseDialog;
}

class EraseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EraseDialog(QWidget *parent = nullptr);
    ~EraseDialog();
    int getFirst();
    int getLast();
private:
    Ui::EraseDialog *ui;
};

#endif // ERASEDIALOG_H
