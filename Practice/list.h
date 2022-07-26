#pragma once

using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node *prev;

    Node();
};

class LinkedList{
public:
    Node *head;
    Node *tail;
    int count = 0;

    LinkedList();
    void Append(int data);
    void Prepend(int data);
    int Length();
    void Print();
    void PrintReverse();
};
