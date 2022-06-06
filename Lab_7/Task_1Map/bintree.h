#ifndef BINTREE_H
#define BINTREE_H

#include <memory>
#include <list>

template <typename K, typename V>
class BinTree
{
public:
    typedef K KeyType;
    typedef V ValueType;

    struct Node
    {
        Node(KeyType k, ValueType v, Node* p);
        ~Node(){};

        bool operator < (const Node& other) const;

        bool hasChildren() const;
        bool isFull() const;

        KeyType key;
        ValueType value;
        Node* left;
        Node* right;
        Node* parent;
        int height;
    };

    BinTree();
    ~BinTree();

    void addItem(KeyType key, const ValueType& value, Node** addedNode);
    void deleteItem(KeyType key);
    Node* getRoot() const;

    bool find(KeyType key, ValueType& value);

    void traversePreorder(Node* root, std::list<KeyType>& out);
    void traverseInorder(Node* root, std::list<KeyType>& out) const;
    void traverseInorder(Node* root, std::list<Node*>& out) const;
    void traversePostorder(Node* root, std::list<KeyType>& out);
    size_t size() const;
    void clear(Node* node);
    Node* set(KeyType key, const ValueType& value, Node* root, Node* parent, Node** addedNode);
    Node* balance(Node* root);
    void updateHeight(Node* root);
    int getHeight(Node* root) const;
    int getBF(Node* root) const;
    Node* rotateR(Node* root);
    Node* rotateL(Node* root);
    Node* remove(KeyType key, Node* root, Node* parent);
    std::pair<Node*, Node*> find(KeyType key, Node* root, Node* parent);
    std::pair<Node*,Node*> findMin(Node* node, Node* parent);
    Node* recursiveBalance(Node* root);
private:
    Node* _root;
};

template <typename K, typename V>
BinTree<K, V>::BinTree() :
    _root(nullptr) {

}

template <typename K, typename V>
BinTree<K, V>::~BinTree() {
}

template <typename K, typename V>
void BinTree<K, V>::clear(Node* node) {
    if(node == nullptr) {
        return;
    }

    if(node->left != nullptr) clear(node->left);
    if(node->right != nullptr) clear(node->right);
    delete node;
    _root = nullptr;
}

template <typename K, typename V>
typename BinTree<K, V>::Node* BinTree<K, V>::getRoot() const {
    return _root;
}

template <typename K, typename V>
void BinTree<K, V>::addItem(K key, const V& value, Node** addedNode) {
    if(_root == nullptr){
        _root = new Node(key, value, nullptr);
        if (addedNode != nullptr) {
            *addedNode = _root;
        }
    } else {
        ValueType foundValue;
        if(!find(key, foundValue)) {
            Node* addedNodeTemp;
           _root = set(key, value, _root, nullptr, &addedNodeTemp);
           *addedNode = addedNodeTemp;
        }
    }
}

template <typename K, typename V>
bool BinTree<K, V>::find(K key, V& value) {
    if(_root == nullptr) {
        return false;
    }

    std::pair<Node*, Node*> curr = find(key, _root, nullptr);
    if(curr.first) {
        value = curr.first->value;
        return true;
    }
    return false;
}

template <typename K, typename V>
void BinTree<K, V>::deleteItem(K key) {
    if(_root == nullptr) {
        return;
    }

    std::pair<Node*, Node*> curr = find(key, _root, nullptr);
    if(curr.first) {
        remove(key, curr.first, curr.second);
    }
}

template <typename K, typename V>
typename BinTree<K, V>::Node* BinTree<K,V>::set(K key, const V& value, Node* root, Node* parent, Node** addedNode) {
    if(!root) {
        Node* newNode = new Node(key, value, parent);
        if (addedNode != nullptr) {
            *addedNode = newNode;
        }
        return newNode;
    }

    if(key < root->key) {
        root->left = set(key, value ,root->left, root, addedNode);
    }
    else {
        root->right =  set(key, value ,root->right, root, addedNode);
    }

    return balance(root);
}

template <typename K, typename V>
typename BinTree<K, V>::Node* BinTree<K,V>::balance(Node* root) {
    updateHeight(root);

    if(getBF(root) == 2) {
        if(getBF(root->right) < 0) {
            root->right = rotateR(root->right);
        }
        return rotateL(root);
    } else if(getBF(root) == -2) {
        if(getBF(root->left) > 0) {
            root->left = rotateL(root->left);
        }
        return rotateR(root);
    }
    return root;
}

