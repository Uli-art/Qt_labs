#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "hashmap_stack.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void refreshHashTable();
    void insertPushButtonClicked();
    void getPushButtonClicked();
    void erasePushButtonClicked();
    void containsPushButtonClicked();
    void generatePushButtonClicked();
    void extractPushButtonClicked();

private:
    Ui::MainWindow *ui;
    typedef HashMapStack<int, QString> HashTable;
    HashTable _hashTable;
};
#endif // MAINWINDOW_H
