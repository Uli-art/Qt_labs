#ifndef NODE_H
#define NODE_H
#include "calls.h"

struct Node
{
    Calls call;
    int next;
    int prev;
    bool show;
public:
    Node();
};

#endif // NODE_H
