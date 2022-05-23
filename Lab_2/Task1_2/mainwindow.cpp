#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calls.h"
#include "addcall.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QInputDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::showAll(){
    ui->treeWidget->clear();
    ui->treeWidget->setColumnCount(0);
    ui->treeWidget->setHeaderLabels(QStringList() << "Date Of Call" << "Code Of City" << "City" << "Time" << "Rate" << "Phone Number City" << "Subscriber's Phone Number");
    QList<QTreeWidgetItem *> items;
    for(int i = 0; i < ListOfCalls.getSize(); ++i){
        Node* array = ListOfCalls.getArray();
        Calls call = array[i].call;
        if(array[i].show){
            QTreeWidgetItem* item = new QTreeWidgetItem(QStringList() << call.getDateOfCall().toString("dd.MM.yyyy") << QString::number(call.getCodeOfCity()) << call.getCity() << call.getTime().toString("HH:mm:ss") << call.getRate() << call.getPhoneNumberCity() << call.getPhoneNumber() );
            item->setData(0, Qt::UserRole, QVariant(i));
            items.append(item);
        }
    }
    ui->treeWidget->insertTopLevelItems(0, items);
}
bool MainWindow::openTaskFile(QString const& filePath){
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return false;
    }

    QTextStream fileStream(&file);

    QString testLine;
    testLine = fileStream.readLine().trimmed();
    int count = 0;
    int seven = 0;
    while(!testLine.isNull()){
        if(seven < 7) {
            ++seven;
        } else {
            seven = 0;
            ++count;
        }
        int i = 0;
        switch (seven) {
        case 1:{
            QDate d = QDate::fromString(testLine, "dd.MM.yyyy");
            if (!d.isValid()) return false;
            break;}
        case 2:{
            while (i != testLine.size()) {
            if (!testLine[i].isNumber()) return false;
            ++i;
            }
            break;}
        case 3:{
            while (i != testLine.size()) {
            if (!testLine[i].isLetter()) return false;
            ++i;
            }
            break;
        }
        case 4:{
            QTime time = QTime::fromString(testLine, "HH:mm:ss");
            if(!time.isValid()) return false;
            break;
        }
        case 5:{
            break;
        }
        case 6:
            while (i != testLine.size()) {
                if (testLine[i].isLetter()) return false;
                ++i;
            }
            if (testLine.size() != 17) return false;
            break;
        case 7:
            while (i != testLine.size()) {
                if (testLine[i].isLetter()) return false;
                ++i;
            }
            if (testLine.size() != 17) return false;
            break;
        }
        testLine = fileStream.readLine().trimmed();
    }
   // if(count != 0) ++count;

    fileStream.seek(0);
    file.seek(0);
    ListOfCalls.clear();
    for(int i = 0; i < count; ++i){
        QString dateOfCall = file.readLine().trimmed();
        QString codeOfCity = file.readLine().trimmed();
        QString city = file.readLine().trimmed();
        QString time= file.readLine().trimmed();
        QString rate= file.readLine().trimmed();
        QString phoneNumberCity = file.readLine().trimmed();
        QString phoneNumber = file.readLine().trimmed();
        QDate date;
        QTime qtime;
        Calls newCall(date.fromString(dateOfCall, "dd.MM.yyyy"), codeOfCity.toInt(), city,qtime.fromString(time,"HH:mm:ss"),rate,phoneNumberCity,phoneNumber);
        ListOfCalls.addCall(newCall);
        file.readLine();
    }
    return true;
}
void MainWindow::saveToFile(){
    QFile file(currentFilePath);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    for(int i = 0; i < ListOfCalls.getSize();++i){
        Calls call = ListOfCalls.getArray()[i].call;
        if(ListOfCalls.getArray()[i].show){
            out << call.getDateOfCall().toString("dd.MM.yyyy") << "\n" << QString::number(call.getCodeOfCity()) << "\n" << call.getCity() << "\n" << call.getTime().toString("HH:mm:ss") << "\n" << call.getRate() << "\n" << call.getPhoneNumberCity() << "\n" << call.getPhoneNumber()<< "\n\n" ;
        }
    }
}
void MainWindow::onFindBy_City_clicked(){
    QStringList items;
    for(int i = 0;i < ListOfCalls.getSize(); ++i){
        if(ListOfCalls.getArray()[i].show){
            items << tr(ListOfCalls.getArray()[i].call.getCity().toStdString().c_str());
        }
    }
    items.removeDuplicates();
       bool ok;
       QString item = QInputDialog::getItem(this, tr("Choose city"),
                                            tr("City:"), items, 0, false, &ok);
    if (ok && !item.isEmpty()){
        ui->treeWidget->clear();
        ui->treeWidget->setColumnCount(0);
        ui->treeWidget->setHeaderLabels(QStringList() << "Date Of Call" << "Code Of City" << "City" << "Time" << "Rate" << "Phone Number City" << "Subscriber's Phone Number");
        QList<QTreeWidgetItem *> items;
        for(int i = 0; i < ListOfCalls.getSize(); ++i){
            if(ListOfCalls.getArray()[i].call.getCity() == item){
                Node* array = ListOfCalls.getArray();
                Calls call = array[i].call;
                if(array[i].show){
                    QTreeWidgetItem* item = new QTreeWidgetItem(QStringList() << call.getDateOfCall().toString("dd.MM.yyyy") << QString::number(call.getCodeOfCity()) << call.getCity() << call.getTime().toString("HH:mm:ss") << call.getRate() << call.getPhoneNumberCity() << call.getPhoneNumber() );
                    item->setData(0, Qt::UserRole, QVariant(i));
                    items.append(item);
                 }
                ui->treeWidget->insertTopLevelItems(0, items);
            }
        }
    }
}
void MainWindow::onDelete_Number_clicked(){
    QStringList items;
    for(int i = 0;i < ListOfCalls.getSize(); ++i){
        if(ListOfCalls.getArray()[i].show){
            items << tr(ListOfCalls.getArray()[i].call.getPhoneNumber().toStdString().c_str());
        }
    }
    items.removeDuplicates();
    if(items.size() != 0){
        bool ok;
        QString item = QInputDialog::getItem(this, tr("Choose number"),
                                            tr("Number:"), items, 0, false, &ok);
        if (ok && !item.isEmpty()){
            for(int i = 0; i < ListOfCalls.getSize(); ++i){
                if(ListOfCalls.getArray()[i].call.getPhoneNumber() == item){
                    ListOfCalls.deleteCall(i);
                }
            }
            showAll();
            saveToFile();
        }
    }
}
void MainWindow::onOpen_clicked(){
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open Document"), QDir::currentPath(), tr("Document files (*.txt)"));
    if (filePath.isEmpty()){
        return;
    }

    if (!openTaskFile(filePath))
    {
        QMessageBox::critical(this, "Open Task File", "Failed to open task file");
        return;
    }

    currentFilePath = filePath;

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }
    setEnabled(true);
    showAll();
}
void MainWindow::onShow_All_clicked(){
    showAll();
}
void MainWindow::onFindBy_Telephone_Number_clicked(){
    QStringList items;
    for(int i = 0;i < ListOfCalls.getSize(); ++i){
        if(ListOfCalls.getArray()[i].show){
            items << tr(ListOfCalls.getArray()[i].call.getPhoneNumber().toStdString().c_str());
        }
    }
    items.removeDuplicates();
       bool ok;
       QString item = QInputDialog::getItem(this, tr("Choose number"),
                                            tr("Number:"), items, 0, false, &ok);
    if (ok && !item.isEmpty()){
        ui->treeWidget->clear();
        ui->treeWidget->setColumnCount(0);
        ui->treeWidget->setHeaderLabels(QStringList() << "Date Of Call" << "Code Of City" << "City" << "Time" << "Rate" << "Phone Number City" << "Subscriber's Phone Number");
        QList<QTreeWidgetItem *> items;
        for(int i = 0; i < ListOfCalls.getSize(); ++i){
            if(ListOfCalls.getArray()[i].call.getPhoneNumber() == item){
                Node* array = ListOfCalls.getArray();
                Calls call = array[i].call;
                if(array[i].show){
                    QTreeWidgetItem* item = new QTreeWidgetItem(QStringList() << call.getDateOfCall().toString("dd.MM.yyyy") << QString::number(call.getCodeOfCity()) << call.getCity() << call.getTime().toString("HH:mm:ss") << call.getRate() << call.getPhoneNumberCity() << call.getPhoneNumber() );
                    item->setData(0, Qt::UserRole, QVariant(i));
                    items.append(item);
                 }
                ui->treeWidget->insertTopLevelItems(0, items);
            }
        }
    }
}

