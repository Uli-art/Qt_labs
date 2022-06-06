#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QMessageBox>
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

void MainWindow::onClear_clicked(){
    test.clear();
    print();
}

void MainWindow::onContains_clicked(){
    bool ok;
    int element = QInputDialog::getInt(this, tr("QInputDialog::getText()"),
                                             tr("Key:"),
                                             25, 0, 100,1, &ok);
    if (ok){
        QMessageBox msgBox;
        if(test.contains(element)){
            msgBox.setText("true");
        } else {
            msgBox.setText("false");
        }
        msgBox.exec();
    }
}

void MainWindow::onInsert_clicked(){
    bool ok;
    int element = QInputDialog::getInt(this, tr("QInputDialog::getText()"),
                                             tr("Key:"),
                                             25, 0, 100,1, &ok);
    if (ok){
        std::pair<typename Set<int>::iterator, bool> it = test.insert(element);
        QMessageBox msgBox;
        if(it.second){
            msgBox.setText("Successfully added");
        } else {
            msgBox.setText("Element with such key already exists");
        }
        msgBox.exec();

    }
    print();
}

void MainWindow::onDelete_clicked(){
    bool ok;
    int element = QInputDialog::getInt(this, tr("QInputDialog::getText()"),
                                             tr("Key:"),
                                             25, 0, 100,1, &ok);
    if (ok){
        test.erase(test.find(element));
    }
    print();
}

void MainWindow::print(){
    ui->textEdit->setText(test.toString());
}
