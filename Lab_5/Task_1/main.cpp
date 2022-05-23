#include "mainwindow.h"
#include "queue.h"
#include <QApplication>
#include <QDebug>
class A{
public:
    A() : array('0'){qDebug() << "Constract" << "\n";};
    A(char g): array(g), a(0){qDebug() << "Constract" << array <<"\n";};
    A(char g, int s): array(g),a(s){qDebug() << "Constract" << array <<"\n";};
    ~A(){qDebug() << "Delete" << "\n";}
    A& operator =(const A& other){qDebug() << "Operator = " << "\n"; array = other.array; a = other.a;return *this;};
    A(const A& other){qDebug() << "Const Copy constructor = " << "\n"; array = other.array; a = other.a;};
    char array;
    int a;

};

void print(queue<A>& queue){
    while(!queue.empty()){
       qDebug() << queue.front().array;
       queue.pop();
    }
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
//    queue<A> q;
//    queue<A> q2;
//    A newA4('4');
//    A newA5('5');
//    A newA3('3');
//    A newA9('9');
//    q2.push(newA3);
//    q2.push(newA9);
//    q2.push(newA5);
//    q2.push(newA5);
//    print(q2);
//    q2.push(newA3);
//    q2.push(newA9);
//    q2.push(newA5);
//    q2.push(newA5);
//    q.push(newA4);
//    q.push(newA5);
//    //q.emplace('3', 2);
//    print(q);
//    q.push(newA4);
//    q.push(newA5);
//   // q.emplace('3', 2);
//    qDebug() << q.front().array << " " << q.back().array << " " << q.size();
//    q.pop();
//    q.pop();
//    qDebug() << q.empty();
//   // qDebug() << q.front().array << " " << q.back().array << " " << q.size();
//    //q.swap(q2);
//    print(q);
//    print(q2);

//    {
//        queue<A> q3;
//        q3.push(newA3);
//        q3.push(newA9);
//        q3.push(newA5);
//        q3.push(newA5);

//        qDebug("----- Begin Delete q3 ----");
//    }

//    qDebug("----- End Delete q3 ----");

}
