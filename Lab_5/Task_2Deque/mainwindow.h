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
    void onPush_back_clicked();
    void onPush_front_clicked();
    void onPop_back_clicked();
    void onPop_front_clicked();
    void onClear_clicked();
    void onResize_clicked();
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void print();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
