#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    refreshStatistics();
    refreshConversions();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onValueChanged() {
    _bitSet = BitSet<64>(ui->_valueLineEdit->text().remove(" ").toStdString());

    refreshStatistics();
    refreshConversions();
}

void MainWindow::onSetPushButtonClicked() {
    _bitSet.set(ui->_setBitSpinBox->value(), true);
    updateValue();
}

void MainWindow::onResetPushButtonClicked() {
    _bitSet.reset(ui->_resetBitSpinBox->value());
    updateValue();
}

void MainWindow::onFlipPushButtonClicked() {
    _bitSet.flip(ui->_flipBitSpinBox->value());
    updateValue();
}

void MainWindow::onTestPushButtonClicked() {
    ui->_testBitValueLabel->setText(_bitSet.test(ui->_testBitSpinBox->value()) ? "True" : "False");
}

void MainWindow::onModifyPushButtonClicked() {
    _bitSet[ui->_modifyBitSpinBox->value()] = ui->_modifyBitValueComboBox->currentText() == "True" ? true : false;
    updateValue();
}

void MainWindow::onAndPushButtonClicked() {
    BitSet<64> other(ui->_andValueLineEdit->text().remove(" ").toStdString());
    _bitSet &= other;

    updateValue();
}

void MainWindow::onOrPushButtonClicked() {
    BitSet<64> other(ui->_orValueLineEdit->text().remove(" ").toStdString());
    _bitSet |= other;

    updateValue();
}

void MainWindow::onXorPushButtonClicked() {
    BitSet<64> other(ui->_xorValueLineEdit->text().remove(" ").toStdString());
    _bitSet ^= other;

    updateValue();
}

void MainWindow::onNotPushButtonClicked() {
    _bitSet = ~_bitSet;
    updateValue();
}

void MainWindow::onLeftShitPushButtonClicked() {
    _bitSet <<= ui->_shiftLeftPosSpinBox->value();
    updateValue();
}

void MainWindow::onRightShitPushButtonClicked() {
    _bitSet >>= ui->_shiftRightPosSpinBox->value();
    updateValue();
}

void MainWindow::refreshStatistics() {
    ui->_allLabel->setText(_bitSet.all() ? "True" : "False");
    ui->_noneLabel->setText(_bitSet.none() ? "True" : "False");
    ui->_anyLabel->setText(_bitSet.any() ? "True" : "False");
    ui->_sizeLabel->setText(QString::number(_bitSet.size()));
    ui->_countLabel->setText(QString::number(_bitSet.count()));
}

void MainWindow::refreshConversions() {
    ui->_toStringLabel->setText(QString::fromStdString(_bitSet.toString()));
    ui->_toUlongLabel->setText(QString::number(_bitSet.toUlong()));
    ui->_toUllongLabel->setText(QString::number(_bitSet.toUllong()));
}

void MainWindow::updateValue() {
    ui->_valueLineEdit->blockSignals(true);
    ui->_valueLineEdit->setText(QString::fromStdString(_bitSet.toString()));
    ui->_valueLineEdit->blockSignals(false);

    refreshStatistics();
    refreshConversions();
}
