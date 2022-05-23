#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QTreeWidgetItem>
#include "data.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private slots:
    void onAdd_clicked();
    void on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString convertToPost(QString infForm);
    bool isItNumber(QString element);
    int priorety(QString sing);
    double calculate(QString postForm, Data &data);
    void showAll();
    double decodingLetters(double array[], QString element);
    QStringList decoding(QString PostForm, Data &data);
    void setExpressions();
private:
    Ui::MainWindow *ui;
    QList<Data> expressions;
};
#endif // MAINWINDOW_H
