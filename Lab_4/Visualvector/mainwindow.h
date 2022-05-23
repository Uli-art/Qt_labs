#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void showInfo();
private slots:
    void onClear_clicked();
    void onAssign_clicked();
    void onEmplace_clicked();
    void onEmplace_back_clicked();
    void onInsert_clicked();
    void onPush_back_clicked();
    void onPop_back_clicked();
    void onErase_clicked();
    void onReserve_clicked();
    void onResize_clicked();
    void onSwap_clicked();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
