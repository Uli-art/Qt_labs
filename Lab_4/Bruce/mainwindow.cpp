#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "C:/Users/ulyas/Documents/Labs_OAIP(2 sem)/Lab_4/Task_1/Pair.h"
#include "C:/Users/ulyas/Documents/Labs_OAIP(2 sem)/Lab_4/HeaderOnlyLibVector/vector.h"
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
void Normalize(vector<int>& c) {
    for (int i = 0; i < (int)c.size() - 1; ++i) {
        c[i + 1] += c[i] >> 1;
        c[i] &= 1;
    }
}

void AddZero(vector<int>& c, int x) {
    c.resize(x + 1);
    c[x] = 0;
}

vector<int> AddNum(vector<int>& a, vector<int>& b, int k) {

    vector<int> c(std::max(a.size(), b.size()) + 1);

    for (int i = 0; i < (int)c.size(); ++i) {
        if (i < (int)a.size()) {
            c[i] += a[i];
        }
        if (i < (int)b.size()) {
            c[i] += b[i];
        }
    }

    Normalize(c);
    AddZero(c, k);

    return c;
}

int GetBit(vector<int>& v, int b) {
    return v[b] & 1;
}

vector<int> Multiply(vector<int>& a, int x, int k) {

    vector<int> b = a;
    b.push_back(0);

    for (int i = 0; i < (int)b.size(); ++i) {
        b[i] *= x;
    }

    Normalize(b);
    AddZero(b, k);

    return b;
}

void GenerateSequence(vector<int> n, vector<vector<int>>& p, int k, int i, vector<Pair<int, vector<int>>>& v) {
    if (i == k) {
        n.resize(k + 1);
        if (GetBit(n, k)) {
            v.push_back(make_Pair(k, n));
        }
        return;
    }

    if (GetBit(n, i)) {
        return;
    }

    GenerateSequence(n, p, k, i + 1, v);

    if (i) {
        GenerateSequence(AddNum(n, p[i], k + 1), p, k, i + 1, v);
    }
    return;
}



void MainWindow::on_pushButton_clicked()
{
    int value = ui->num->value();
    if (value == 1) {
        ui->textEdit->setText("1");
        return;
    }
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
}

