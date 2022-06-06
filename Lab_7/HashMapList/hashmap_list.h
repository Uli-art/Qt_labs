#ifndef HASMAP_LIST_H
#define HASMAP_LIST_H

#include <memory>
#include <list>
#include <ostream>

template <class K, class V, class Hash = std::hash<K> >
class HashMapList {
public:
    typedef K KeyType;
    typedef V MappedType;
    typedef std::pair<K, V> ValueType;
    typedef Hash HashFunc;
    typedef std::list<ValueType> ValueCont;

    HashMapList(size_t bucketCount);
    ~HashMapList();

    size_t getSize() const;
    size_t getBucketCount() const;
    const ValueCont& getBucketValues(size_t bucketIndex) const;
    void clear();

    bool insert(const ValueType& value);
    V& operator[] (const K& key);
    size_t erase(const K& key);
    bool contains(const K& key) const;

    float getLoad() const;
    bool maxLoadIsExceeded() const;
    float getMaxloadFactor() const;
    void setMaxLoadFactor(float maxLoadFactor);
    void rehash(size_t newBucketCount);

private:
    size_t getBucketForKey(const K& key) const;

private:
    size_t _bucketCount;
    ValueCont* _hashTable;
    HashFunc _hashFunc;
    size_t _elementCount;
    float _maxLoadFactor;
};

template <class K, class V, class Hash>
HashMapList<K, V, Hash>::HashMapList(size_t bucketCount) :
    _bucketCount(bucketCount),
    _hashTable(new ValueCont[bucketCount]),
    _hashFunc(),
    _elementCount(0),
    _maxLoadFactor(1.0) {

}

template <class K, class V, class Hash>
HashMapList<K, V, Hash>::~HashMapList() {
    delete [] _hashTable;
}

template <class K, class V, class Hash>
size_t HashMapList<K, V, Hash>::getBucketCount() const {
    return _bucketCount;
}

template <class K, class V, class Hash>
const typename HashMapList<K, V, Hash>::ValueCont& HashMapList<K, V, Hash>::getBucketValues(size_t bucketIndex) const {
    return _hashTable[bucketIndex];
}

template <class K, class V, class Hash>
size_t HashMapList<K, V, Hash>::getSize() const {
    return _elementCount;
}

template <class K, class V, class Hash>
void HashMapList<K, V, Hash>::clear() {
    for (size_t i = 0; i < _bucketCount; ++i) {
        _hashTable[i].clear();
    }

    _elementCount = 0;
}

template <class K, class V, class Hash>
bool HashMapList<K, V, Hash>::insert(const ValueType& value) {
    size_t bucket = getBucketForKey(value.first);

    ValueCont& bucketValues = _hashTable[bucket];
    for (typename ValueCont::iterator it = bucketValues.begin(); it != bucketValues.end(); ++it) {
        if (it->first == value.first) {
            return false;
        }
    }

    bucketValues.push_back(value);
    ++_elementCount;

    if (maxLoadIsExceeded()) {
        rehash(_bucketCount * 2);
    }

    return true;
}

template <class K, class V, class Hash>
V& HashMapList<K, V, Hash>::operator[] (const K& key) {
    size_t bucket = getBucketForKey(key);

    ValueCont& bucketValues = _hashTable[bucket];
    for (typename ValueCont::iterator it = bucketValues.begin(); it != bucketValues.end(); ++it) {
        if (it->first == key) {
            return it->second;
        }
    }

    bucketValues.push_back(ValueType(key, V()));
    ++_elementCount;

    if (maxLoadIsExceeded()) {
        rehash(_bucketCount * 2);
        return operator[](key);
    }

    return bucketValues.back().second;
}

template <class K, class V, class Hash>
bool HashMapList<K, V, Hash>::contains(const K& key) const {
    size_t bucket = getBucketForKey(key);

    ValueCont& bucketValues = _hashTable[bucket];
    for (typename ValueCont::iterator it = bucketValues.begin(); it != bucketValues.end(); ++it) {
        if (it->first == key) {
            return true;
        }
    }

    return false;
}

template <class K, class V, class Hash>
size_t HashMapList<K, V, Hash>::erase(const K& key) {
    size_t bucket = getBucketForKey(key);
    ValueCont& bucketValues = _hashTable[bucket];
    for (typename ValueCont::iterator it = bucketValues.begin(); it != bucketValues.end(); ++it) {
        if (it->first == key) {
            bucketValues.erase(it);
            --_elementCount;

            return 1;
        }
    }

    return 0;
}

template <class K, class V, class Hash>
float HashMapList<K, V, Hash>::getLoad() const {
    return float(_elementCount) / float(_bucketCount);
}

template <class K, class V, class Hash>
bool HashMapList<K, V, Hash>::maxLoadIsExceeded() const {
    return getLoad() > getMaxloadFactor();
}

template <class K, class V, class Hash>
float HashMapList<K, V, Hash>::getMaxloadFactor() const {
    return _maxLoadFactor;
}

template <class K, class V, class Hash>
void HashMapList<K, V, Hash>::setMaxLoadFactor(float maxLoadFactor) {
    _maxLoadFactor = maxLoadFactor;
}

template <class K, class V, class Hash>
void HashMapList<K, V, Hash>::rehash(size_t newBucketCount) {
    if (newBucketCount == 0) {
        return;
    }

    ValueCont* newHashTable = new ValueCont[newBucketCount];

    for (size_t i = 0; i < _bucketCount; ++i) {
        ValueCont& bucketValues = _hashTable[i];
        for (typename ValueCont::iterator it = bucketValues.begin(); it != bucketValues.end(); ++it) {
            int newBucket = _hashFunc(it->first) % newBucketCount;
            newHashTable[newBucket].push_back(*it);
        }
    }

    std::swap(_hashTable, newHashTable);
    std::swap(_bucketCount, newBucketCount);

    delete [] newHashTable;
}

template <class K, class V, class Hash>
size_t HashMapList<K, V, Hash>::getBucketForKey(const K& key) const {
    return _hashFunc(key) % _bucketCount;
}

#endif // HASMAP_LIST_H
