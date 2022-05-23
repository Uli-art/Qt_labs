#ifndef SWAPDIALOG_H
#define SWAPDIALOG_H

#include <QDialog>

namespace Ui {
class SwapDialog;
}

class SwapDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SwapDialog(QWidget *parent = nullptr);
    ~SwapDialog();
    QString getLine();
private:
    Ui::SwapDialog *ui;
};

#endif // SWAPDIALOG_H
