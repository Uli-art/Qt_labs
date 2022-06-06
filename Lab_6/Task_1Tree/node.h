#ifndef NODE_H
#define NODE_H

#include <QString>

class Node
{
public:
    Node(int k, QString d, Node* p):
         key(k),
         right(nullptr),
         left(nullptr),
         data(d),
         parent(p),
         height(1) {};

    int getKey() const {
        return key;
    }

    QString getValue() const {
        return data;
    }

    Node* getLeft() const {
        return left;
    }

    Node* getRight() const {
        return right;
    }

    bool operator <(const Node& second) {
        return key < second.key;
    }

    bool operator >(const Node& second) {
        return key > second.key;
    }

    bool operator <(const int& second) {
        return key < second;
    }

    bool operator >(const int& second) {
        return key > second;
    }

    bool hasChildren() const {
        return left != nullptr || right != nullptr;
    }

    bool isFull() const {
        return left != nullptr && right != nullptr;
    }

    ~Node(){
        right = nullptr;
        left = nullptr;
    };

private:
    int key;
    Node* right;
    Node* left;
    QString data;
    Node* parent;
    int height;

    friend class SearchTree;
};

#endif // NODE_H
