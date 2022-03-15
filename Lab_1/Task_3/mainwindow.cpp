#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "date.h"
//#include "windowforinfo.h"
#include <QFile>
#include <QDir>
#include <QFileInfo>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QStandardItemModel>
#include <iostream>
#include <QDebug>
#include <QLabel>
#include <QInputDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::addItemstoBox(){
    QFile file(m_currentFilePath);
    QTextStream fileStream(&file);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        return;
    }

    QString text = fileStream.readAll();
    QStringList arrayOfDate = text.split("\n");

    ui->comboBox->clear();
    for(int i = 0; i < arrayOfDate.size(); ++i){
        QDate date = date.fromString(arrayOfDate[i],"dd.MM.yyyy");
        if(date.isValid()){
            ui->comboBox->addItem(arrayOfDate[i]);
        }
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open Document"), QDir::currentPath(), tr("Document files (*.txt)"));
    if (filePath.isEmpty()){
        return;
    }

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        return;
    }
    m_currentFilePath = filePath;
    QTextStream fileStream(&file);
    QString testLine;
    testLine = fileStream.readLine();
    while(!testLine.isNull()){
        QDate testDate = testDate.fromString(testLine,"dd.MM.yyyy");
        if(!testDate.isValid())
            return;
        testLine = fileStream.readLine();
    };

    fileStream.seek(0);
    QString text = fileStream.readAll();
    ui->plainTextEdit->setPlainText(text);
    ui->comboBox->setEnabled(true);
    addItemstoBox();
    //QString line = fileStream.readLine();
}
void MainWindow::on_pushButton_clicked()
{
    QFile file(m_currentFilePath);
    if(!file.open( QFile::Append| QFile::Text)){
        QMessageBox::warning(this,"title","file not open");
        return;
    }
    QTextStream out(&file);
    QString text = ui->lineEdit->text();
    QDate date = date.fromString(text,"dd.MM.yyyy");
    if(!date.isValid()){
        QMessageBox::warning(this,"title","date format is invalid");
    } else {
        out << endl << text;
        file.flush();
        ui->plainTextEdit->appendPlainText(text);
        file.close();
        QMessageBox::information(this,"title","date was added successfully!");
    }

    addItemstoBox();
}

void MainWindow::on_pushButton_6_clicked()
{

//    QString filePath = QFileDialog::getOpenFileName(this, tr("Open Document"), QDir::currentPath(), tr("Document files (*.txt)"));
//    if (filePath.isEmpty()){
//        return;
//    }

    QFile file(m_currentFilePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::warning(this,"title","file not open");
        return;
    }
    QTextStream fileStream(&file);
    QString testLine;
    testLine = fileStream.readLine();
    while(!testLine.isNull()){
        QDate testDate = testDate.fromString(testLine,"dd.MM.yyyy");
        if(!testDate.isValid())
            return;
        testLine = fileStream.readLine();
    };

    fileStream.seek(0);
    QString line = fileStream.readLine();
    int count = 0;
    while(!line.isNull()){
        ++count;
        line = fileStream.readLine();
    }

    QTableView* view = ui->tableView;
    view->setShowGrid(true);
    QStandardItemModel* model = new QStandardItemModel();
    QStringList labels = QObject::trUtf8("Next day, Difference").simplified().split(",");
    model->setHorizontalHeaderLabels(labels);
    fileStream.seek(0);
    QString text = fileStream.readAll();
    QStringList VertLabels = QObject::trUtf8(text.toStdString().c_str()).simplified().split(" ");
    model->setVerticalHeaderLabels(VertLabels);

    QStringList arrayOfDate = text.split("\n");
    QStandardItem* item = 0;
    QDate temp;
    for(int i = 0;i < count;i++){
        temp = temp.fromString(arrayOfDate[i],"dd.MM.yyyy");
            item = new QStandardItem(temp.addDays(1).toString("dd.MM.yyyy"));
            model->setItem(i,0,item);

            QDate nextDate;
            if(i == count - 1 )
                nextDate = nextDate.fromString(arrayOfDate[0],"dd.MM.yyyy");
             else
                nextDate = nextDate.fromString(arrayOfDate[i + 1],"dd.MM.yyyy");
            int differens = temp.daysTo(nextDate);
            item = new QStandardItem(QString("%1").arg(differens));
            model->setItem(i,1,item);
        }

    ui->tableView->setModel(model);
    ui->tableView->show();
}

