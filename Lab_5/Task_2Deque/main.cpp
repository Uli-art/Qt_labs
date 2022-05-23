#include "mainwindow.h"
#include "deque.h"
#include <QApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
//    Deque<int> g;
//    g.push_back(6);
//    g.push_back(6);
//    g.push_front(9);
//    g.push_front(90);
//    g.pop_front();
//    g.pop_front();
//    g.pop_front();
//    g.pop_front();
//    g.push_back(7);
//    g.push_back(8);
//    g.push_front(1);
//    g.push_front(2);
//    g.clear();
//    g.push_back(6);
//    g.push_front(9);
//    for(int i = 0;i < g.size(); ++i) {
//        qDebug() << g[i];
//    }

}
