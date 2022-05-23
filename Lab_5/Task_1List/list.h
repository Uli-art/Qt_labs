#ifndef LIST_H
#define LIST_H
#include "node.h"
class List
{
public:
    List();
    ~List();
    void add(QString newSrt);
    void pop(int index);
    void clear();
    int getSize();
    Node* makeCircle();
   // Node* find(int index);
    Node *getHead();
   // void setHead(Node * newHead);
private:
    Node *head;
    int size;
    Node *tail;
};

#endif //LIST_H
