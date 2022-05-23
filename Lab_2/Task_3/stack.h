#ifndef STACK_H
#define STACK_H
#include <QString>

class Stack
{
public:
    Stack();
    int getSize();
    void push(QString newNode);
    QString pop();
    void clear();
    QString getValue();
private:
    struct Node{
        QString value;
        Node* next;
    };
    Node* head;
    int size;
};

#endif // STACK_H
