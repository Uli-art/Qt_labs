#include "stack.h"

Stack::Stack()
{
    head = nullptr;
    size = 0;
}

int Stack::getSize(){
    return size;
}

void Stack::push(QString newValue){
    Node* newNode = new Node();
    newNode->value = newValue;
    newNode->next = head;
    head = newNode;
    ++size;

}
QString Stack::pop(){
    if(size == 0)
        return "";
    if(size ==1){
        QString value = head->value;
        delete head;
        head = nullptr;
        size = 0;
        return value;
    }
    Node* newHead = head->next;
    QString value = head->value;
    delete head;
    head = newHead;
    --size;
    return value;
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

QString Stack::getValue(){
    return head->value;
}

