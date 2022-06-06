#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    _hashTable(10)
{
    ui->setupUi(this);
    refreshHashTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::refreshHashTable() {
    ui->_hashTreeWidget->clear();
    for (size_t bucketIndex = 0; bucketIndex < _hashTable.getBucketCount(); ++bucketIndex) {
        QTreeWidgetItem* bucketItem = new QTreeWidgetItem(ui->_hashTreeWidget);

        const HashTable::ValueCont& valueList = _hashTable.getBucketValues(bucketIndex);
        for (HashTable::ValueCont::const_iterator it = valueList.begin(); it != valueList.end(); ++it) {
            QTreeWidgetItem* valueItem = new QTreeWidgetItem(bucketItem,
                QStringList() << QString::number(it->first) << it->second);
        }

        bucketItem->setText(0, QString("[%1] - %2").arg(bucketIndex).arg(valueList.size()));
    }

    ui->_statusBar->showMessage(QString("Buckets: %1, Size: %2, Load: %3 (%4)").
                                arg(_hashTable.getBucketCount()).
                                arg(_hashTable.getSize()).
                                arg(_hashTable.getLoad()).
                                arg(_hashTable.getMaxloadFactor()));
}

void MainWindow::insertPushButtonClicked() {
    int key = ui->_insertKeySpinBox->value();
    QString value = ui->_insertValueLineEdit->text();

    bool inserted = _hashTable.insert(HashTable::ValueType(key, value));
    ui->_insertResultLabel->setText(inserted ? "True" : "False");

    refreshHashTable();
}

void MainWindow::getPushButtonClicked() {
    int key = ui->_getKeySpinBox->value();
    QString newValue = ui->_getValueLineEdit->text();
    if (!newValue.isEmpty()) {
        _hashTable[key] = newValue;
    }
    ui->_getResultLabel->setText(_hashTable[key]);

    refreshHashTable();
}

void MainWindow::erasePushButtonClicked() {
    int key = ui->_eraseKeySpinBox->value();
    size_t count = _hashTable.erase(key);

    ui->_eraseResultLabel->setText(QString("%1").arg(count));

    refreshHashTable();
}

void MainWindow::containsPushButtonClicked() {
    int key = ui->_containsKeySpinBox->value();
    bool contains = _hashTable.contains(key);

    ui->_containsResultLabel->setText(contains ? "True" : "False");
}

void MainWindow::clearPushButtonClicked() {
    _hashTable.clear();
    refreshHashTable();
}

void MainWindow::rehashPushButtonClicked() {
    size_t newBucketCount = ui->_rehashBucketCountSpinBox->value();
    _hashTable.rehash(newBucketCount);
    refreshHashTable();
}
