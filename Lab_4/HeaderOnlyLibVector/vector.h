#ifndef VECTOR_H
#define VECTOR_H

#include <algorithm>
#include <stdio.h>
template<typename T>
class vector {
public:

    vector();
    vector(int n);
    vector(const vector& other) {
            if (_size) delete[] array;
            array = new T[other._capacity];
            for(int i = 0; i < other.size(); ++i) array[i] = other.array[i];
            _size = other.size();
            _capacity = other._capacity;
        }
    class const_iterator{

    public:
        const_iterator() : pointer(nullptr) {};

        const T& operator*() {
            return *pointer;
        }

        const T* operator->() {
            return pointer;
        }

        const_iterator& operator++(void) {
            ++pointer;
            return *this;
        }

        const_iterator operator++(int) {
            return const_iterator(pointer++);
        }

        const_iterator operator =(const const_iterator& other) {
            pointer = other.pointer;
            return *this;
        }

        const_iterator& operator--(void) {
            --pointer;
            return *this;
        }

        const_iterator operator--(int) {
            return const_iterator(pointer--);
        }

        const_iterator operator +=(const const_iterator& other) {
            this->pointer + other.pointer;
            return *this;
        }

        const_iterator operator -=(const const_iterator& other) {
            this->pointer - other.pointer;
            return *this;
        }

        const_iterator operator +(const const_iterator& other) {
            this->pointer + other.pointer;
            return *this;
        }

        const_iterator operator +(int other) {
            pointer = pointer + other;
            return *this;
        }

        int operator -(const const_iterator& other) {
            return (pointer - other.pointer);
        }

        bool operator ==(const const_iterator& other) {
            return this->pointer == other.pointer;
        }

        bool operator !=(const const_iterator& other) {
            return this->pointer != other.pointer;
        }

        bool operator < (const const_iterator other) {
            return this->pointer < other.pointer;
        }

        bool operator <= (const const_iterator& other) {
            return this->pointer <= other.pointer;
        }

        bool operator > (const const_iterator& other) {
            return this->pointer > other.pointer;
        }

        bool operator >= (const const_iterator& other) {
            return this->pointer >= other.pointer;
        }
    private:
        const T* pointer;
        const_iterator(T* data): pointer(data) {};
        friend class vector;
    };
    class iterator{
    public:
        iterator() : pointer(nullptr) {};
        iterator(const iterator& other) : pointer(other.pointer) {};

        T& operator*() {
            return *pointer;
        }

        T* operator->() {
            return pointer;
        }

        iterator& operator++(void) {
            ++pointer;
            return *this;
        }

        iterator operator++(int) {
            return iterator(pointer++);
        }

        iterator operator =(const iterator& other) {
            pointer = other.pointer;
            return *this;
        }

        iterator& operator--(void) {
            --pointer;
            return *this;
        }

        iterator operator--(int) {
            return iterator(pointer--);
        }

        iterator operator +=(const iterator& other) {
            this->pointer + other.pointer;
            return *this;
        }

        iterator operator -=(const iterator& other) {
            this->pointer - other.pointer;
            return *this;
        }

        iterator operator -(int other) {
            pointer -= other;
            return *this;
        }

        iterator operator +(int other) {
            pointer = pointer + other;
            return *this;
        }

        int operator -(const iterator& other) {

            return (pointer - other.pointer);
        }

        bool operator ==(const iterator& other) {
            return this->pointer == other.pointer;
        }

        bool operator !=(const iterator& other) {
            return this->pointer != other.pointer;
        }

        bool operator < (const iterator& other) {
            return this->pointer < other.pointer;
        }

        bool operator <= (const iterator& other) {
            return this->pointer <= other.pointer;
        }

        bool operator > (const iterator& other) {
            return this->pointer > other.pointer;
        }

        bool operator >= (const iterator& other) {
            return this->pointer >= other.pointer;
        }

    private:
        iterator(T* data) : pointer(data) {};

        T* pointer;

        friend class vector;

    };
    class reverse_iterator{
public:
        reverse_iterator() : pointer(nullptr) {};

        T& operator*() {
            return *pointer;
        }

        T* operator->() {
            return pointer;
        }

        reverse_iterator& operator++(void) {
            --pointer;
            return *this;
        }

        reverse_iterator operator++(int) {
            return const_iterator(pointer--);
        }

        reverse_iterator operator =(const reverse_iterator& other) {
            pointer = other.pointer;
            return *this;
        }

        reverse_iterator& operator--(void) {
            ++pointer;
            return *this;
        }

        reverse_iterator operator--(int) {
            return const_iterator(pointer++);
        }

        reverse_iterator operator +=(const reverse_iterator& other) {
            this->pointer - other.pointer;
            return *this;
        }

