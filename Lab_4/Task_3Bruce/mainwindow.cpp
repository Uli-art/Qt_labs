#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Functions.h"
#include <algorithm>
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


void MainWindow::on_pushButton_clicked()
{
    int value = ui->num->value();
    if (value == 1) {
        ui->textEdit->setText("1");
        return;
    }
    ui->pushButton->setEnabled(false);
    --value;
    vector<Pair<int, vector<int>>> sequence;
    for (int k = 1; value / 2 >= (int)sequence.size(); ++k) {
        vector<int> a(k + 1);
        a[k] = 1;
        vector<vector<int>> b(k + 1);
        b[0].push_back(1);
        AddZero(b[0], k + 1);
        for (int i = 0; i < k; ++i) {
            b[i + 1] = Multiply(b[i], 10, k + 1);
        }
        GenerateSequence(a, b, k, 0, sequence);
     }


    for (int i = 0; i < (int)sequence.size(); ++i)
        std::reverse(sequence[i].second.data(), sequence[i].second.data() + sequence[i].second.size());

    std::sort(sequence.data(), sequence.data() + sequence.size()); /////////////////////////
    --value;
    vector<int> w = sequence[value / 2].second;
    std::reverse(w.data(), w.data() + w.size());

    if (value % 2) {
        w[0] ^= 1;
    }

    QString answer;
    for (int k = sequence[value / 2].first; k >= 0; --k) {
        answer += QString::number(w[k] & 1);
    }
    ui->textEdit->setText(answer);
    ui->pushButton->setEnabled(true);
}

