#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private slots:
    void onStrcpyCopyClicked();
    void onStrncpyCopyClicked();
    void onMemcpyCopyClicked();
    void onStrcmpCompareClicked();
    void onStrncmpCompareClicked();
    void onMemcmpCompareClicked();
    void onStrcatCompareClicked();
    void onStrncatCompareClicked();
    void onMemmoveCopyClicked();
    void onStrtokDivideClicked();
    void onMemsetSetClicked();
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
