#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "shared_ptr.h"
#include "weak_ptr.h"
#include "unique_ptr.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private slots:
    void on_Addweak_clicked();
    void on_Addunique_clicked();
    void on_Addshared_clicked();
    void on_Reset_clicked();
    void on_Delete_clicked();
    void on_CopyFrom_clicked();
    void on_Swap_clicked();
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void showAll();
private:
    Ui::MainWindow *ui;
    std::vector<shared_ptr<int>> shared;
    std::vector<weak_ptr<int>> weak;
    std::vector<unique_ptr<int>> unique;
};
#endif // MAINWINDOW_H