        reverse_iterator operator -=(const reverse_iterator& other) {
            this->pointer + other.pointer;
            return *this;
        }

        reverse_iterator operator +(const reverse_iterator& other) {
            this->pointer - other.pointer;
            return *this;
        }

        reverse_iterator operator +(int other) {
            pointer = pointer - other;
            return *this;
        }

        reverse_iterator operator -(const reverse_iterator& other) {
            this->pointer + other.pointer;
            return *this;
        }

        bool operator ==(const reverse_iterator& other) {
            return this->pointer == other.pointer;
        }

        bool operator !=(const reverse_iterator& other) {
            return this->pointer != other.pointer;
        }

        bool operator < (const reverse_iterator other) {
            return this->pointer < other.pointer;
        }

        bool operator <= (const reverse_iterator& other) {
            return this->pointer <= other.pointer;
        }

        bool operator > (const reverse_iterator& other) {
            return this->pointer > other.pointer;
        }

        bool operator >= (const reverse_iterator& other) {
            return this->pointer >= other.pointer;
        }
    private:
        T* pointer;

        reverse_iterator(T* data): pointer(data) {};

        friend class vector;
    };
    class const_reverse_iterator{
    public:
        const_reverse_iterator() : pointer(nullptr) {};

        const T& operator*() {
            return *pointer;
        }

        const T* operator->() {
            return pointer;
        }

        const_reverse_iterator& operator++(void) {
            --pointer;
            return *this;
        }

        const_reverse_iterator operator++(int) {
            return const_reverse_iterator(pointer--);
        }

        const_reverse_iterator operator =(const const_reverse_iterator& other) {
            pointer = other.pointer;
            return *this;
        }

        const_reverse_iterator& operator--(void) {
            ++pointer;
            return *this;
        }

        const_reverse_iterator operator--(int) {
            return const_iterator(pointer++);
        }

        const_reverse_iterator operator +=(const const_reverse_iterator& other) {
            this->pointer - other.pointer;
            return *this;
        }

        const_reverse_iterator operator -=(const const_reverse_iterator& other) {
            this->pointer + other.pointer;
            return *this;
        }

        const_reverse_iterator operator +(const const_reverse_iterator& other) {
            this->pointer - other.pointer;
            return *this;
        }

        const_reverse_iterator operator +(int other) {
            pointer = pointer - other;
            return *this;
        }

        const_reverse_iterator operator -(const const_reverse_iterator& other) {
            this->pointer + other.pointer;
            return *this;
        }

        bool operator ==(const const_reverse_iterator& other) {
            return this->pointer == other.pointer;
        }

        bool operator !=(const const_reverse_iterator& other) {
            return this->pointer != other.pointer;
        }

        bool operator < (const const_reverse_iterator& other) {
            return this->pointer < other.pointer;
        }

        bool operator <= (const const_reverse_iterator& other) {
            return this->pointer <= other.pointer;
        }

        bool operator > (const const_reverse_iterator& other) {
            return this->pointer > other.pointer;
        }

        bool operator >= (const const_reverse_iterator& other) {
            return this->pointer >= other.pointer;
        }
    private:
        const T* pointer;

        const_reverse_iterator(T* data): pointer(data) {};

        friend class vector;
    };

    void pop_back();
    void push_back(const T& x);
    void resize(int n);
    void swap(vector<T>& other);
    void reserve(size_t n);
    void clear();
    T& front() const;
    T& at(int n);
    T& back() const;
    T* data() const;
    int capacity() const;
    size_t max_size() const;
    int size() const;
    bool empty() const;
    T& operator [](int n) const {
        return array[n];
    };

    vector& operator=(const vector& other) {
        if (this != &other) {
            delete[] array;
            array = nullptr;
            array = new T[other._capacity];
            for(int i = 0; i < other.size(); ++i) array[i] = other.array[i];
            _size = other.size();
            _capacity = other.capacity();
        }
        return *this;
    }
    bool operator<(const vector<T>& tmp) const {
        T* _first = array;
        T* _other = tmp.array;

        for (int i = 0; i < _size && i < tmp._size; ++i) {
            if (_first[i] < _other[i]) {
                return true;
            }
            else if (_first[i] > _other[i]) {
                return false;
            }
        }

        return (_size < tmp._size);
    }

    bool operator>(const vector<T>& tmp){
        return tmp < this;
    }

    iterator insert(iterator position, const T& value);

    iterator insert(iterator position, size_t n , const T& value);

    iterator erase(const_iterator first, const_iterator last) ;

    void assign(iterator first, iterator last);

    template< class... Args >
    T& emplace_back( Args&&... args );

