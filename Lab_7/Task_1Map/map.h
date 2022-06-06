#ifndef MAP_H
#define MAP_H
#include "bintree.h"

template <typename K, typename V>
class Map
{
public:
    typedef std::pair<K, V> ValueType;
    typedef typename BinTree<K, ValueType>::Node Node;
    typedef typename std::list<Node*>::iterator listIterator;

    class iterator {
    public:
        iterator();
        ~iterator();

        V& operator*() const;
        V* operator->() const;
        iterator& operator++(void);
        iterator operator =(const iterator& other);
        iterator& operator--(void);
        bool operator !=(const iterator& other);

        K& getKey();

    private:
        listIterator pointer;
        iterator(listIterator p);
    friend class Map;
    };

    Map();
    ~Map();

    V& operator[](const K& key);

    bool empty() const;
    size_t size() const;
    bool contains(K& key);

    void clear();
    std::pair<iterator, bool> insert( const ValueType& value );
    void erase(iterator pos);
    iterator find(const K& key);

    iterator begin();
    iterator end();

private:
    BinTree<K, ValueType> _tree;
    std::list<Node*> _sortedNodeList;

    listIterator insert(Node* other);
    void deleteKey(iterator pos);

    static bool compareNodes(const Node* a, const Node* b) {
        return *a < *b;
    }
};

template <typename K, typename V>
Map<K,V>::Map() :
        _tree(),
        _sortedNodeList()
{}

template <typename K, typename V>
Map<K,V>::~Map() {
    clear();
}

template <typename K, typename V>
bool Map<K,V>::empty() const {
    return _tree.size() == 0;
}

template <typename K, typename V>
size_t Map<K,V>::size() const {
    return _tree.size();
}

template <typename K, typename V>
void Map<K,V>::clear() {
    _tree.clear(_tree.getRoot());
    _sortedNodeList.clear();
}

template <typename K, typename V>
bool Map<K,V>::contains(K& key) {
    V temp;
    return _tree.find(key, temp);
}

template <typename K, typename V>
std::pair<typename Map<K,V>::iterator, bool> Map<K,V>::insert(const ValueType& value) {
    std::pair<Node*, Node*> result = _tree.find(value.first, _tree.getRoot(), nullptr);
    if(!result.first) {
        Node* addedNode = nullptr;
        _tree.addItem(value.first, value, &addedNode);
        return std::make_pair<typename Map<K,V>::iterator, bool>(iterator(insert(addedNode)),true);
    } else {

        return std::make_pair<typename Map<K,V>::iterator, bool>(iterator(std::find(_sortedNodeList.begin(), _sortedNodeList.end(), result.first)) ,false);
    }

}

template <typename K, typename V>
typename Map<K,V>::iterator Map<K,V>::find(const K& key) {
    std::pair<Node*, Node*> result = _tree.find(key, _tree.getRoot(), nullptr);
    listIterator it =std::find(_sortedNodeList.begin(), _sortedNodeList.end(), result.first);
    return iterator(it);
}

template <typename K, typename V>
typename Map<K,V>::iterator Map<K,V>::begin() {
    return iterator(_sortedNodeList.begin());
}

template <typename K, typename V>
typename Map<K,V>::iterator Map<K,V>::end() {
    return iterator(_sortedNodeList.end());
}

template <typename K, typename V>
V&  Map<K,V>::operator[](const K& key){
    std::pair<Node*, Node*> result = _tree.find(key, _tree.getRoot(), nullptr);
    return result.first->value.second;
}

template <typename K, typename V>
void  Map<K,V>::erase(iterator pos){
    if(pos != _sortedNodeList.end()){
        Node* it = *pos.pointer;
        _tree.deleteItem(it->key);
        _sortedNodeList.clear();
        _tree.traverseInorder(_tree.getRoot(), _sortedNodeList);
    }
}

template <typename K, typename V>
typename Map<K,V>::listIterator Map<K,V>::insert(Node* other) {
    listIterator it = std::lower_bound(_sortedNodeList.begin(), _sortedNodeList.end(), other, compareNodes);
    return _sortedNodeList.insert(it, other);
}

template <typename K, typename V>
void Map<K,V>::deleteKey(iterator pos) {
    listIterator it = _sortedNodeList.erase(pos.pointer);
    std::list<Node*> _sortedNode = _sortedNodeList;
}

template <typename K, typename V>
Map<K,V>::iterator::iterator() :
    iterator(listIterator()) {
}

template <typename K, typename V>
Map<K,V>::iterator::~iterator() {
}

template <typename K, typename V>
Map<K,V>::iterator::iterator(listIterator p) :
    pointer(p)
{}

template <typename K, typename V>
V& Map<K,V>::iterator::operator*() const {
    Node* it = *pointer;
    return it->value.second;
}

template <typename K, typename V>
V* Map<K,V>::iterator::operator->() const {
    Node* it = *pointer;
    return &it->value.second;
}

template <typename K, typename V>
typename Map<K,V>::iterator& Map<K,V>::iterator::operator++(void) {
    ++pointer;
    return *this;
}

template <typename K, typename V>
typename Map<K,V>::iterator& Map<K,V>::iterator::operator--(void) {
    --pointer;
    return *this;
}

template <typename K, typename V>
typename Map<K,V>::iterator Map<K,V>::iterator::operator =(const iterator& other) {
    pointer = other.pointer;
    return *this;
}

template <typename K, typename V>
bool Map<K,V>::iterator::operator !=(const iterator& other) {
    return this->pointer != other.pointer;
}

template <typename K, typename V>
K& Map<K,V>::iterator::getKey() {
    Node* it = *pointer;
    return it->value.first;
}
#endif // MAP_H
