#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "deque.h"
#include <QInputDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

Deque<int> deque;
void MainWindow::print(){
    ui->textEdit->clear();
    QString info;
    for(int i = 0;i < deque.size(); ++i){
        info += QString::number(deque[i]) + " ";
    }
    ui->textEdit->append(info);
    ui->textEdit->append("Size: " + QString::number(deque.size()));
}
void MainWindow::onPush_back_clicked(){
    bool ok;
    int element = QInputDialog::getInt(this, tr("QInputDialog::getText()"),
                                             tr("Element:"),
                                             25, 0, 100,1, &ok);
    if (ok){
        deque.push_back(element);
    }
    print();
}
void MainWindow::onPush_front_clicked(){
    bool ok;
    int element = QInputDialog::getInt(this, tr("QInputDialog::getText()"),
                                             tr("Element:"),
                                             25, 0, 100,1, &ok);
    if (ok){
        deque.push_front(element);
    }
    print();
}
void MainWindow::onPop_back_clicked(){
    deque.pop_back();
    print();
}
void MainWindow::onPop_front_clicked(){
    deque.pop_front();
    print();
}
void MainWindow::onClear_clicked(){
    deque.clear();
    print();
}
void MainWindow::onResize_clicked(){
    bool ok;
    int element = QInputDialog::getInt(this, tr("QInputDialog::getText()"),
                                             tr("Element:"),
                                             25, 0, 100,1, &ok);
    if (ok){
        deque.resize(element);
    }
    print();
}
