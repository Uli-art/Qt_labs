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

        int valueCount = 0;
        HashTable::ValueCont valueStack(_hashTable.getBucketValues(bucketIndex));
        while (!valueStack.empty()) {
            const HashTable::ValueType& value = valueStack.top();
            QTreeWidgetItem* valueItem = new QTreeWidgetItem(bucketItem, QStringList() << QString::number(value.first) << value.second);
            valueStack.pop();

            ++valueCount;
        }

        bucketItem->setText(0, QString("[%1] - %2").arg(bucketIndex).arg(valueCount));
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

void MainWindow::generatePushButtonClicked() {
    srand (time(0));
    size_t inserted = 0;
    for (int i = 0; i < 100; ++i) {
        int key = 50 - rand() % 100;
        if (_hashTable.insert(HashTable::ValueType(key, QString("Value for %1").arg(key)))) {
            ++inserted;
        }
    }

    ui->_generateResultLabel->setText(QString("Inserted %1 keys").arg(inserted));

    refreshHashTable();
}

struct LessThan50 {
    bool operator ()(int v) const {
        return v < 0;
    }
};

void MainWindow::extractPushButtonClicked() {
    HashTable negativeHashTable(10);
    size_t negativeCount = _hashTable.extractValues(negativeHashTable, LessThan50());

    ui->_extractResultGroupBox->setTitle(QString("Result (%1):").arg(negativeCount));
    ui->_extractResultTreeWidget->clear();

    for (size_t bucketIndex = 0; bucketIndex < negativeHashTable.getBucketCount(); ++bucketIndex) {
        QTreeWidgetItem* bucketItem = new QTreeWidgetItem(ui->_extractResultTreeWidget);

        int valueCount = 0;
        HashTable::ValueCont valueStack(negativeHashTable.getBucketValues(bucketIndex));
        while (!valueStack.empty()) {
            const HashTable::ValueType& value = valueStack.top();
            QTreeWidgetItem* valueItem = new QTreeWidgetItem(bucketItem, QStringList() << QString::number(value.first) << value.second);
            valueStack.pop();

            ++valueCount;
        }

        bucketItem->setText(0, QString("[%1] - %2").arg(bucketIndex).arg(valueCount));
    }

    refreshHashTable();
}
