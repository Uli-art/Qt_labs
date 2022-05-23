#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stack.h"
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>
#include <QColorDialog>
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


void MainWindow::onOpen_clicked(){
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open Document"), QDir::currentPath(), tr("Document files (*.txt)"));
    if (filePath.isEmpty()){
        return;
    }
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }
    currentFilePath = filePath;
    QString textFromFile = file.readAll();
    file.close();
    ui->textEdit->setText(textFromFile);
}

int MainWindow::Check(){
    stack.clear();
    stack2.clear();
    QString allText = ui->textEdit->toPlainText();
    QStringList strList = allText.split('\n');
    for(int i = 0; i < strList.size(); ++i){
        for(int j = 0; j < strList.at(i).size(); ++j){
            if(strList.at(i)[j] == '[' || strList.at(i)[j] == '(' || strList.at(i)[j] == '{'){
                stack.push(strList.at(i)[j], i,j);
            }
            else if(strList.at(i)[j] == ']' || strList.at(i)[j] == ')' || strList.at(i)[j] == '}'){
                if(stack.getSize() == 0 || strList.at(i)[j] != getPair(stack.getHead())){
                    stack2.push(strList.at(i)[j],i,j);
                    return i;
                }
                stack.pop();
            }
        }
    }
    if(stack.getSize() != 0){
        for(int i = 0; i < stack.getSize() - 1; ++i){
            stack.pop();
        }
        return stack.getHeadIndex();
    }
    return -1;
}

void MainWindow::on_check_clicked()
{
    QString allText = ui->textEdit->toPlainText();
    int result = Check();
    if(result == -1){  
        QTextCharFormat fmt = ui->textEdit->currentCharFormat();
        //fmt.setForeground(QBrush("#AFFAAD"));
        fmt.setForeground(QBrush(Qt::black));
        QPalette p = ui->textEdit->palette();
        p.setColor(QPalette::Base,"#D0FFCE");
        ui->textEdit->setPalette(p);
        fmt.setBackground(QBrush("#AFFAAD"));
        ui->textEdit->setCurrentCharFormat(fmt);
        ui->textEdit->setText(allText);
        ui->statusbar->clearMessage();
    } else{
        QPalette p = ui->textEdit->palette();
        p.setColor(QPalette::Base, Qt::white);
        ui->textEdit->setPalette(p);
        QStringList strList = allText.split('\n');
        ui->textEdit->clear();

        QTextCharFormat fmt = ui->textEdit->currentCharFormat();
        fmt.setBackground(QBrush(Qt::white));
        ui->textEdit->setCurrentCharFormat(fmt);

        for(int i = 0; i < result; ++i){
            ui->textEdit->append(strList[i]);
        }

        fmt = ui->textEdit->currentCharFormat();
        fmt.setBackground(QBrush("#FB8686"));
        ui->textEdit->setCurrentCharFormat(fmt);
        ui->textEdit->append(strList[result]);

        fmt.setForeground(QBrush(Qt::black));
        fmt.setBackground(QBrush(Qt::white));
        ui->textEdit->setCurrentCharFormat(fmt);

        for(int i = result + 1; i < strList.size(); ++i){
            ui->textEdit->append(strList[i]);
        }
        if(stack2.getSize() != 0){
            ui->statusbar->showMessage(QString("Row: %1, Column: %2").arg(stack2.getHeadIndex() + 1).arg(stack2.getHeadSecIndex() + 1));
        } else{
             ui->statusbar->showMessage(QString("Row: %1, Column: %2").arg(stack.getHeadIndex() + 1).arg(stack.getHeadSecIndex() + 1));
        }
    }
}
//AFFAAD
QString MainWindow::getPair(QString braket){
    if(braket == "(")
        return ")";
    if(braket == "[")
        return "]";
    return "}";
}

// ({)}
