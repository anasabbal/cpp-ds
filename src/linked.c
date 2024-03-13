//
// Created by Anas on 11/3/2024.
//
#include "../include/linked.h"


void insertAtBegin(LinkedList *list, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    printf("Inserted %d at the beginning.\n", data);
}

void insertAtEnd(LinkedList *list, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    if (list->head == NULL) {
        list->head = newNode;
        printf("Inserted %d at the end.\n", data);
        return;
    }
    Node *current = list->head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    printf("Inserted %d at the end.\n", data);
}

void insertAtPosition(LinkedList* list, int data, int position) {
    if (position < 0) {
        fprintf(stderr, "Invalid position. Position must be greater than or equal to 0.\n");
        return;
    }
    if (position == 0) {
        insertAtBegin(list, data);
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }
    newNode->data = data;
    Node* current = list->head;
    Node* prev = NULL;
    for (int i = 0; i < position && current != NULL; ++i) {
        prev = current;
        current = current->next;
    }
    if (current == NULL && position > 0) {
        fprintf(stderr, "Invalid position. Position exceeds the length of the list.\n");
        free(newNode); // Free memory allocated for the new node
        return;
    }
    prev->next = newNode;
    newNode->next = current;
    printf("Inserted %d at position %d.\n", data, position);
}

Node* getByPosition(LinkedList* list, int position) {
    if (position < 0) {
        fprintf(stderr, "Invalid position. Position must be non-negative.\n");
        return NULL;
    }
    Node* current = list->head;
    int currentPosition = 0;
    while (current != NULL && currentPosition < position) {
        current = current->next;
        currentPosition++;
    }
    if (current == NULL) {
        fprintf(stderr, "Position exceeds the length of the list.\n");
    }
    return current;
}
void removeFirst(LinkedList *list) {
    if (list == NULL || list->head == NULL) {
        fprintf(stderr, "Error: List is empty.\n");
        return;
    }
    Node *current = list->head;
    list->head = current->next;

    printf("Removed first node with data: %d\n", current->data); // Log removal of the first node
    free(current);
}

void removeLast(LinkedList* list) {
    if (list == NULL || list->head == NULL) {
        fprintf(stderr, "Error: List is empty.\n");
        return;
    }
    Node *current = list->head;
    Node *prev = NULL;
    // traverse to the last node
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }
    if (prev == NULL) {
        printf("Removed last node with data: %d\n", list->head->data); // Log removal of the only node in the list
        free(list->head);
        list->head = NULL;
    } else {
        printf("Removed last node with data: %d\n", current->data); // Log removal of the last node
        prev->next = NULL;
        free(current);
    }
}
void removeByPosition(LinkedList *list, int position){
    if (list == NULL || list->head == NULL) {
        fprintf(stderr, "Error: List is empty.\n");
        return;
    }

    if (position < 0) {
        fprintf(stderr, "Error: Invalid position. Position must be non-negative.\n");
        return;
    }

    Node *prev = NULL;
    Node *current = getByPosition(list, position);

    if (current == NULL) {
        fprintf(stderr, "Error: Position exceeds the length of the list.\n");
        return;
    }
    // If the node to remove is the first node
    if (position == 0) {
        list->head = current->next;
        free(current);
        return;
    }
    prev = getByPosition(list, position - 1);
    if (prev == NULL || prev->next == NULL) {
        fprintf(stderr, "Error: Invalid position.\n");
        return;
    }
    prev->next = current->next;
    free(current);
}
void display(LinkedList* list) {
    Node* current = list->head;
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf("->");
        } else {
            printf("->NULL");
        }
        current = current->next;
    }
    printf("\n");
}