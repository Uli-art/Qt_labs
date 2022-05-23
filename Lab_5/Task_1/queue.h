#ifndef QUEUE_H
#define QUEUE_H
#include "../Task_2Deque/deque.h"
#include <deque>
#include <memory>

template<typename T, typename C = Deque<T> >
class queue
{
public:
    const T& front() const
    {
        return _container.front();
    }

    const T& back() const
    {
        return _container.back();
    }

    bool empty() const
    {
        return _container.empty();
    }

    size_t size() const
    {
        return _container.size();
    }

    void push(const T& newElement)
    {
        _container.push_back(newElement);
    }

    void pop()
    {
        _container.pop_front();
    }

private:
    C _container;
};


template<typename T>
class Queue
{
public:
    Queue();
    Queue(const Queue& other);
    Queue& operator =(const Queue& other);
    T& front() const;
    T& back() const;
    bool empty() const;
    int size() const;
    void push(const T& newElement);
    template< class... Args >
    void emplace( Args&&... args );
    void pop();
    void swap(Queue& other);
    ~Queue();

private:
    struct Node
    {
        T data;
        std::shared_ptr<Node> next;
        std::weak_ptr<Node> prev;
    public:
        Node(const T& element) : data(element)
        {}

        template<class... Args>
        Node(Args&&... args) : data(args...)
        {}
    };

    std::shared_ptr<Node> _head;
    std::weak_ptr<Node> _tail;
    int _size;
};

template<typename T>
Queue<T>::Queue() :
    _size(0)
{
}
template<typename T>
Queue<T>::Queue(const Queue& other){
    std::shared_ptr<Node> temp = other._head;
    while(temp != nullptr) {
        push(temp->data);
        temp = temp->next;
    }
}
template<typename T>
Queue<T>& Queue<T>::operator =(const Queue& other){
    while(_head != nullptr){
        pop();
    }
    Node* temp = other._head;
    while(temp != nullptr){
        push(temp->data);
        temp = temp->next;
    }
}
template<typename T>
T& Queue<T>::front() const {
    return _head->data;
}
template<typename T>
T& Queue<T>::back() const {
    return _tail.lock()->data;
}
template<typename T>
bool Queue<T>::empty() const{
    return _size == 0;
}
template<typename T>
int Queue<T>::size() const{
    return _size;
}
template<typename T>
void Queue<T>::push(const T& newElement) {
    std::shared_ptr<Node> newNode = std::make_shared<Node>(newElement);
    if (empty())
    {
        _head = newNode;
        _tail = _head;
    }
    else
    {
        _tail.lock()->next = newNode;
        newNode->prev = _tail;
        _tail = newNode;
    }

    ++_size;
}

template<typename T>
template< class... Args >
void Queue<T>::emplace(Args&&... args) {
    std::shared_ptr<Node> newNode = std::make_shared<Node>(args...);
    if (empty())
    {
        _head = newNode;
        _tail = _head;
    }
    else
    {
        _tail.lock()->next = newNode;
        newNode->prev = _tail;
        _tail = newNode;
    }

    ++_size;
}

template<typename T>
void Queue<T>::pop() {
    if (empty()) {
        return;
    }

    _head = _head->next;
    --_size;

    if (empty())
    {
        _tail.reset();
    }
    else
    {
        _head->prev.reset();
    }
}

template<typename T>
void Queue<T>::swap(Queue& other) {
    std::swap(_head, other._head);
    std::swap(_tail, other._tail);
    std::swap(_size, other._size);
}

template<typename T>
Queue<T>::~Queue()
{

}

#endif // QUEUE_H
