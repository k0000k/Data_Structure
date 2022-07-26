#include "list.h"
#include <iostream>

Node::Node(){
    next = nullptr;
    prev = nullptr;
}

LinkedList::LinkedList(){
    head = nullptr;
    tail = nullptr;
}

void LinkedList::Append(int data){
    Node* n = new Node;
    count += 1;

    n->data = data;

    if (head == nullptr){
        head = n;
        tail = n;
    }

    else{
        tail->next = n;
        n->prev = tail;
        tail = n;
    }

}

void LinkedList::Prepend(int data){
    Node* n = new Node;
    count += 1;

    n->data = data;

    if (head == nullptr){
        head = n;
        tail = n;
    }

    else{
        n->next = head;
        head->prev = n;
        head = n;
    }

}

int LinkedList::Length(){
    return count;
}

void LinkedList::Print(){
    Node* temp_ptr = head;
    for(int i = 0; i < count; i++){
        cout<<temp_ptr -> data<<" ";
        temp_ptr = temp_ptr -> next;
    }
    cout<<endl;
}

void LinkedList::PrintReverse(){
    Node* temp_ptr = tail;
    for(int i = 0; i < count; i++){
        cout<<temp_ptr -> data<<" ";
        temp_ptr = temp_ptr -> prev;
    }
    cout<<endl;
}
