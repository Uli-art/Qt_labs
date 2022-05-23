#ifndef NODE_H
#define NODE_H

#include "book.h"
struct Node
{
    Book data;
    Node *next;
    Node *prev;
public:
    Node();
};

#endif // NODE_H
