#ifndef FINDBYTITLEYEARDIALOG_H
#define FINDBYTITLEYEARDIALOG_H

#include <QDialog>

namespace Ui {
class FindByTitleYearDialog;
}

class FindByTitleYearDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FindByTitleYearDialog(QWidget *parent = nullptr);
    ~FindByTitleYearDialog();
    void accept();
    QString getTitle();
    int getYear();
private:
    Ui::FindByTitleYearDialog *ui;
};

#endif // FINDBYTITLEYEARDIALOG_H
