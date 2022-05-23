#include "stack.h"

Stack::Stack()
{
    head = nullptr;
    size = 0;
}

int Stack::getSize(){
    return size;
}

void Stack::push(QString newValue, int index, int number){
    Node* newNode = new Node();
    newNode->value = newValue;
    newNode->index = index;
    newNode->number = number;
    newNode->next = head;
    head = newNode;
    ++size;

}
void Stack::pop(){
    if(size == 0)
        return;
    Node* newHead = head->next;
    delete head;
    head = newHead;
    --size;
}
void Stack::clear(){
    if(size == 0)
        return;
    if(size == 1){
        delete head;
         size = 0;
         head = nullptr;
        return;
    }
    Node* newHead = head;
    for(int i = 0; i < size; ++i){
        newHead = head->next;
        delete head;
        head = newHead;
    }
    delete newHead;
    size = 0;
    head = nullptr;
}

QString Stack::getHead(){
    return head->value;
}

int Stack::getHeadIndex(){
    return head->index;
}

int Stack::getHeadSecIndex(){
    return head->number;
}
