#ifndef EMPLACEDIALOG_H
#define EMPLACEDIALOG_H

#include <QDialog>

namespace Ui {
class EmplaceDialog;
}

class EmplaceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EmplaceDialog(QWidget *parent = nullptr);
    ~EmplaceDialog();
    int getElement();
    int getPosition();
private:
    Ui::EmplaceDialog *ui;
};

#endif // EMPLACEDIALOG_H
