#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Set.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void print();
private slots:
    void onClear_clicked();
    void onContains_clicked();
    void onInsert_clicked();
    void onDelete_clicked();
private:
    Ui::MainWindow *ui;
    Set<int> test;
};
#endif // MAINWINDOW_H
