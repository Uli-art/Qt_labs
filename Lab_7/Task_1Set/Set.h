#ifndef MAP_H
#define MAP_H
#include "BinTree.h"
#include <QString>
template <typename K>
class Set
{
public:
    typedef std::pair<K, char> ValueType;
    typedef typename BinTree<K, ValueType>::Node Node;
    typedef typename std::list<Node*>::iterator listIterator;

    class iterator {
    public:
        iterator();
        ~iterator();

        K& operator*() const;
        K* operator->() const;
        iterator& operator++(void);
        iterator operator =(const iterator& other);
        iterator& operator--(void);
        bool operator !=(const iterator& other) {
            return this->pointer != other.pointer;
        }


    private:
        listIterator pointer;
        iterator(listIterator p);
    friend class Set;
    };

    Set();
    ~Set();

    bool empty() const;
    size_t size() const;
    bool contains(const K& key );

    void clear();
    std::pair<iterator, bool> insert( const K& value );
    void erase(iterator pos);
    iterator find(const K& key);
    QString toString();
private:
    BinTree<K, ValueType> _tree;
    std::list<Node*> _sortedNodeList;

    listIterator insert(Node* other) {
        listIterator it = std::lower_bound(_sortedNodeList.begin(), _sortedNodeList.end(), other, compareNodes);
        return _sortedNodeList.insert(it, other);
    }

    void deleteKey(iterator pos) {
        listIterator it = _sortedNodeList.erase(pos.pointer);
    }

    static bool compareNodes(const Node* a, const Node* b) {
        return *a < *b;
    }
};

template <typename K>
Set<K>::Set() :
        _tree(),
        _sortedNodeList()
{}

template <typename K>
Set<K>::~Set() {
    clear();
}

template <typename K>
bool Set<K>::empty() const {
    return _tree.size() == 0;
}

template <typename K>
size_t Set<K>::size() const {
    return _tree.size();
}

template <typename K>
void Set<K>::clear() {
    _tree.clear(_tree.getRoot());
    _sortedNodeList.clear();
}

template <typename K>
bool Set<K>::contains(const K& key) {
    char temp;
    return _tree.find(key, std::make_pair(key,temp));
}

template <typename K>
std::pair<typename Set<K>::iterator, bool> Set<K>::insert(const K& value) {
    std::pair<Node*, Node*> result = _tree.find(value, _tree.getRoot(), nullptr);
    if(!result.first) {
        Node* addedNode = nullptr;
        char temp;
        _tree.addItem(value, std::make_pair(value,temp), &addedNode);
        return std::make_pair<typename Set<K>::iterator, bool>(iterator(insert(addedNode)),true);
    } else {

        return std::make_pair<typename Set<K>::iterator, bool>(iterator(std::find(_sortedNodeList.begin(), _sortedNodeList.end(), result.first)) ,false);
    }
}

template <typename K>
typename Set<K>::iterator Set<K>::find(const K& key) {
    std::pair<Node*, Node*> result = _tree.find(key, _tree.getRoot(), nullptr);
    listIterator it =std::find(_sortedNodeList.begin(), _sortedNodeList.end(), result.first);
    return iterator(it);
}

template <typename K>
void  Set<K>::erase(iterator pos){
    if(pos != _sortedNodeList.end()){
        Node* it = *pos.pointer;
        _tree.deleteItem(it->key);
        deleteKey(pos);
    }
}

template <typename K>
Set<K>::iterator::iterator() :
    iterator(listIterator()) {
}

template <typename K>
Set<K>::iterator::~iterator() {
}

template <typename K>
Set<K>::iterator::iterator(listIterator p) :
    pointer(p)
{}

template <typename K>
K& Set<K>::iterator::operator*() const {
    Node* it = *pointer;
    return it->value.first;
}

template <typename K>
K* Set<K>::iterator::operator->() const {
    Node* it = *pointer;
    return &it->value.first;
}

template <typename K>
typename Set<K>::iterator& Set<K>::iterator::operator++(void) {
    ++pointer;
    return *this;
}

template <typename K>
typename Set<K>::iterator& Set<K>::iterator::operator--(void) {
    --pointer;
    return *this;
}

template <typename K>
typename Set<K>::iterator Set<K>::iterator::operator =(const iterator& other) {
    pointer = other.pointer;
    return *this;
}

template <typename K>
QString  Set<K>::toString(){
    QString result;
    std::list<K> elements;
    _tree.traverseInorder(_tree._root, elements);
    for(auto it = elements.begin(); it != elements.end(); ++it) {
        result += QString::number(*it) + " ";

    }
    return result;
}

#endif // MAP_H
