#include "mainwindow.h"
#include "searchtree.h"
#include <QApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    SearchTree r;
//    r.addItem(5,"hj");
//    QString temp3 = r.find(6);
//    r.addItem(4,"ghjkl");
//    r.addItem(6,"dfgyuh");
//    r.addItem(4,"hkj");
//    r.addItem(2,"hkj");
//    r.addItem(1,"hkj");
//    r.addItem(9,"hkj");
//    QString temp = r.find(6);
//    QString temp2 = r.find(9);
//    r.deleteItem(5);
//    QString f = r.traversePostorder(r.getRoot());
//    qDebug() << f;

    MainWindow w;

    w.show();
    return a.exec();
}
