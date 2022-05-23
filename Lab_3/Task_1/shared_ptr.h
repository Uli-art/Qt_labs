#ifndef SHARED_PTR_H
#define SHARED_PTR_H

#include <algorithm>

template<class T>
class shared_ptr
{
public:
    shared_ptr();
    shared_ptr(shared_ptr<T> const& otherPtr);
    shared_ptr(T* ptr);

    ~shared_ptr();

    shared_ptr<T>& operator = (const shared_ptr<T>& otherPtr);
    T* operator ->() const;
    T& operator *() const;
    operator bool() const;
    T* get() const;
    void swap(shared_ptr<T>& otherPtr);
    bool unique() const;
    size_t use_count() const;
    size_t bp_count() const;
    void reset(T* ptr);
    bool owner_before(const shared_ptr<T>& ptr) const;

private:
    struct detail
    {
        T* ptr;
        size_t useCount;
        size_t bpCount;

        detail() :
            ptr(nullptr),
            useCount(0),
            bpCount(1)
        {
        }

        detail(T* p) :
            ptr(p),
            useCount(1),
            bpCount(1)
        {
        }
    };

    void copyFrom(shared_ptr<T> const& otherPtr);
    void release();

    shared_ptr(detail* d);

    detail* _d;

    template<class Y> friend class weak_ptr;
};

template<class T>
shared_ptr<T>::shared_ptr() :
    _d(new detail()) {
}

template<class T>
shared_ptr<T>::shared_ptr(T* ptr) :
    _d(new detail(ptr)) {

}

template<class T>
shared_ptr<T>::shared_ptr(shared_ptr const& otherPtr) {
    this->copyFrom(otherPtr);
}

template<class T>
shared_ptr<T>::shared_ptr(detail* other) :
    _d(other) {
    ++_d->bpCount;

    if (_d->ptr != nullptr) {
        ++_d->useCount;
    }
}

template<class T>
shared_ptr<T>::~shared_ptr() {
    release();
}

template<class T>
void shared_ptr<T>::copyFrom(shared_ptr<T> const& otherPtr){
    _d = otherPtr._d;

    ++_d->bpCount;
    if(_d->ptr != nullptr)
    {
        ++_d->useCount;
    }
}

template<class T>
shared_ptr<T>& shared_ptr<T>::operator= (const shared_ptr<T>& otherPtr)
{
    if(_d == otherPtr._d) {
        return *this;
    }

    release();
    copyFrom(otherPtr);
}

template<class T>
void shared_ptr<T>::release(){
    if(_d->ptr != nullptr && --_d->useCount == 0){
        delete _d->ptr;
        _d->ptr = nullptr;
    }
    if(--_d->bpCount == 0){
        delete _d;
    }

    _d = nullptr;
}

template<class T>
T* shared_ptr<T>::operator ->() const {
    return _d->ptr;
}

template<class T>
T& shared_ptr<T>::operator *() const {
    return *_d->ptr;
}

template<class T>
T* shared_ptr<T>::get() const {
    return _d->ptr;
}

template<class T>
shared_ptr<T>::operator bool() const {
    if(_d->ptr != nullptr){
        return true;
    }
    return false;
}

template<class T>
void shared_ptr<T>::swap(shared_ptr<T>& otherPtr) {
    if(_d == otherPtr._d)
        return;
    std::swap(_d, otherPtr._d);
}

template<class T>
bool shared_ptr<T>::unique() const {
    return _d->useCount == 1;
}

template<class T>
size_t shared_ptr<T>::use_count() const {
    return _d->useCount;
}

template<class T>
size_t shared_ptr<T>::bp_count() const {
    return _d->bpCount;
}

template<class T>
void shared_ptr<T>::reset(T* ptr){
    release();
    _d = new detail(ptr);
}

template<class T>
bool shared_ptr<T>::owner_before(const shared_ptr& ptr) const {
    return _d < ptr._d;
}

#endif // SHARED_PTR_H
