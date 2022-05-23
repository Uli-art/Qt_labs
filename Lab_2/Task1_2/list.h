#ifndef LIST_H
#define LIST_H
#include "node.h"
#include "calls.h"
class List
{
private:
    Node* array;
    size_t size;
    int capacity;
    Node *head;
public:
    List();
    void addCall(Calls newCall);
    void deleteCall(int index);
    void clear();
    Node* grow();
    int getSize();
    Node* getArray();
    void setHead();
};

#endif // LIST_H
