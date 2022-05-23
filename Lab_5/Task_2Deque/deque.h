#ifndef DEQUE_H
#define DEQUE_H
#include <list>
template<typename T>
class Deque
{
public:
    Deque(); 
    class iterator{
    typedef typename std::list<T*>::iterator _node_it;
    public:
        iterator() : _curr(nullptr) {};
        iterator(const iterator& other) : _curr(other._curr), _first(other._first), _last(other._last), _node(other._node) {};
        iterator(T* f, T* l, T* cur, _node_it node) : _curr(cur), _first(f), _last(l), _node(node) {};
        T& operator*() {
            return *_curr;
        }

        T* operator->() {
            return _curr;
        }

        iterator& operator++(void) {
            ++_curr;
            if(_curr == _last){
                set_node(++_node);
                _curr = _first;
            }
            return *this;
        }

        iterator operator++(int) {
            iterator tmp(*this);
            ++*this;
            return tmp;
        }

        iterator operator =(const iterator& other) {
            _curr = other._curr;
            _first = other._first;
            _last = other._last;
            _node = other._node;
            return *this;
        }

        iterator& operator--(void) {
            if(_curr == _first){
                set_node(--_node);
                _curr = _last;
            }
            --_curr;
            return *this;
        }

        iterator operator--(int) {
            iterator tmp(*this);
            --*this;
            return tmp;
        }

//        iterator operator +=(const iterator& other) {
//            this->pointer + other.pointer;
//            return *this;
//        }

//        iterator operator -=(const iterator& other) {
//            this->pointer - other.pointer;
//            return *this;
//        }

//        iterator operator -(int other) {
//            pointer -= other;
//            return *this;
//        }

        iterator operator +(int other) {
            for(int i = 0; i < other; ++i){
                ++*this;
            }
            return *this;
        }

//        int operator -(const iterator& other) {

//            return (pointer - other.pointer);
//        }

        bool operator ==(const iterator& other) {
            return _curr == other._curr;
        }

        bool operator !=(const iterator& other) {
            return _curr != other._curr;
        }

        bool operator < (const iterator& other) {
            return _curr < other._curr;
        }

        bool operator <= (const iterator& other) {
            return _curr <= other._curr;
        }

        bool operator > (const iterator& other) {
            return _curr > other._curr;
        }

        bool operator >= (const iterator& other) {
            return _curr >= other._curr;
        }

    private:
        T* _first;
        T* _last;
        T* _curr;
        _node_it _node;
        void set_node(_node_it new_node){
            //_node = ++new_node;
            _node = new_node;
            _first = *new_node;
            _last = _first + _blok_size;
        }
        friend class Deque;
    };

    void push_back(const T& newElement);
    void push_front(const T& newElement);
    void pop_back();
    void pop_front();
    void clear();
    size_t size() const;
    bool empty() const;
    void resize(size_t count);
    T& operator[](int index);
    T& front() const {
        return *_begin._curr;
    }
    T& back() const {
        iterator temp = --_end;
        return *(temp._curr);
    }
    ~Deque(){
        clear();
    }
private:
    int _size;
    static const int _blok_size = 2;
    iterator _begin;
    iterator _end;
    std::list<T*> _arrayOfPointers;

    friend class iterator;
};
template<typename T>
Deque<T>::Deque() : _size(0)
{}

template<typename T>
void Deque<T>::push_back(const T& newElement)
{
    if((_size == 0  && _arrayOfPointers.size() == 0)|| (_end._node == --_arrayOfPointers.end() && _end._curr == _end._last - 1)) {
        resize(3);
    }
    //--_end._node;

    *_end._curr = newElement;
    ++_end;
    ++_size;
}

template<typename T>
void Deque<T>::push_front(const T& newElement)
{
    if((_size == 0 && _arrayOfPointers.size() == 0) || (_begin._node == _arrayOfPointers.begin() && _begin._curr == _begin._first)) {
        resize(3);
    }
    if(_size == 0){
        ++_end;
    } else{
        --_begin;
    }
    *_begin._curr = newElement;
    ++_size;
}

template<typename T>
void Deque<T>::pop_back()
{
    if(_size == 0) {
        return;
    }
//    if(_size == 1) {
//          (_end._curr - 1)->~T();
//        _end._curr = _begin._curr = nullptr;
//        _end._first = _begin._first = nullptr;
//        _end._last = _begin._last = nullptr;
        //delete _arrayOfPointers;
     else {
        --_end;
        _end._curr->~T();
        //delete _end._curr;
    }
    --_size;
}

template<typename T>
void Deque<T>::pop_front()
{
    if(_size == 0) {
        return;
    }
//    if(_size == 1) {
//        _begin._curr->~T();
//        _end._curr = _begin._curr = nullptr;
//        _end._first = _begin._first = nullptr;
//        _end._last = _begin._last = nullptr;
        //delete _arrayOfPointers.begin();
  //  }
else {
        _begin._curr->~T();
        ++_begin;
        //delete _begin._curr;
    }
    --_size;
}

template<typename T>
void Deque<T>::resize(size_t count)
{
    if(_size == 0) {
        T* block = new T[_blok_size]();
        _arrayOfPointers.push_back(block);
        _begin._curr =  _begin._first = block;
        _begin._last = block + _blok_size;
        _begin._node = _arrayOfPointers.begin();
        _end = _begin;
        //--_begin;
    } else {
        for(int i = 0; i < count; ++i){
            _arrayOfPointers.push_back(new T[_blok_size]);
            _arrayOfPointers.push_front(new T[_blok_size]);
        }
    }
}

template<typename T>
bool Deque<T>::empty() const {
    return _size == 0;
}

template<typename T>
T& Deque<T>::operator[](int index) {
    iterator temp = _begin;
    return *(temp + index);
}

template<typename T>
size_t Deque<T>::size() const {
    return _size;
}
template<typename T>
void Deque<T>::clear()
{
    for(; _begin != _end; ++_begin){
         _begin._curr->~T();
    }
    _size = 0;
}
#endif // DEQUE_H
