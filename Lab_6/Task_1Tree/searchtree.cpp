#include "searchtree.h"
#include "node.h"

#include <QString>

Node* SearchTree::set(int key, QString data, Node* root, Node* parent) {
    if(!root){
        return new Node(key, data, parent);
    }
    if(key < root->key){
        root->left = set(key,data ,root->left, root);
    }
    else{
        root->right =  set(key,data ,root->right, root);
    }
    return balance(root);
}

Node* SearchTree::balance(Node* root) {
    updateHeight(root);
    if(getBF(root) == 2){
        if(getBF(root->right) < 0){
            root->right = rotateR(root->right);
        }
        return rotateL(root);
    } else if(getBF(root) == -2){
        if(getBF(root->left) > 0){
            root->left = rotateL(root->left);
        }
        return rotateR(root);
    }
    return root;
}

Node* SearchTree::recursiveBalance(Node* root) {
    if(root == nullptr)
        return nullptr;
    updateHeight(root);
    if(getBF(root) == 2){
        if(getBF(root->right) < 0){
            root->right = rotateR(root->right);
        }
        rotateL(root);
    } else if(getBF(root) == -2){
        if(getBF(root->left) > 0){
            root->left = rotateL(root->left);
        }
        rotateR(root);
    }
    return recursiveBalance(root->parent);
}
void SearchTree::updateHeight(Node* root) {
    root->height = qMax(getHeight(root->right), getHeight(root->left)) + 1;
}

int SearchTree::getHeight(Node* root) const {
    return root? root->height:0;
}

int SearchTree::getBF(Node* root) const {
    return getHeight(root->right)- getHeight(root->left);
}

Node* SearchTree::rotateR(Node* root){
    Node* sec = root->left;
    root->left = sec->right;
    sec->right = root;
    updateHeight(sec);
    updateHeight(root);
    return sec;
}

Node* SearchTree::rotateL(Node* root){
    Node* sec = root->right;
    root->right = sec->left;
    sec->left = root;
    updateHeight(sec);
    updateHeight(root);
    return sec;
}

void SearchTree::addItem(int newElement, QString data){
    if(_root == nullptr){
        _root = new Node(newElement, data, nullptr);
    } else {
        if(!find(newElement, data)){
           _root = set(newElement, data, _root, nullptr);
        }
    }
}

bool SearchTree::find(int key, QString& data){
    if(_root == nullptr)
        return false;
    std::pair<Node*, Node*> curr = find(key, _root, nullptr);
    if(curr.first){
        data = curr.first->data;
        return true;
    }
    return false;
}

std::pair<Node*, Node*> SearchTree::find(int key, Node* node, Node* parent){
    if(node == nullptr){
        return std::make_pair(node, parent);;
    }
    if(node->key > key ){
        return find(key, node->left, node);
    } else if(node->key < key){
        return find(key, node->right, node);
    } else{
        return std::make_pair(node, parent);
    }
}

void SearchTree::deleteItem(int key){
    if(_root == nullptr)
        return;
    std::pair<Node*, Node*> curr = find(key, _root, nullptr);
    if(curr.first)
        remove(key, curr.first, curr.second);
}

Node* SearchTree::remove(int key, Node* node, Node* parent) {
    if(node == nullptr) {
        return nullptr;
    }

    if (!node->hasChildren()) {
        if(parent) {
            if(parent->right && parent->right->key == key) {
                parent->right = nullptr;
            } else {
                parent->left = nullptr;
            }
        } else {
            _root = nullptr;
        }
        delete node;
        node = nullptr;
        return nullptr;
    } else if (node->isFull()) {
        std::pair<Node*, Node*> min = findMin(node->right,node);
        std::swap(node->data,min.first->data);
        std::swap(node->key, min.first->key);

        Node* parent =  min.first->parent;
        remove(min.first->key,min.first, min.second);

        return recursiveBalance(parent);
    } else {
        if (parent != nullptr) {
            if(parent->right->key == key) {
                if(node->right)
                    parent->right = node->right;
                else {
                    parent->right = node->left;
                }
            } else {
                if(node->right)
                    parent->left = node->right;
                else {
                    parent->left = node->left;
                }
            }
        } else {
            if(node->right)
                _root = node->right;
            else {
                _root = node->left;
            }
        }

        delete node;
        node = nullptr;
    }

    if (parent != nullptr) {
        return recursiveBalance(parent);
    }

    return nullptr;
}

std::pair<Node*,Node*> SearchTree::findMin(Node* node, Node* parent) {
    if(node->left) {
        findMin(node->left, node);
    }
    return std::make_pair(node, parent);
}

QString SearchTree::traversePreorder(Node* root){
    QString res = "";
    res += " " + QString::number(root->key);
    if (root->left)
        res += traversePreorder(root->left);

    if (root->right){
         res += traversePreorder(root->right);
    }
    return res;
}

QString SearchTree::traverseInorder(Node* root){
    QString res = "";
    if(!root) return res;
    if (root->left)
        res += traverseInorder(root->left);

    res += " " + QString::number(root->key);

    if (root->right){
         res += traverseInorder(root->right);
    }
    return res;
}

QString SearchTree::traversePostorder(Node* root){
    QString res = "";
    if (root->left)
        res += traversePostorder(root->left);

    if (root->right){
         res += traversePostorder(root->right);
    }
    res += " " + QString::number(root->key);
    return res;
}

Node* SearchTree::getRoot() const {
    return _root;
}