template <typename K, typename V>
typename BinTree<K, V>::Node* BinTree<K,V>::recursiveBalance(Node* root) {
    if(root == nullptr) {
        return nullptr;
    }

    updateHeight(root);
    if(getBF(root) == 2) {
        if(getBF(root->right) < 0) {
            root->right = rotateR(root->right);
        }
        rotateL(root);
    } else if(getBF(root) == -2) {
        if(getBF(root->left) > 0) {
            root->left = rotateL(root->left);
        }
        rotateR(root);
    }
    if(root->parent) {
        return recursiveBalance(root->parent);
    } else {
        return recursiveBalance(root);
    }
}

template <typename K, typename V>
void BinTree<K,V>::updateHeight(Node* root) {
    root->height = qMax(getHeight(root->right), getHeight(root->left)) + 1;
}

template <typename K, typename V>
int BinTree<K,V>::getHeight(Node* root) const {
    return root ? root->height : 0;
}

template <typename K, typename V>
int BinTree<K,V>::getBF(Node* root) const {
    return getHeight(root->right)- getHeight(root->left);
}

template <typename K, typename V>
typename BinTree<K, V>::Node* BinTree<K,V>::rotateR(Node* root) {
    Node* sec = root->left;
    root->left = sec->right;
    sec->right = root;
    std::swap(sec->parent, root->parent);
    updateHeight(sec);
    updateHeight(root);
    return sec;
}

template <typename K, typename V>
typename BinTree<K, V>::Node* BinTree<K,V>::rotateL(Node* root) {
    Node* sec = root->right;
    root->right = sec->left;
    sec->left = root;
    std::swap(sec->parent, root->parent);
    updateHeight(sec);
    updateHeight(root);
    return sec;
}

template <typename K, typename V>
std::pair<typename BinTree<K, V>::Node*, typename BinTree<K, V>::Node*> BinTree<K,V>::find(K key, Node* node, Node* parent) {
    if(node == nullptr) {
        return std::make_pair(node, parent);;
    }

    if(key < node->key) {
        return find(key, node->left, node);
    } else if(node->key < key) {
        return find(key, node->right, node);
    } else {
        return std::make_pair(node, parent);
    }
}

template <typename K, typename V>
typename BinTree<K, V>::Node* BinTree<K,V>::remove(K key, Node* node, Node* parent) {
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
        std::swap(node->value,min.first->value);
        std::swap(node->key, min.first->key);
        remove(min.first->key,min.first, min.second);
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
    if(parent) {
        return recursiveBalance(parent);
    } else {
        return recursiveBalance(_root);
    }
}

template <typename K, typename V>
std::pair<typename BinTree<K, V>::Node*, typename BinTree<K, V>::Node*> BinTree<K,V>::findMin(Node* node, Node* parent) {
    if(node->left) {
        findMin(node->left, node);
    }
    return std::make_pair(node, parent);
}

template <typename K, typename V>
void BinTree<K, V>::traversePreorder(Node* root, std::list<KeyType>& out) {
    out.push_back(root->key);
    if (root->left) {
        traversePreorder(root->left, out);
    }

    if (root->right) {
         traversePreorder(root->right, out);
    }
}

template <typename K, typename V>
void BinTree<K, V>::traverseInorder(Node* root, std::list<KeyType>& out) const {
    if(root == nullptr) {
        return;
    }

    if (root->left) {
        traverseInorder(root->left, out);
    }

    out.push_back(root->key);

    if (root->right) {
         traverseInorder(root->right, out);
    }
}

template <typename K, typename V>
void BinTree<K, V>::traverseInorder(Node* root, std::list<Node*>& out) const {
    if(root == nullptr) {
        return;
    }

    if (root->left) {
        traverseInorder(root->left, out);
    }

    out.push_back(root);

    if (root->right) {
         traverseInorder(root->right, out);
    }
}

template <typename K, typename V>
void BinTree<K, V>::traversePostorder(Node* root, std::list<KeyType>& out) {
    if (root->left) {
        traversePostorder(root->left, out);
    }

    if (root->right) {
         traversePostorder(root->right, out);
    }

    out.push_back(root->key);
}

template <typename K, typename V>
size_t BinTree<K, V>::size() const {
    std::list<KeyType> out;
    traverseInorder(_root, out);
    return out.size();
}

template <typename K, typename V>
BinTree<K, V>::Node::Node(KeyType k, ValueType v, Node* p):
    key(k),
    value(v),
    left(nullptr),
    right(nullptr),
    parent(p),
    height(1) {}

template <typename K, typename V>
bool BinTree<K, V>::Node::operator < (const Node& other) const {
    return this->key < other.key;
}

template <typename K, typename V>
bool BinTree<K, V>::Node::hasChildren() const {
    return left != nullptr || right != nullptr;
}

template <typename K, typename V>
bool BinTree<K, V>::Node::isFull() const {
    return left != nullptr && right != nullptr;
}
#endif // BINTREE_H
