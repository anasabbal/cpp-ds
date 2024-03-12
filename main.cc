#include <iostream>
#include <cstdlib> // for exit()
#include "../include/linked.h"

void handleLinkedList(LinkedList &myList) {
    int insertChoice, data, position;
    char exitKey;
    do {
        std::cout << "Linked List selected. Choose insertion type:\n";
        std::cout << "1. Insert at the beginning\n";
        std::cout << "2. Insert at the end\n";
        std::cout << "3. Insert at specific position\n";
        std::cout << "Enter your choice (1/2/3): ";
        std::cin >> insertChoice;

        switch (insertChoice) {
            case 1:
                std::cout << "Enter data to insert at the beginning: ";
                std::cin >> data;
                myList.insertAtBegin(data);
                std::cout << "Node inserted at the beginning.\n";
                break;
            case 2:
                std::cout << "Enter data to insert at the end: ";
                std::cin >> data;
                myList.insertAtEnd(data);
                std::cout << "Node inserted at the end.\n";
                break;
            case 3:
                std::cout << "Enter data to insert at the end: ";
                std::cin >> data;
                std::cout << "Enter position : ";
                std::cin >> position;
                myList.insertAtPosition(data, position);
                break;
            case 4:
                std::cout << "Enter data to insert at the end: ";
                std::cin >> data;
                myList.insertAtEnd(data);
                std::cout << "Node inserted at the end.\n";
                break;
            default:
                std::cerr << "Invalid choice. Exiting program.\n";
                exit(EXIT_FAILURE);
        }
        std::cout << "Updated Linked List:\n";
        myList.display(); // Display the linked list after each operation

        std::cout << "Do you want to continue? (y/n): ";
        std::cin >> exitKey;
    } while (exitKey == 'y' || exitKey == 'Y');
}

void handleChoice(int choice) {
    switch (choice) {
        case 1: {
            LinkedList list;
            handleLinkedList(list);
            break;
        }
        case 2:
            // Handle Stack
            break;
        case 3:
            // Handle Queue
            break;
        default:
            std::cerr << "Invalid choice. Exiting program.\n";
            exit(EXIT_FAILURE);
    }
}

int main() {
    int choice;
    std::cout << "Select a data structure!" << std::endl;
    std::cout << "1. Linked List\n";
    std::cout << "2. Stack\n";
    std::cout << "3. Queue\n";
    std::cout << "Enter your choice (1/2/3): ";
    std::cin >> choice;

    handleChoice(choice);
    return 0;
}
