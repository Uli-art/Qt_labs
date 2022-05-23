#include "mainwindow.h"
#include "list.h"
#include <QApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    List f;
    f.add("dd");
    f.add("hgf");
    f.add("kjnhg");
    f.add("juhyg");
    f.add("juhyg");
    f.makeCircle();
    Node* start = f.getHead();
    //for(;;){
       // qDebug() << start->data;
      //  start = start->next;
  //  }
    w.show();
    return a.exec();

}
