//
// Created by Anas on 11/3/2024.
//

#ifndef LINKED_H
#define LINKED_H

#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}
    ~LinkedList();
    void insertAtBegin(int data);
    void insertAtEnd(int data);
    void insertAtPosition(int data, int position);
    void display();
};

#endif // LINKED_H
