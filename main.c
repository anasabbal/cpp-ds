#include <stdio.h>
#include <stdlib.h>
#include "include/linked.h"


//linked list
void handleLinkedList(LinkedList* myList);
void handleChoice();


int main() {
    int choice;
    printf("Select a data structure!\n");
    printf("1. Linked List\n");
    printf("2. Stack\n");
    printf("3. Queue\n");
    printf("Enter your choice (1/2/3): ");
    scanf("%d", &choice);

    handleChoice(choice);
    return 0;
}

void handleChoice(int choice) {
    switch (choice) {
        case 1: {
            LinkedList list;
            handleLinkedList(&list);
            break;
        }
        case 2:
            // Handle Stack
            break;
        case 3:
            // Handle Queue
            break;
        default:
            fprintf(stderr, "Invalid choice. Exiting program.\n");
            exit(EXIT_FAILURE);
    }
}

void handleLinkedList(LinkedList* myList) {
    int insertChoice, data, position;
    char exitKey;
    do {
        printf("Linked List selected. Choose insertion type:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at specific position\n");
        printf("4. Remove First\n");
        printf("5. Remove Last\n");
        printf("6. Remove at position\n");
        printf("7. Get by position\n");
        printf("Enter your choice (1/2/3): ");
        scanf("%d", &insertChoice);

        switch (insertChoice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBegin(myList, data);
                printf("Node inserted at the beginning.\n");
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(myList, data);
                printf("Node inserted at the end.\n");
                break;
            case 3:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                printf("Enter position : ");
                scanf("%d", &position);
                insertAtPosition(myList, data, position);
                break;
            case 4:
                printf("Removing First Node from Linked List");
                removeFirst(myList);
                break;
            case 5:
                printf("Removing Last Node from Linked List");
                removeLast(myList);
                break;
            case 6:
                printf("Enter position to remove node form it: ");
                scanf("%d", &position);
                removeByPosition(myList, position);
                break;
            case 7:
                printf("Enter position to get node by it: ");
                scanf("%d", &position);
                getByPosition(myList, position);
                break;
            default:
                fprintf(stderr, "Invalid choice. Exiting program.\n");
                exit(EXIT_FAILURE);
        }
        printf("Updated Linked List:\n");
        display(myList); // Display the linked list after each operation

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &exitKey);
    } while (exitKey == 'y' || exitKey == 'Y');
}