#include "mainwindow.h"
#include "Set.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
//    Set<int> test;
//    std::pair<int,int> t = std::make_pair<int, int>(4,5);
//    std::pair<int,int> ty = std::make_pair<int, int>(2,9);

//    std::pair<int,int> te = std::make_pair<int, int>(1,0);

//    std::pair<int,int> ti = std::make_pair<int, int>(10,3);

//    Set<int>::iterator x;
//    std::pair<Set<int>::iterator, bool> f = test.insert(t);
//    std::pair<Set<int>::iterator, bool> fd = test.insert(ty);

//    std::pair<Set<int>::iterator, bool> fh = test.insert(te);

//    std::pair<Set<int>::iterator, bool> fj = test.insert(ti);

//    std::pair<Set<int>::iterator, bool> fu = test.insert(t);
//    x = f.first;
//    x = fd.first;
//    x = fj.first;
//    x.operator->();

    //x = test.find(5);
    //test.erase(x);

    w.show();
    return a.exec();
}
