#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../HeaderOnlyLibVector/vector.h"
#include <QInputDialog>
#include <QDir>
#include "insertdialog.h"
#include "emplacedialog.h"
#include "assigndialog.h"
#include "swapdialog.h"
#include "erasedialog.h"
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

vector<int> test;

void MainWindow::showInfo(){
    ui->size->clear();

    ui->size->append("Size: " + QString::number(test.size()));
    ui->size->append("Capacity: : " + QString::number(test.capacity()));
    ui->size->append("Is vector empty: " + test.empty());
    ui->size->append("Max_size: " + QString::number(test.max_size()));

    QString vec = "{ ";
    for(int i = 0; i < test.size(); ++i){
        vec += QString::number(test[i]) + ", ";
    }
    vec += " }";
    ui->vector->setText(vec);
}

void MainWindow::onEmplace_back_clicked(){
    bool ok;
    int element = QInputDialog::getInt(this, tr("QInputDialog::getText()"),
                                             tr("Element:"),
                                             25, 0, 100,1, &ok);
    if (ok){
        test.emplace_back(element);
    }
    showInfo();
}

void MainWindow::onPush_back_clicked(){
    bool ok;
    int element = QInputDialog::getInt(this, tr("QInputDialog::getText()"),
                                             tr("Element:"),
                                             25, 0, 100,1, &ok);
    if (ok){
        test.emplace_back(element);
    }
    showInfo();
}

void MainWindow::onInsert_clicked(){
    InsertDialog insertdialog(this);
    if (insertdialog.exec() == QDialog::Accepted)
    {
        int el = insertdialog.getElement();
        int pos = insertdialog.getPosition();
        test.insert(test.begin() + pos, el);
    }
    showInfo();
}

void MainWindow::onPop_back_clicked(){
    test.pop_back();
    showInfo();
}

void MainWindow::onReserve_clicked(){
    bool ok;
    int element = QInputDialog::getInt(this, tr("QInputDialog::getText()"),
                                             tr("Element:"),
                                             25, 0, 100,1, &ok);
    if (ok){
        test.reserve(element);
    }
    showInfo();
}

void MainWindow::onResize_clicked(){
    bool ok;
    int element = QInputDialog::getInt(this, tr("QInputDialog::getText()"),
                                             tr("Element:"),
                                             25, 0, 100,1, &ok);
    if (ok){
        test.resize(element);
    }
    showInfo();
}

void MainWindow::onEmplace_clicked(){
    EmplaceDialog emplacedialog(this);
    if (emplacedialog.exec() == QDialog::Accepted)
    {
        int el = emplacedialog.getElement();
        int pos = emplacedialog.getPosition();
        test.emplace(test.cbegin() + pos, el);
    }
    showInfo();
}

void MainWindow::onAssign_clicked(){
    AssignDialog assigndialog(this);
    if (assigndialog.exec() == QDialog::Accepted)
    {
        int first = assigndialog.getFirst();
        int last = assigndialog.getLast();
        test.assign(test.begin() + first, test.begin() + last);
    }
    showInfo();
}

void MainWindow::onSwap_clicked(){
    SwapDialog swapdialog(this);
    if (swapdialog.exec() == QDialog::Accepted)
    {
        QString line = swapdialog.getLine();
        QStringList el= line.split(" ");
        vector<int> newVec(el.size());
        for(int i= 0;i < el.size(); ++i){
            int newEl = el[i].toInt();
            newVec.push_back(newEl);
        }
        test.swap(newVec);
    }
    showInfo();
}

void MainWindow::onClear_clicked(){
    test.clear();
    showInfo();
}

void MainWindow::onErase_clicked(){
    EraseDialog erasedialog(this);
    if (erasedialog.exec() == QDialog::Accepted)
    {
        int first = erasedialog.getFirst();
        int last = erasedialog.getLast();
        test.erase(test.cbegin() + first, test.cbegin() + last);
    }
    showInfo();
}