    template< class... Args >
    iterator emplace(const_iterator position ,Args&&... args );

    iterator begin() const {
        return iterator(&array[0]);
    }
    iterator end() const{
        return iterator(&array[_size]);
    }
    const_iterator cbegin() const {
        return const_iterator(&array[0]);
    }
    const_iterator cend() const {
        return const_iterator(&array[_size]);
    }
    reverse_iterator rbegin() const {
        return reverse_iterator(&array[_size - 1]);
    }
    reverse_iterator rend() const{
        return reverse_iterator(&array[-1]);
    }
    const_reverse_iterator crbegin() const{
        return const_reverse_iterator(&array[_size - 1]);
    }
    const_reverse_iterator crend() const{
        return const_reverse_iterator(&array[-1]);
    }
    ~vector();

private:
    T* array;
    int _capacity = 1;
    int _size = 0;

    void size1() {
        T* newArray = new T[_capacity];
        for (int i = 0; i < _capacity; i++)
            newArray[i] = array[i];
        delete[] array;
        array = new T[_capacity * 2];
        for (int i = 0; i < _capacity; i++)
            array[i] = newArray[i];
        delete[] newArray;
        _capacity = 2 * _capacity;
    }

    void* memmove(void* s1, const void* s2, size_t n) {
        unsigned char *pd = reinterpret_cast<unsigned char*>(s1);
        const unsigned char *ps = reinterpret_cast<const unsigned char*>(s2);
        if(ps == pd)
            return s1;
        if (ps < pd && ps + n >= pd) {
            for (pd += n, ps += n; n--;) {
                *--pd = *--ps;
            }
        }
        else {
            while(n--) {
                *pd++ = *ps++;
            }
        }
        return s1;
    }

    void deallocate(iterator it)
    {
        (*it).~T();
    }

    void deallocate(const_iterator it)
    {
        (*it).~T();
    }

    void deallocate(iterator first, iterator last) {
        for(iterator it = first; it != last; ++it) {
            deallocate(it);
        }
    }

    void deallocate(const_iterator first, const_iterator last) {
        for(const_iterator it = first; it != last; ++it) {
            deallocate(it);
        }
    }

//    int pointer_to_index(const T* p)
//    {
//        return (p - &array[0]) / sizeof(T);
//    }
};

template<typename T>
vector<T>::vector() {
    _capacity = 1;
    array = new T[1];
    _size = 0;
}

template<typename T>
vector<T>::vector(int n)
{
    _size = n;
    while(_capacity <= n){
        _capacity *= 2;
    }
    array = new T[_capacity];
    for(int i = 0; i < n; ++i){
        array[i] = T();
    }
}

template<typename T>
void vector<T>::pop_back() {
    if (_size > 0) {
        iterator it(&array[--_size]);
        deallocate(it);
    }
}

template<typename T>
void vector<T>::push_back(const T& x) {
    if (_capacity <= _size){
        int a = _capacity;
        _capacity *= 2;
        T* tmp = array;
        array = new T[_capacity];
        for (int i = 0; i < _size; ++i) array[i] = tmp[i];
        delete[] tmp;

    }
    array[_size] = x;
    _size++;
}
/*
            _capacity *= 2;
            T* tmp = array;
            array = new T[_capacity];
            for (int i = 0; i < num_of_elements; ++i) array[i] = tmp[i];
            delete[] tmp;
        }
        ++num_of_elements;
        array[num_of_elements - 1] = value;
*/
template<typename T>
void vector<T>::swap(vector<T>& other) {
    T* temp = array;
    int tempSize = _size;
    int tempTrueSize = _capacity;
    array = other.array;
    _size = other._size;
    _capacity = other._capacity;
    other.array = temp;
    other._size = tempSize;
    other._capacity = tempTrueSize;
}

template<typename T>
void vector<T>::resize(int n) {
    if(!_capacity){
        _capacity = 1;
        while (_capacity < n) {
            _capacity *= 2;
        }
        array = new T[_capacity];
        for (int i = 0; i < n; ++i) array[i] = {};
        _size = n;
    }
    else{
        while(_capacity < n){
            _capacity *= 2;
        }
        T* tmp = array;
        array = new T[_capacity];
        for (int i = 0; i < _size; ++i) array[i] = tmp[i];
        for(int i = _size; i < n; ++i) array[i] = T();
        _size = n;
        //delete tmp;
    }
}
/*
    void resize(const int& n){
        if(!_capacity){
            _capacity = 1;
            while (_capacity < n) {
                _capacity *= 2;
            }
            array = new T[_capacity];
            for (int i = 0; i < n; ++i) array[i] = {};
            num_of_elements = n;
        }
        else{
            while(_capacity < n){
                _capacity *= 2;
            }
            T* tmp = array;
            array = new T[_capacity];
            for (int i = 0; i < num_of_elements; ++i) array[i] = tmp[i];
            for(int i = num_of_elements; i < n; ++i) array[i] = 0;
            num_of_elements = n;
            delete[] tmp;
        }

    }

    if(n < _capacity) {
        return;
    }
    T* tmp = array;
    T* newArray = new T[_capacity];
    for (int i = 0; i < _capacity; i++)
        newArray[i] = array[i];

    array = new T[n];
    for (int i = 0; i < std::min(n, _capacity); i++)
        array[i] = newArray[i];
    delete[] newArray;
    _capacity = n;
    delete tmp;
*/
template<typename T>
void vector<T>::reserve(size_t n) {
    if(n < _capacity) {
        return;
    }
    resize(_capacity);
}

