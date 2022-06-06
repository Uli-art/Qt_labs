#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "map.h"
#include "adddialog.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QTreeWidgetItem>
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

Map<int, int> test;

void MainWindow::onAdd_clicked(){
    AddDialog adddialog(this);
    if (adddialog.exec() == QDialog::Accepted)
    {
        int key = adddialog.getKey();
        int value = adddialog.getValue();
        std::pair<int, int> temp = std::make_pair(key,value);
        test.insert(temp);
    }
    print();
}

void MainWindow::onFind_clicked(){
    bool ok;
    int element = QInputDialog::getInt(this, tr("QInputDialog::getText()"),
                                             tr("Key:"),
                                             25, 0, 100,1, &ok);
    if (ok){
        QMessageBox msgBox;
        Map<int, int>::iterator it = test.find(element);
        if(it != test.end()) {
            msgBox.setText(QString::number(*it));
        } else {
            msgBox.setText("Element not found");
        }
        msgBox.exec();
    }
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
void MainWindow::onSize_clicked(){
    QMessageBox msgBox;
    msgBox.setText(QString::number(test.size()));
    msgBox.exec();
}

void MainWindow::onClear_clicked(){
    test.clear();
    print();
}

void MainWindow::print(){
    ui->treeWidget->clear();
    QList<QTreeWidgetItem *> items;
    int i = 0;
    for(Map<int, int>::iterator it = test.begin(); it != test.end(); ++it){
        QTreeWidgetItem* item = new QTreeWidgetItem(QStringList() << QString::number(it.getKey()) << QString::number(*it));
        item->setData(0, Qt::UserRole, QVariant(i));
        ++i;
        items.append(item);
    }
    ui->treeWidget->insertTopLevelItems(0, items);
}
