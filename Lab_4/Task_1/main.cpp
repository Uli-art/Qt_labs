#include "mainwindow.h"
#include "Pair.h"
#include "vector.h"
#include <QApplication>
#include <QDebug>

class A{
public:
    A() : array('0'){qDebug() << "Constract" << "\n";};
    A(char g): array(g), a(0){qDebug() << "Constract" << array <<"\n";};
    A(char g, int s): array(g),a(s){qDebug() << "Constract" << array <<"\n";};
    //A(char&& g): array(g){qDebug() << "Constract move" << array <<"\n";};
    ~A(){qDebug() << "Delete" << "\n";}
    //A operator =(A& other){qDebug() << "Operator = " << "\n"; array = other.array;return *this;};
    A& operator =(const A& other){qDebug() << "Operator = " << "\n"; array = other.array; a = other.a;return *this;};
    //A(A& other){qDebug() << "Copy constructor = " << "\n"; array = other.array;};
    A(const A& other){qDebug() << "Const Copy constructor = " << "\n"; array = other.array; a = other.a;};

    char array;
    int a;

};

void print(const vector<A>& newVector) {
    for(int i = 0; i < newVector.size(); ++i){
        qDebug() << newVector[i].array << " " << newVector[i].a << ' ';
    }
    qDebug() << newVector.capacity() << " " << newVector.size() << '\n';
}

void printy(vector<A>& newVector) {
    for(vector<A>::const_reverse_iterator it = newVector.crbegin(); it > newVector.crend(); ++it){
        qDebug() << (*it).array << ' ';
    }
    qDebug() << '\n';
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

//    Pair<int,int> pair(2,3);
//    qDebug() << pair.first << " " << pair.second << "\n";
//    Pair<int,int> pair1(pair);
//    qDebug() << pair1.first << " " << pair1.second << "\n";
//    Pair<int,int> pair2;
//    pair2= pair1;
//    qDebug() << pair2.first << " " << pair2.second << "\n";
//    Pair<Pair<int,int>,Pair<int,int>> pair3(pair,pair1);
//    qDebug() << pair3.first.first << " " << pair3.first.second<< " " << pair3.second.first << " " << pair3.second.second <<  "\n";

//    pair = Pair<char, char>(1, 2);
//    qDebug() << pair.first << " " << pair.second << "\n";

     //return a.exec();
    vector<A> newVector(6);
    print(newVector);
    A newA4('4');
    A newA5('5');
    A newA3('3');
    A newA9('9');
    print(newVector);
    newVector.insert(newVector.begin(), 4, newA4);
    print(newVector);
    int ae = 2;
    newVector.insert(newVector.begin() + ae, 2, newA5);
    print(newVector);
    newVector.erase(newVector.cbegin() + 3, newVector.cend());
    print(newVector);
    vector<A> newVector2(3);
    newVector2.push_back(newA3);
    newVector2.push_back(newA4);
    newVector2.push_back(newA3);
    newVector.assign(newVector2.begin(), newVector2.end());
    print(newVector);
    newVector.emplace_back('3',5);
    print(newVector);
    newVector.emplace(newVector.cbegin() + 2, '9');
    print(newVector);
//    newVector.push_back(3);
//    newVector.push_back(4);
//    newVector.push_back(8);
//    newVector.pop_back();
//    newVector.pop_back();
//    newVector.pop_back();
//    newVector.pop_back();
//    newVector.pop_back();
//    newVector.pop_back();
//    print(newVector);

/*    vector<int> newVector2(6);
    newVector2.push_back(2);
    newVector.swap(newVector2);
    newVector.clear();
    newVector.insert(newVector.begin()+2,5);*/
    qDebug() << newVector.empty() << '\n';
}
