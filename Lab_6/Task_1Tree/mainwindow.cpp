#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "searchtree.h"
#include "additem.h"
#include <QMessageBox>
#include <QInputDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    print();
}

MainWindow::~MainWindow()
{
    delete ui;
}

SearchTree test;

void MainWindow::onAdd_clicked(){
    AddItem adddialog(this);
    if (adddialog.exec() == QDialog::Accepted)
    {
        int key = adddialog.getKey();
        QString data = adddialog.getData();
        test.addItem(key, data);
    }
    print();
}
void MainWindow::onFind_clicked(){
    bool ok;
    int element = QInputDialog::getInt(this, tr("QInputDialog::getText()"),
                                             tr("Key:"),
                                             25, 0, 100,1, &ok);
    if (ok){
        QString result;
        bool IsFind = test.find(element, result);
        if(IsFind){
            QMessageBox msgBox;
            msgBox.setText(result);
            msgBox.exec();
        }
    }
}
void MainWindow::onDelete_clicked(){
    bool ok;
    int element = QInputDialog::getInt(this, tr("QInputDialog::getText()"),
                                             tr("Key:"),
                                             25, 0, 100,1, &ok);
    if (ok){
        test.deleteItem(element);
    }
    print();
}
void MainWindow::onInorder_clicked(){
    QString inorder = test.traverseInorder(test.getRoot());
    QMessageBox msgBox;
    msgBox.setText(inorder);
    msgBox.exec();
}
void MainWindow::onPreorder_clicked(){
    QString inorder = test.traversePreorder(test.getRoot());
    QMessageBox msgBox;
    msgBox.setText(inorder);
    msgBox.exec();
}
void MainWindow::onPostorder_clicked(){
    QString inorder = test.traversePostorder(test.getRoot());
    QMessageBox msgBox;
    msgBox.setText(inorder);
    msgBox.exec();
}

void MainWindow::print(){
    ui->treeWidget->clear();
    ui->treeWidget->setColumnCount(3);
    if(test.getRoot() != nullptr){
        addTreeRoot(test.getRoot());
        ui->treeWidget->expandAll();
    }

}

void MainWindow::addTreeRoot(Node* root)
{
    // QTreeWidgetItem(QTreeWidget * parent, int type = Type)
    QTreeWidgetItem *treeItem = new QTreeWidgetItem(ui->treeWidget);

    // QTreeWidgetItem::setText(int column, const QString & text)
    if(root){
        treeItem->setText(0, "root");
        treeItem->setText(1, QString::number(root->getKey()));
        treeItem->setText(2, root->getValue());

        if(root->getLeft() != nullptr)
            addTreeChild(treeItem, "left",root->getLeft());
        if(root->getRight() != nullptr)
            addTreeChild(treeItem, "right", root->getRight());
    }
}

void MainWindow::addTreeChild(QTreeWidgetItem *parent, QString description,
                              Node* root)
{
    // QTreeWidgetItem(QTreeWidget * parent, int type = Type)
    QTreeWidgetItem *treeItem = new QTreeWidgetItem();

    // QTreeWidgetItem::setText(int column, const QString & text)
    treeItem->setText(0, description);
    treeItem->setText(1, QString::number(root->getKey()));
    treeItem->setText(2, root->getValue());

    // QTreeWidgetItem::addChild(QTreeWidgetItem * child)
    parent->addChild(treeItem);
    if(root->getLeft() != nullptr)
        addTreeChild(treeItem, "left", root->getLeft());
    if(root->getRight() != nullptr)
        addTreeChild(treeItem, "right", root->getRight());
     return;
}

void MainWindow::onCount_clicked(){
    int c = count(test.getRoot());
    QMessageBox msgBox;
    msgBox.setText(QString::number(c));
    msgBox.exec();
}

int MainWindow::count(Node* root){
    int res = 0;
    if(!root) return res;
    if (root->getLeft())
        res += count(root->getLeft());

    if((!root->getLeft() && root->getRight()) || (root->getLeft() && !root->getRight()))
        res += 1;

    if (root->getRight()){
         res += count(root->getRight());
    }
    return res;
}
