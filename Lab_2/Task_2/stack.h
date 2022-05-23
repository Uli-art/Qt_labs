#ifndef STACK_H
#define STACK_H
#include <QString>

class Stack
{
public:
    Stack();
    int getSize();
    void push(QString newNode, int index, int number);
    void pop();
    void clear();
    QString getHead();
    int getHeadIndex();
    int getHeadSecIndex();
private:
    struct Node{
        QString value;
        int index;
        int number;
        Node* next;
    };
    Node* head;
    int size;
};

#endif // STACK_H
