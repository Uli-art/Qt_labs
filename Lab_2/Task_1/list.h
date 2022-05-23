#ifndef LIST_H
#define LIST_H
#include "node.h"

class List
{
private:
    Node *head;
    int size;
    Node *tail;
public:
    List();
    ~List();
    void addNode(Book newBook);
    void deleteNode(int index);
    void clear();
    int getSize();
    Node* find(int index);
    Node *getHead();
    void setHead(Node * newHead);
};

#endif // LIST_H
