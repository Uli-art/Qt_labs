    #ifndef WINDOWFORINFO_H
#define WINDOWFORINFO_H

#include <QDialog>

namespace Ui {
class WindowForInfo;
}

class WindowForInfo : public QDialog
{
    Q_OBJECT

public:
    explicit WindowForInfo(QWidget *parent = nullptr);
    ~WindowForInfo();

private:
    Ui::WindowForInfo *ui;

};

#endif // WINDOWFORINFO_H
