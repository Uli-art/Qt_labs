#include "list.h"

List::List()
{
    head = tail = nullptr;
    size = 0;
}

List::~List()
{
   clear();
}

void List::addNode(Book newBook){
    Node* newNode = new Node();
    newNode->data = newBook;
    newNode->next = nullptr;
    if(head == nullptr){
        newNode->prev = nullptr;
        head = newNode;
    } else{
        Node *current = head;
        while(current->next != nullptr){
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
    ++size;
    tail = newNode;
}

void List::deleteNode(int index){
    if(head == nullptr){
        return;
    }
    if(size == 1){
        delete head;
        head = tail = nullptr;
        size = 0;
        return;
    }
    Node *current = head;
    for(int i = 0;i < index; ++i){
        current = current -> next;
    }

    if(current->next == nullptr){
        current->prev->next = nullptr;
        delete current;
    } else if(current->prev == nullptr){
        current->next->prev = nullptr;
        head = current->next;
        delete current;
    } else{
         current->prev->next = current->next;
         current->next->prev = current->prev;
         delete current;
    }
    --size;
}

void List::clear(){
    if(head == nullptr){
        return;
    }
    if(size == 1){
        delete head;
        return;
    } else{
        Node *temp = head;
        for(int i = 0; i < size; ++i){
            Node *next = temp->next;
            delete temp;
            temp = next;
        }
    }
    head = nullptr;
    size = 0;
}

int List::getSize(){
    return size;
}

Node* List::getHead(){
    return head;
}

Node* List::find(int index){
    if(index >= size){
        return 0;
    }
    Node *current = head;
    for(int i = 0; i < index; ++i){
        current = current->next;
    }
    return current;
}

void List::setHead(Node * newHead){
    head = newHead;
}
