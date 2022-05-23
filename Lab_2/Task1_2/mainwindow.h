#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "list.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private slots:
    void onFindBy_City_clicked();
    void onDelete_Number_clicked();
    void onOpen_clicked();
    void onShow_All_clicked();
    void onFindBy_Telephone_Number_clicked();
    void onAddCall_clicked();
    void onChangeCall_clicked();
    void onSort_clicked();
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    void showAll();
    bool openTaskFile(QString const& filePath);
    void saveToFile();
    void setEnabled(bool enabled);
    int countOfShowCalls();
private:
    Ui::MainWindow *ui;
    List ListOfCalls;
    QString currentFilePath;
};
#endif // MAINWINDOW_H
