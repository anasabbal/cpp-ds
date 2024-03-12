//
// Created by Anas on 11/3/2024.
//
#include "../include/linked.h"

LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void LinkedList::insertAtBegin(int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void LinkedList::insertAtEnd(int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

void LinkedList::insertAtPosition(int data, int position) {
    if (position < 0) {
        std::cerr << "Invalid position. Position must be greater than or equal to 0.\n";
        return;
    }
    if (position == 0) {
        insertAtBegin(data);
        return;
    }
    Node* newNode = new Node(data);
    Node* current = head;
    Node* prev = nullptr;
    for (int i = 0; i < position && current != nullptr; ++i) {
        prev = current;
        current = current->next;
    }
    if (current == nullptr && position > 0) {
        std::cerr << "Invalid position. Position exceeds the length of the list.\n";
        delete newNode; // Free memory allocated for the new node
        return;
    }
    prev->next = newNode;
    newNode->next = current;
}

void LinkedList::display() {
    Node* current = head;
    std::cout << "Linked List: ";
    while (current != nullptr) {
        std::cout << current->data;
        if (current->next != nullptr) {
            std::cout << "->";
        } else {
            std::cout << "->NULL";
        }
        current = current->next;
    }
    std::cout << std::endl;
}