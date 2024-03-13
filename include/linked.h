//
// Created by Anas on 11/3/2024.
//

#ifndef LINKED_H
#define LINKED_H

#include <stdio.h>
#include <stdlib.h>

// node structure
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// linked list structure
typedef struct LinkedList {
    Node* head;
} LinkedList;

// function prototypes
LinkedList* createLinkedList();
// destroy
void destroyLinkedList(LinkedList* list);
// insert
void insertAtBegin(LinkedList* list, int data);
void insertAtEnd(LinkedList* list, int data);
void insertAtPosition(LinkedList* list, int data, int position);
// get
Node* getByPosition(LinkedList* list, int position);
// remove
void removeFirst(LinkedList *list);
void removeLast(LinkedList* list);
void removeByPosition(LinkedList *list, int position);
// display
void display(LinkedList* list);

#endif 