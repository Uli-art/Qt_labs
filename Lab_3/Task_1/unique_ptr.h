#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H

#include <algorithm>

template<class T>
class unique_ptr
{
public:
    unique_ptr();
    unique_ptr(T* ptr);
    unique_ptr(unique_ptr&& other);

    ~unique_ptr();

    T* operator ->() const;
    T& operator *() const;
    unique_ptr<T>& operator = ( unique_ptr<T>&& otherPtr);
    operator bool() const;

    T* get() const;
    void reset(T* newPtr);
    void swap(unique_ptr<T>& other);
private:
    T* _ptr;
    T* release();
};

template<class T>
unique_ptr<T>::unique_ptr() :
    _ptr(nullptr)
{
}

template<class T>
unique_ptr<T>::unique_ptr(T* ptr) :
    _ptr(ptr)
{
}

template<class T>
unique_ptr<T>::unique_ptr(unique_ptr&& other) :
    _ptr(other._ptr)
{
    other._ptr = nullptr;
}

template<class T>
unique_ptr<T>::~unique_ptr()
{
    delete _ptr;
}

template<class T>
void unique_ptr<T>::swap(unique_ptr<T>& other)
{
    std::swap(_ptr, other._ptr);
}

template<class T>
T* unique_ptr<T>::operator ->() const {
    return get();
}

template<class T>
T& unique_ptr<T>::operator *() const {
    return *_ptr;
}

template<class T>
unique_ptr<T>& unique_ptr<T>::operator= (unique_ptr<T>&& otherPtr)
{
    reset(otherPtr.release());
    return *this;
}

template<class T>
T* unique_ptr<T>::get() const {
    return _ptr;
}

template<class T>
unique_ptr<T>::operator bool() const {
    return _ptr != nullptr;
}

template<class T>
void unique_ptr<T>::reset(T* newPtr){
    delete _ptr;
    _ptr = newPtr;
}

template<class T>
T* unique_ptr<T>::release(){
    T* tmp = _ptr;
    _ptr = nullptr;
    return tmp;
}
#endif // UNIQUE_PTR_H