template<typename T>
void vector<T>::clear() {
    delete[] array;
    _capacity = 1;
    _size = 0;
    array = new T[1];
}

template<typename T>
T& vector<T>::front() const{
    return array[0];
}

template<typename T>
T& vector<T>::at(int n) {
    return array[n];
}

template<typename T>
T& vector<T>::back() const {
    return array[_size - 1];
}

template<typename T>
T* vector<T>::data() const {
    return &array[0];
}

template<typename T>
int vector<T>::capacity() const{
    return _capacity;
}

template<typename T>
size_t vector<T>::max_size() const {
    return 2^(64-sizeof(T))-1;
}

template<typename T>
int vector<T>::size() const {
    return _size;
}

template<typename T>
bool vector<T>::empty() const{
    return _size == 0;
}

template<typename T>
vector<T>::~vector() {
    deallocate(cbegin(),cend());
    //delete array;
}

template<typename T>
void vector<T>::assign(typename vector<T>::iterator first, vector<T>::iterator last) {
    deallocate(begin(), end());
    int inputSize = last.pointer - first.pointer;
    reserve(inputSize);
    iterator cur = begin();
    const_iterator e = cend();
    for(int i = 0; i < inputSize; ++i){
        *cur = *first;
        ++cur;
        ++first;
    }
//    for(; first.pointer != last.pointer && cur.pointer != e.pointer; ++cur, ++ first) {
//        *cur = *first;
//    }
//    const_iterator cur_const(cur.pointer);
   // if(cur.pointer != e.pointer)
   //     erase(cur_const + 1,e);
    _size = inputSize;
}

template<typename T>
typename vector<T>::iterator vector<T>::insert(vector<T>::iterator position, const T& value) {
    reserve(_size  + 1);
    int index = position - begin();
    if(_size != 0)
        memmove(position.pointer + 1, position.pointer, (_size - index) * sizeof(T));
    *position = value;
    ++_size;
    return position;
}

template<typename T>
typename vector<T>::iterator vector<T>::insert(vector<T>::iterator position, size_t n , const T& value) {
    bool empty = this->empty();
    if (_capacity < _size + n)
        reserve(_size + n);
    int index = position - begin();
    if(!empty)
        memmove(position.pointer + n, position.pointer, (_size - index) * sizeof(T));
    for(int i = 0; i < n; ++i) {
        array[index + i] = value;
    }
    _size += n;
    return position;
}

template<typename T>
typename vector<T>::iterator vector<T>::erase(vector<T>::const_iterator first, vector<T>::const_iterator last) {
    int inputSize = last - first;
    vector<T>::iterator returned(const_cast<T*>(first.pointer));
    vector<T>::iterator f(const_cast<T*>(first.pointer));
    deallocate(first, last);
    if(inputSize >= _size) {
        _size = 0;
    } else{
        vector<T>::iterator cur(const_cast<T*>(last.pointer));
        vector<T>::const_iterator e = cend();
        for(; f.pointer != last.pointer && cur.pointer != e.pointer; ++f, ++cur) {
            *f = *cur;
        }
        deallocate(begin() + (_size - inputSize), end());
        _size -= inputSize;
    }
    return returned;
}

template< typename T >
template< class ...Args >
T& vector<T>::emplace_back( Args&&... args ){
    reserve(_size + 1);
    new(&array[_size]) T(args...);
    ++_size;
    return array[_size];
}

template< typename T >
template< class ...Args >
typename vector<T>::iterator vector<T>::emplace(vector<T>::const_iterator position ,Args&&... args ){
    reserve(_size + 1);
    int index = position.pointer - begin().pointer;
    iterator returned(const_cast<T*>(position.pointer));
    memmove(returned.pointer + 1, returned.pointer, (_size - index) * sizeof(T));
    new(&array[index]) T(args...);
    ++_size;
    return returned;
}

#endif // VECTOR_H
