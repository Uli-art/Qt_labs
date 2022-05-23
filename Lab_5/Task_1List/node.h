#ifndef NODE_H
#define NODE_H
#include <QString>


struct Node
{
    QString data;
    Node *next;
    Node *prev;
public:
    Node();
};

#endif // NODE_H
