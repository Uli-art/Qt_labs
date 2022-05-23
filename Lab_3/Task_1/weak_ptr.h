#ifndef WEAK_PTR_H
#define WEAK_PTR_H

#include "shared_ptr.h"


#include <algorithm>

template<class T>
class weak_ptr
{
public:
    weak_ptr();
    weak_ptr(weak_ptr<T> const& otherPtr);
    weak_ptr(shared_ptr<T> const& otherPtr);
    weak_ptr(T* ptr);

    ~weak_ptr();

    weak_ptr<T>& operator= (weak_ptr<T> const& other);
    weak_ptr<T>& operator= (shared_ptr<T> const& other);
    T* operator ->() const;
    T& operator *() const;

    shared_ptr<T> lock();
    bool expired();
    T* get() const;
    void reset(T* ptr);
    void swap(weak_ptr<T>& otherPtr);

private:
    void release();

    typedef typename shared_ptr<T>::detail detail;
    detail* _d;
};

template<class T>
weak_ptr<T>::weak_ptr() :
  _d(new detail()) {
}


template<class T>
weak_ptr<T>::weak_ptr(weak_ptr<T> const& otherPtr) :
    _d(otherPtr._d) {
    ++_d->bpCount;
}


template<class T>
weak_ptr<T>::weak_ptr(shared_ptr<T> const& otherPtr) :
    _d(otherPtr._d) {
    ++_d->bpCount;
}

template<class T>
weak_ptr<T>::weak_ptr(T* ptr) :
  _d(new detail(ptr)) {
}


template<class T>
weak_ptr<T>::~weak_ptr() {
    release();
}

template<class T>
weak_ptr<T>& weak_ptr<T>::operator= (weak_ptr<T> const& other) {

    if(_d == other._d) {
        return *this;
    }

    release();

    _d = other._d;
    ++_d->bpCount;

    return *this;
}

template<class T>
weak_ptr<T>& weak_ptr<T>::operator= (shared_ptr<T> const& other) {
    if(_d == other._d) {
        return *this;
    }

    release();

    _d = other._d;
    ++_d->bpCount;

    return *this;
}

template<class T>
T* weak_ptr<T>::operator ->() const {
    return _d->ptr;
}

template<class T>
T& weak_ptr<T>::operator *() const {
    return *_d->ptr;
}


template<class T>
bool weak_ptr<T>::expired(){
    return _d->ptr == nullptr;
}

template<class T>
shared_ptr<T> weak_ptr<T>::lock(){
    return shared_ptr<T>(_d);
}

template<class T>
void weak_ptr<T>::release() {
    if(--_d->bpCount == 0) {
        delete _d;
    }

    _d = nullptr;
}

template<class T>
T* weak_ptr<T>::get() const {
    return _d->ptr;
}

template<class T>
void weak_ptr<T>::reset(T* ptr){
    release();
    _d = new detail(ptr);
}

template<class T>
void weak_ptr<T>::swap(weak_ptr<T>& otherPtr) {
    if(_d == otherPtr._d)
        return;
    std::swap(_d, otherPtr._d);
}

#endif // WEAK_PTR_H
