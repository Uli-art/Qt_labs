#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "String/string.h"

static int const MaxOutputBufferSize = 1024;

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

void MainWindow::onStrcpyCopyClicked(){
    char outputString[MaxOutputBufferSize];
    QByteArray sourceStringUtf8 = ui->strcpySourceLineEdit->text().toUtf8();
    int offset = ui->strcpyOffsetSpinBox->value();

    // check

    strfun::strcpy(outputString, sourceStringUtf8.constData() + offset);
    ui->strcpyOutputTextEdit->setText(QString::fromUtf8(outputString));
    ui->strcpyOutputTextEdit->append("Lenght: " + QString::number(strfun::strlen(outputString)));
}

void MainWindow::onStrncpyCopyClicked(){
    char outputString[MaxOutputBufferSize];
    QByteArray sourceStringUtf8 = ui->strncpySourceLineEdit->text().toUtf8();
    int offset = ui->strncpyOffsetSpinBox->value();

    // check

    strfun::strncpy(outputString, sourceStringUtf8.constData(),offset);
    ui->strncpyOutputTextEdit->setText(QString::fromUtf8(outputString));
}

void MainWindow::onMemcpyCopyClicked(){
    char outputString[MaxOutputBufferSize];
    QByteArray sourceStringUtf8 = ui->memcpySourceLineEdit->text().toUtf8();
    int offset = ui->memcpyOffsetSpinBox->value();

    // check

    strfun::memcpy(outputString, sourceStringUtf8.constData(),offset);
    ui->memcpyOutputTextEdit->setText(QString::fromUtf8(outputString));
}

void MainWindow::onStrcmpCompareClicked(){
    QByteArray sourceStringUtf81 = ui->strcmpFirstLineEdit->text().toUtf8();
    QByteArray sourceStringUtf82 = ui->strcmpSecondLineEdit->text().toUtf8();

    // check

    int result = strfun::strcmp(sourceStringUtf81.constData(), sourceStringUtf82.constData());
    ui->strcmpOutputTextEdit->setText(QString::number(result));
}

void MainWindow::onStrncmpCompareClicked(){
    QByteArray sourceStringUtf81 = ui->strncmpFirstLineEdit->text().toUtf8();
    QByteArray sourceStringUtf82 = ui->strncmpSecondLineEdit->text().toUtf8();
    int offset = ui->strncmpOffsetSpinBox->value();
    // check

    int result = strfun::strncmp(sourceStringUtf81.constData(), sourceStringUtf82.constData(),offset);
    ui->strncmpOutputTextEdit->setText(QString::number(result));
}

void MainWindow::onMemcmpCompareClicked(){
    QByteArray sourceStringUtf81 = ui->memcmpFirstLineEdit->text().toUtf8();
    QByteArray sourceStringUtf82 = ui->memcmpSecondLineEdit->text().toUtf8();
    int offset = ui->memcmpOffsetSpinBox->value();
    // check

    int result = strfun::memcmp(sourceStringUtf81.constData(), sourceStringUtf82.constData(),offset);
    ui->memcmpOutputTextEdit->setText(QString::number(result));
}

void MainWindow::onStrcatCompareClicked(){
    QByteArray sourceStringUtf81 = ui->strcatFirstLineEdit->text().toUtf8();
    QByteArray sourceStringUtf82 = ui->strcatSecondLineEdit->text().toUtf8();
    sourceStringUtf81.resize(sourceStringUtf82.size() + sourceStringUtf81.size());
    // check

    strfun::strcat(sourceStringUtf81.data(), sourceStringUtf82.constData());
    ui->strcatOutputTextEdit->setText(QString::fromUtf8(sourceStringUtf81.data()));
}

void MainWindow::onStrncatCompareClicked(){
    QByteArray sourceStringUtf81 = ui->strncatFirstLineEdit->text().toUtf8();
    QByteArray sourceStringUtf82 = ui->strncatSecondLineEdit->text().toUtf8();
    int offset = ui->strncatOffsetSpinBox->value();
    sourceStringUtf81.resize(sourceStringUtf81.size() + offset);
    // check

    strfun::strncat(sourceStringUtf81.data(), sourceStringUtf82.constData(), offset);
    ui->strncatOutputTextEdit->setText(QString::fromUtf8(sourceStringUtf81.data()));
}

void MainWindow::onMemmoveCopyClicked(){
    QByteArray sourceStringUtf8 = ui->memmoveSourceLineEdit->text().toUtf8();
    int offset = ui->memmoveOffsetSpinBox->value();
    int count = ui->memmoveCountSpinBox->value();

    strfun::memmove(sourceStringUtf8.data() + offset, sourceStringUtf8.constData(),count);
    ui->memmoveOutputTextEdit->setText(QString::fromUtf8(sourceStringUtf8.constData()));
 //   char* sourceStringUtf81 = static_cast<char*>(strfun::memcpy(sourceStringUtf8.data() + offset, sourceStringUtf8.constData(),count));
 //  ui->memmoveOutputTextEdit->append(QString::fromUtf8(sourceStringUtf81));
}

void MainWindow::onStrtokDivideClicked(){
    //char outputString[MaxOutputBufferSize];
    ui->strtokOutputTextEdit->clear();
    QByteArray sourceStringUtf8 = ui->strtokSourceLineEdit->text().toUtf8();
    QByteArray delitersStringUtf8 = ui->strtokDelitersLineEdit->text().toUtf8();
    // check
    char* ptr;
    ptr = strfun::strtok(sourceStringUtf8.data(), delitersStringUtf8.constData());
    while(ptr!=nullptr){
        ui->strtokOutputTextEdit->append(QString::fromUtf8(ptr));
        ptr = strfun::strtok(nullptr, delitersStringUtf8.constData());
    }
 //   char* sourceStringUtf81 = static_cast<char*>(strfun::memcpy(sourceStringUtf8.data() + offset, sourceStringUtf8.constData(),count));
 //  ui->memmoveOutputTextEdit->append(QString::fromUtf8(sourceStringUtf81));
}

void MainWindow::onMemsetSetClicked(){
    QByteArray sourceStringUtf8 = ui->memsetSourceLineEdit->text().toUtf8();
    QByteArray symbol = ui->memsetSymbolLineEdit->text().toUtf8();
    int count = ui->memsetCountSpinBox->value();

    strfun::memset(sourceStringUtf8.data(),*symbol.data(),count);
    ui->memsetOutputTextEdit->setText(QString::fromUtf8(sourceStringUtf8));
}