void  MainWindow::onSort_clicked(){
    if(ListOfCalls.getSize() == 0 || ListOfCalls.getSize() == 1){
        return;
    }
    for(int i = 0; i < ListOfCalls.getSize() - 1; ++i){
        for(int j = 0;j < ListOfCalls.getSize() - i - 1;++j){
            if(ListOfCalls.getArray()[j].call.getDateOfCall() > ListOfCalls.getArray()[j + 1].call.getDateOfCall() ){
                Calls temp = ListOfCalls.getArray()[j].call;
                ListOfCalls.getArray()[j].call = ListOfCalls.getArray()[j + 1].call;
                ListOfCalls.getArray()[j + 1].call = temp;
            }

        }
    }
    showAll();
    saveToFile();
}
void MainWindow::onAddCall_clicked(){
    AddCall addcall(this);
    if (addcall.exec() == QDialog::Accepted){
        Calls call = addcall.getCall();
        ListOfCalls.addCall(call);
        saveToFile();
        ui->actionDelete_Phone_Number->setEnabled(true);
    }
    showAll();
}
void MainWindow::onChangeCall_clicked(){
    QTreeWidgetItem* item = ui->treeWidget->currentItem();
       if (item == nullptr)
       {
           return;
       }

     QVariant data = item->data(0, Qt::UserRole);
     if (data.isValid()){
         int const callIndex = data.toInt();
         AddCall addDialog(this);
         addDialog.setCurrentCall(ListOfCalls.getArray()[callIndex].call);
         if (addDialog.exec() == QDialog::Accepted){
             ListOfCalls.getArray()[callIndex].call = addDialog.getCall();
             showAll();
             saveToFile();
         }
     }
}

void MainWindow::setEnabled(bool enabled){
    ui->actionAdd_Call->setEnabled(enabled);
    ui->actionChange_Call->setEnabled(enabled);
    ui->actionCity->setEnabled(enabled);
    ui->actionDelete_Phone_Number->setEnabled(enabled);
    ui->actionShow_All->setEnabled(enabled);
    ui->actionTelephone_Number->setEnabled(enabled);
}
