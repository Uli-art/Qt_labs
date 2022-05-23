#include "list.h"

List::List()
{
    array = new Node[1];
    size = 0;
    capacity = 1;
    head = nullptr;
}

void List::addCall(Calls newCall){
    if(head == nullptr){
        Node *newNode = new Node();
        newNode->call = newCall;
        newNode->next = -1;
        newNode->prev = -1;
        head = newNode;
        array[size] = *newNode;
    }
    else{
        int index = 0;
        Node* tail;
        for(int i = 0; i < size; ++i){
            if(array[i].next == -1 && array[i].show){
                index = i;
                tail = &array[i];
            }
        }
        Node *newNode = new Node();
        newNode->call = newCall;
        newNode->next = -1;
        tail->next = size;
        newNode->prev = index;
        if(size >= capacity){
            array = grow();
        }
        array[size] = *newNode;
    }
    ++size;
}
void List::deleteCall(int index){
    array[index].show = false;
    Node* deleted = &array[index];
    array[deleted->prev].next = deleted->next;
    array[deleted->next].prev = deleted->prev;

}

void List::clear(){
    if(head == nullptr){
        return;
    }
    if(size == 1){
        delete head;
        head = nullptr;
        //return;
    }
    Node* newArray = new Node[1];
    capacity = 1;
    size = 0;
    delete[] array;
    array = newArray;
}

Node* List::grow(){
    Node *newArray = new Node[capacity * 2];
    capacity *= 2;
    for(int i = 0; i < size; ++i){
        newArray[i] = array[i];
    }
    return newArray;
}

int List::getSize(){
    return size;
}

Node* List::getArray(){
    return array;
}
