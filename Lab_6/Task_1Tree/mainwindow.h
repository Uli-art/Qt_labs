#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QTreeWidgetItem>
#include <QMainWindow>
#include "node.h"
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
    void addTreeRoot(Node* root);
    void addTreeChild(QTreeWidgetItem *parent, QString description,
                          Node* root);
    int count(Node* root);
private slots:
    void onAdd_clicked();
    void onFind_clicked();
    void onDelete_clicked();
    void onInorder_clicked();
    void onPreorder_clicked();
    void onPostorder_clicked();
    void onCount_clicked();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
