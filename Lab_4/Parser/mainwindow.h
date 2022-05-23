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
    void CountOfVariables();
    void FindPrototype();
    void ChangeVariables();
    void CountOfLocalVariables();
    void CountOfOverloading();
    void BranchingDepth();
    void LogicErrors();
    void Check();
    void clearAll();
private slots:
    void on_pushButtonCheck_clicked();
    void onOpenFile_clicked();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
