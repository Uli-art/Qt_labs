#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "list.h"
#include <QDebug>
#include <QPoint>
#include <QWheelEvent>
#include <QScrollArea>
#include <QPlainTextEdit>
#include <QScrollBar>
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

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    List f;
    QString text = ui->textEdit->toPlainText();
    QStringList splitText = text.split("\n");
    for(int i = 0; i< splitText.size(); ++i){
        f.add(splitText[i]);
    }
    f.makeCircle();
    Node* start = f.getHead();
    for(int i = 0; i < arg1; ++i){
        start = start->next;
    }
    QList<QTextEdit::ExtraSelection> extraSelections;
    if(ui->textEdit->textCursor().atEnd()){
        ui->textEdit->moveCursor(QTextCursor::Start);
    } else{
        ui->textEdit->moveCursor(QTextCursor::NextBlock);
    }
    ui->textEdit->find(start->data);
    {
        QTextEdit::ExtraSelection extra;
        extra.cursor = ui->textEdit->textCursor();
        extraSelections.append(extra);
    }

    ui->textEdit->setExtraSelections(extraSelections);
    ui->lineEdit->setText(start->data);
}

