#ifndef HASMAP_H
#define HASMAP_H

#include <memory>
#include <stack>
#include <ostream>

template <class K, class V, class Hash = std::hash<K> >
class HashMapStack {
public:
    typedef K KeyType;
    typedef V MappedType;
    typedef std::pair<K, V> ValueType;
    typedef Hash HashFunc;
    typedef std::stack<ValueType> ValueCont;

    HashMapStack(size_t bucketCount);
    ~HashMapStack();

    size_t getSize() const;
    size_t getBucketCount() const;
    const ValueCont& getBucketValues(size_t bucketIndex) const;
    void clear();

    bool insert(const ValueType& value);
    V& operator[] (const K& key);
    bool contains(const K& key) const;
    size_t erase(const K& key);

    float getLoad() const;
    bool maxLoadIsExceeded() const;
    float getMaxloadFactor() const;
    void setMaxLoadFactor(float maxLoadFactor);
    void rehash(size_t newBucketCount);

    template <class Pred>
    size_t extractValues(HashMapStack<K, V, Hash>& to, Pred pred);

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
HashMapStack<K, V, Hash>::HashMapStack(size_t bucketCount) :
    _bucketCount(bucketCount),
    _hashTable(new ValueCont[bucketCount]),
    _hashFunc(),
    _elementCount(0),
    _maxLoadFactor(1.0) {

}

template <class K, class V, class Hash>
HashMapStack<K, V, Hash>::~HashMapStack() {
    delete [] _hashTable;
}

template <class K, class V, class Hash>
const typename HashMapStack<K, V, Hash>::ValueCont& HashMapStack<K, V, Hash>::getBucketValues(size_t bucketIndex) const {
    return _hashTable[bucketIndex];
}

template <class K, class V, class Hash>
size_t HashMapStack<K, V, Hash>::getBucketCount() const {
    return _bucketCount;
}

template <class K, class V, class Hash>
size_t HashMapStack<K, V, Hash>::getSize() const {
    return _elementCount;
}

template <class K, class V, class Hash>
void HashMapStack<K, V, Hash>::clear() {
    for (size_t i = 0; i < _bucketCount; ++i) {
        ValueCont empty;
        _hashTable[i].swap(empty);
    }

    _elementCount = 0;
}

template <class K, class V, class Hash>
bool HashMapStack<K, V, Hash>::insert(const ValueType& value) {
    size_t bucket = getBucketForKey(value.first);

    ValueCont& bucketValues = _hashTable[bucket];
    ValueCont temp;
    temp.swap(bucketValues);

    bool keyFound = false;
    while (!temp.empty()) {
        bucketValues.push(temp.top());

        if (bucketValues.top().first == value.first) {
            keyFound = true;
        }

        temp.pop();
    }

    if (!keyFound) {
        bucketValues.push(value);
        ++_elementCount;

        if (maxLoadIsExceeded()) {
            rehash(_bucketCount * 2);
        }

        return true;
    }

    return false;
}

template <class K, class V, class Hash>
V& HashMapStack<K, V, Hash>::operator[] (const K& key) {
    size_t bucket = getBucketForKey(key);

    ValueCont& bucketValues = _hashTable[bucket];
    ValueCont temp;
    temp.swap(bucketValues);

    V* foundMappedValue = nullptr;
    while (!temp.empty()) {
        bucketValues.push(temp.top());

        if (bucketValues.top().first == key) {
            foundMappedValue = &bucketValues.top().second;
        }

        temp.pop();
    }

    if (foundMappedValue == nullptr) {
        bucketValues.push(ValueType(key, V()));
        foundMappedValue = &bucketValues.top().second;
        ++_elementCount;
    }

    if (maxLoadIsExceeded()) {
        rehash(_bucketCount * 2);
        return operator[](key);
    }

    return *foundMappedValue;
}


template <class K, class V, class Hash>
bool HashMapStack<K, V, Hash>::contains(const K& key) const {
    size_t bucket = getBucketForKey(key);

    ValueCont& bucketValues = _hashTable[bucket];
    ValueCont temp;
    temp.swap(bucketValues);

    bool keyFound = false;
    while (!temp.empty()) {
        bucketValues.push(temp.top());

        if (bucketValues.top().first == key) {
            keyFound = true;
        }

        temp.pop();
    }

    return keyFound;
}

template <class K, class V, class Hash>
size_t HashMapStack<K, V, Hash>::erase(const K& key) {
    size_t bucket = getBucketForKey(key);

    size_t result = 0;
    ValueCont& bucketValues = _hashTable[bucket];
    ValueCont temp;
    while (!bucketValues.empty()) {
        if (bucketValues.top().first != key) {
            temp.push(bucketValues.top());
        }
        else {
            ++result;
            --_elementCount;
        }

        bucketValues.pop();
    }

    bucketValues.swap(temp);
    return result;
}

template <class K, class V, class Hash>
float HashMapStack<K, V, Hash>::getLoad() const {
    return float(_elementCount) / float(_bucketCount);
}

template <class K, class V, class Hash>
bool HashMapStack<K, V, Hash>::maxLoadIsExceeded() const {
    return getLoad() > getMaxloadFactor();
}

template <class K, class V, class Hash>
float HashMapStack<K, V, Hash>::getMaxloadFactor() const {
    return _maxLoadFactor;
}

template <class K, class V, class Hash>
void HashMapStack<K, V, Hash>::setMaxLoadFactor(float maxLoadFactor) {
    _maxLoadFactor = maxLoadFactor;
}

template <class K, class V, class Hash>
void HashMapStack<K, V, Hash>::rehash(size_t newBucketCount) {
    ValueCont* newHashTable = new ValueCont[newBucketCount];

    for (size_t i = 0; i < _bucketCount; ++i) {
        ValueCont& bucketValues = _hashTable[i];

        while (!bucketValues.empty()) {
            ValueType& value = bucketValues.top();

            int newBucket = _hashFunc(value.first) % newBucketCount;
            newHashTable[newBucket].push(value);

            bucketValues.pop();
        }
    }

    std::swap(_hashTable, newHashTable);
    std::swap(_bucketCount, newBucketCount);

    delete [] newHashTable;
}

template <class K, class V, class Hash>
template<class Pred>
size_t HashMapStack<K, V, Hash>::extractValues(HashMapStack<K, V, Hash>& to, Pred pred) {

    size_t extractedCount = 0;
    for (size_t i = 0; i < _bucketCount; ++i) {
        ValueCont& bucketValues = _hashTable[i];
        ValueCont temp;

        while (!bucketValues.empty()) {
            const ValueType& value = bucketValues.top();
            if (pred(value.first)) {
                to.insert(value);
                --_elementCount;
                ++extractedCount;
            }
            else {
                temp.push(value);
            }

            bucketValues.pop();
        }

        bucketValues.swap(temp);
    }

    return extractedCount;
}

template <class K, class V, class Hash>
size_t HashMapStack<K, V, Hash>::getBucketForKey(const K& key) const {
    return _hashFunc(key) % _bucketCount;
}

#endif // HASMAP_H
