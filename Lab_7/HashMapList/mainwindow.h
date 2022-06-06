#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "hashmap_list.h"

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
    void clearPushButtonClicked();
    void rehashPushButtonClicked();

private:
    Ui::MainWindow *ui;
    typedef HashMapList<int, QString> HashTable;
    HashTable _hashTable;
};
#endif // MAINWINDOW_H
