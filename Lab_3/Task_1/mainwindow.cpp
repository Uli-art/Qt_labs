#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSharedPointer>
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
void MainWindow::showAll(){
     ui->treeWidget->clear();
    // ui->treeWidget->setSelectionMode(QAbstractItemView::MultiSelection);
     QList<QTreeWidgetItem *> items;
     for(int i = 0; i < shared.size(); ++i){
         QTreeWidgetItem* item = new QTreeWidgetItem(QStringList() << "shared_" + QString::number(i + 1) << "shared_ptr" << QString("0x%1").arg((quintptr)shared[i].get()) << QString::number(*shared[i]) << QString::number(shared[i].use_count()) << QString::number(shared[i].bp_count()) );
         item->setData(0, Qt::UserRole, QVariant(i));
         items.append(item);
     }
     for(int i = 0; i < weak.size();++i){
         if(weak[i].get() == nullptr){
             QTreeWidgetItem* item = new QTreeWidgetItem(QStringList() << "weak_" + QString::number(i + 1) << "weak_ptr"
                                                         << QString("0x%1").arg((quintptr)weak[i].get())
                                                         << "-" << "-" << "-" );
             item->setData(0, Qt::UserRole, QVariant(i));
             items.append(item);
             continue;
         }
         QTreeWidgetItem* item = new QTreeWidgetItem(QStringList() << "weak_" + QString::number(i + 1) << "weak_ptr"
                                                     << QString("0x%1").arg((quintptr)weak[i].get())
                                                     << QString::number(*weak[i]) << "-" << "-" );
         item->setData(0, Qt::UserRole, QVariant(i));
         items.append(item);
     }
     for(int i = 0; i < unique.size();++i){
         if(unique[i].get() == nullptr){
             QTreeWidgetItem* item = new QTreeWidgetItem(QStringList() << "unique_" + QString::number(i + 1) << "unique_ptr" << QString("0x%1").arg((quintptr)unique[i].get()) << "-" << "-" << "-" );
             item->setData(0, Qt::UserRole, QVariant(i));
             items.append(item);
             continue;
         }
         QTreeWidgetItem* item = new QTreeWidgetItem(QStringList() << "unique_" + QString::number(i + 1) << "unique_ptr" << QString("0x%1").arg((quintptr)unique[i].get()) << QString::number(*unique[i]) << "1" << "1" );

         item->setData(0, Qt::UserRole, QVariant(i));
         items.append(item);
     }
     ui->treeWidget->insertTopLevelItems(0, items);
}
void MainWindow::on_Addweak_clicked(){
    bool ok;
    int i = QInputDialog::getInt(this, tr("QInputDialog::getInt()"),
                                     tr("Value:"), 0, 0, 100, 1, &ok);
    if (ok){
        weak_ptr<int> sh_ptr(new int(i));
        weak.push_back(sh_ptr);
    }
    showAll();
}
void MainWindow::on_Addunique_clicked(){
    bool ok;
    int i = QInputDialog::getInt(this, tr("QInputDialog::getInt()"),
                                     tr("Value:"), 0, 0, 100, 1, &ok);
    if (ok){
        unique_ptr<int> sh_ptr(new int(i));
        unique.push_back(std::move(sh_ptr));
    }
    showAll();
}

void MainWindow::on_Addshared_clicked(){
    bool ok;
    int i = QInputDialog::getInt(this, tr("QInputDialog::getInt()"),
                                     tr("Value:"), 0, 0, 1000, 1, &ok);
    if (ok){
        shared_ptr<int> sh_ptr(new int(i));
        shared.push_back(sh_ptr);
    }
    showAll();

}

void MainWindow::on_Reset_clicked(){
    QTreeWidgetItem* item = ui->treeWidget->currentItem();
    if (item == nullptr)
    {
        return;
    }

    QVariant data = item->data(0, Qt::UserRole);
    if (data.isValid())
    {
        bool ok;
        int i = QInputDialog::getInt(this, tr("QInputDialog::getInt()"),
                                         tr("Value:"), 0, 0, 100, 1, &ok);
        int const index = data.toInt();
        if(item->text(1) == "shared_ptr"){
            if (ok){
                shared[index].reset(new int (i));
            }
        } else if(item->text(1) == "weak_ptr"){
            if (ok){
                weak[index].reset(new int (i));
            }
        } else {
            if (ok){
                unique[index].reset(new int (i));
            }
        }
    }
    showAll();
}
void MainWindow::on_Delete_clicked(){
    QTreeWidgetItem* item = ui->treeWidget->currentItem();
    if (item == nullptr)
    {
        return;
    }

    QVariant data = item->data(0, Qt::UserRole);
    if (data.isValid())
    {
        int const index = data.toInt();
        if(item->text(1) == "shared_ptr"){
            shared.erase(shared.begin() + index);

           // shared[index].~shared_ptr();


        } else if(item->text(1) == "weak_ptr"){
            weak.erase(weak.begin() + index);

            //weak[index].~weak_ptr();

        } else {
            //unique[index].~unique_ptr();
            unique.erase(unique.begin() + index);
        }
    }
    showAll();
}

void MainWindow::on_CopyFrom_clicked(){
    QTreeWidgetItem* item = ui->treeWidget->currentItem();
    if (item == nullptr)
    {
        return;
    }

    QVariant data = item->data(0, Qt::UserRole);
    if (data.isValid())
    {
        int const index = data.toInt();
        if(item->text(1) == "shared_ptr"){
            shared_ptr<int> f(shared[index]);
            shared.push_back(f);
            weak_ptr<int> f1(shared[index]);
            weak.push_back(f1);
        } else if(item->text(1) == "weak_ptr"){
            weak_ptr<int> f(weak[index]);
            weak.push_back(f);
        } else {
            unique_ptr<int> f(std::move(unique[index]));
            unique.push_back(std::move(f));
        }
    }
    showAll();
}

void MainWindow::on_Swap_clicked(){
    QTreeWidgetItem* item = ui->treeWidget->currentItem();
    if (item == nullptr)
    {
        return;
    }

    QVariant data = item->data(0, Qt::UserRole);
    if (data.isValid())
    {
        int const index = data.toInt();
        if(item->text(1) == "shared_ptr"){
            shared[0].swap(shared[index]);
        } else if(item->text(1) == "weak_ptr"){
            weak[0].swap(weak[index]);
        } else {
            unique[0].swap(unique[index]);
        }
    }
    showAll();
}
