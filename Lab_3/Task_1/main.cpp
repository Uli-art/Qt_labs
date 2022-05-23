#include "mainwindow.h"
#include "shared_ptr.h"
#include "weak_ptr.h"
#include "unique_ptr.h"

#include <QDebug>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    shared_ptr<int> f(new int());
    {
        shared_ptr<int> f1(f);
        qDebug() << f.use_count();

        weak_ptr<int> w1(f);
        qDebug() <<f1.use_count();

        shared_ptr<int> f2 = w1.lock();
        qDebug() <<f2.use_count();
    }
    qDebug() << f.use_count();


    unique_ptr<int> up(new int(20));
    qDebug() << "Unique 1 value - "<< *up;

    unique_ptr<int> up1 = std::move(up);
    qDebug() << "up is null - "<< !up << "up1 value " << *up1;

    up.swap(up1);
    qDebug() << "up1 is null - "<< !up1 << "up value " << *up;
    shared_ptr<int> f4(new int(2));
    weak_ptr<int> f5(f4);
    f4.reset(nullptr);
    qDebug() << f5.expired();
    return a.exec();
}