int activeIndex;
void MainWindow::on_pushButton_2_clicked()
{
    const int format = 11;
    QFile file(m_currentFilePath);
    if(!file.open( QFile::ReadWrite| QFile::Text)){
        QMessageBox::warning(this,"title","file not open");
        return;
    }

    QTextStream fileStream(&file);
    QString text = fileStream.readAll();
    QStringList arrayOfDate = text.split("\n");

    QString newDate = ui->lineEdit_5->text();
    bool isItInTheFile = false;
    for(int i = 0;i < arrayOfDate.size(); ++i){
        if(arrayOfDate[i].compare(newDate) == 0){
            isItInTheFile = true;
            break;
        }
    }

    if(isItInTheFile){
        QMessageBox::warning(this,"title","This date already exists in the file");
    } else{
        if (ui->comboBox->isActiveWindow()){
            QDate date = date.fromString(newDate,"dd.MM.yyyy");
            if(!date.isValid()){
                QMessageBox::warning(this,"title","date format is invalid");
            } else {
                if(activeIndex > 2){
                    fileStream.seek(format * activeIndex + (activeIndex - 2));
                } else {
                    fileStream.seek(format * activeIndex);
                }
                if(activeIndex == 0){
                    fileStream << newDate;
                } else {
                    fileStream << endl << newDate;}
                    file.flush();
                    file.close();
                    QMessageBox::information(this,"title","date was updated successfully!");
                }
            addItemstoBox();
        }
    }
    file.open(QFile::ReadWrite| QFile::Text);
    fileStream.seek(0);
    QString Info = fileStream.readAll();
    ui->plainTextEdit->setPlainText(Info);
    file.close();
}

void MainWindow::on_comboBox_activated(int index)
{
     activeIndex = index;
}


void MainWindow::on_pushButton_4_clicked()
{
//    QString Strngdate = ui->lineEdit_3-> text();
//    QDate date = date.fromString(Strngdate, "dd.MM.yyyy");
//    Date myDate(date.day(), date.month(), date.year());

//    if(!date.isNull()){
//        NewWidget * w = new NewWidget(this);
//        QString text = "Date: " + Strngdate + "\n" + "Next day: "  + myDate.NextDay().toString() + "/n" + "Previous day: " + myDate.PreviousDay().toString() +"\n" + "Leap year: " + myDate.isLeap() + "\n" + "Week number: " + myDate.WeekNumber() + "\n" + "Number of days to the current date" + myDate.Dutation(myDate);
//        QLabel *label = new QLabel(tr(text.toStdString().c_str()));
//        w->set;
//        //w->textEdit->setText(text);
//        //textEdit->setText(text);
//        w->show();
//    }
    QString Strngdate = ui->lineEdit_3-> text();
    QDate date = date.fromString(Strngdate, "dd.MM.yyyy");
    if(Strngdate == ""){
        QMessageBox::warning(this,"title","Invalid date!");
        return;
    }
    if(!date.isValid()){
        QMessageBox::warning(this,"title","Invalid date!");
        return;
    }
    WindowForInfo* newWindow = new WindowForInfo(this);
    QVBoxLayout *vlayout = new QVBoxLayout;
    newWindow->setFixedSize(300,300);
    Date myDate(date.day(), date.month(), date.year());
    QDate curDate = curDate.currentDate();

//    bool ok;
//        QString textor = QInputDialog::getText(this, tr("QInputDialog::getText()"),
//                                             tr("Enter your Birthday:"), QLineEdit::Normal,
//                                             QDir::home().dirName(), &ok);
//    QDate test = test.fromString(textor, "dd.MM.yyyy");
//    while (ok && !test.isValid()){
//        QMessageBox::warning(this,"title","date format is invalid");
//        textor = QInputDialog::getText(this, tr("QInputDialog::getText()"),
//                                                     tr("Enter your Birthday:"), QLineEdit::Normal,
//                                                     QDir::home().dirName(), &ok);
//    }
    QString text = "Date: " + Strngdate + "\n" + "Next day: " + myDate.NextDay(myDate).toString("dd.MM.yyyy") + "\n" + "Previous day: " + myDate.PreviousDay(myDate).toString("dd.MM.yyyy") +"\n" + "Leap year: " + QVariant(myDate.isLeap(myDate)).toString() + "\n" + "Week number: " + QString::number(myDate.WeekNumber(myDate)) + "\n" + "Number of days to the current date: " + QString::number((curDate.daysTo(date)));
    QLabel *label = new QLabel(text);
    vlayout->addWidget(label);
    newWindow->setModal(true);
    newWindow->setLayout(vlayout);
    newWindow->show();

    /*QVBoxLayout *vlayout = new QVBoxLayout;
    Dblack->setFixedSize(300,280);
    QLabel *label = new QLabel("Copy Right @ UESTC-CCSE wytk2008.net");
    QAbstractButton *bExit = new QPushButton("back");
    vlayout->addWidget(label);
    vlayout->addWidget(bExit);
    Dblack->setLayout(vlayout);
    Dblack->show();*/
}


void MainWindow::on_pushButton_5_clicked()
{
    QString textor = ui->lineEdit_4-> text();
    QDate test = test.fromString(textor, "dd.MM.yyyy");
    Date myDate(test.day(), test.month(), test.year());
    if(!test.isValid()){
        QMessageBox::warning(this,"title","date format is invalid");
    } else{
        int days = myDate.DaysTillYourBithday(myDate);

    WindowForInfo* newWindow = new WindowForInfo(this);
    QVBoxLayout *vlayout = new QVBoxLayout;
    newWindow->setFixedSize(300,100);
    QString text = "Days till your Bithday: \n" + QString::number(days);
    QLabel *label = new QLabel(text);
    vlayout->addWidget(label);
    newWindow->setModal(true);
    newWindow->setLayout(vlayout);
    newWindow->show();
    }
}

