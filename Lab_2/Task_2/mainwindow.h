#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stack.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private slots:
    void onOpen_clicked();
    void on_check_clicked();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int Check();
    QString getPair(QString braket);
private:
    Ui::MainWindow *ui;
    QString currentFilePath;
    Stack stack;
    Stack stack2;
};
#endif // MAINWINDOW_H
