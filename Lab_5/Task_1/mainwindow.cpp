#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include "queue.h"
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
Queue<int> q;
void MainWindow::print(){
    ui->textEdit->clear();
    if(q.size() != 0){
        ui->textEdit->append("First element: " + QString::number(q.front()));
        ui->textEdit->append("Last element: " + QString::number(q.back()));
    }
    ui->textEdit->append("Size: " + QString::number(q.size()));
}
void MainWindow::onPush_clicked(){
    bool ok;
    int element = QInputDialog::getInt(this, tr("QInputDialog::getText()"),
                                             tr("Element:"),
                                             25, 0, 100,1, &ok);
    if (ok){
        q.push(element);
    }
    print();
}
void MainWindow::onPop_clicked(){
    q.pop();
    print();
}
