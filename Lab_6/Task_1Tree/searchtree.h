#ifndef SEARCHTREE_H
#define SEARCHTREE_H

#include <memory>

class Node;
class QString;

class SearchTree
{
public:
    SearchTree() : _root(nullptr){};
    void addItem(int newElement, QString data);
    bool find(int key, QString& data);
    void deleteItem(int key);
    QString traversePreorder(Node* root);
    QString traverseInorder(Node* root);
    QString traversePostorder(Node* root);
    Node* getRoot() const;
    ~SearchTree(){};

private:
    Node* _root;

    Node* set(int value, QString data, Node* root, Node* parent);
    Node* balance(Node* root);
    void updateHeight(Node* root);
    int getHeight(Node* root) const;
    int getBF(Node* root) const;
    Node* rotateR(Node* root);
    Node* rotateL(Node* root);
    Node* remove(int key, Node* root, Node* parent);
    std::pair<Node*, Node*> find(int value, Node* root, Node* parent);
    std::pair<Node*,Node*> findMin(Node* node, Node* parent);
    Node* recursiveBalance(Node* root);
};

#endif // SEARCHTREE_H
