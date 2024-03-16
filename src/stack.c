#include <stdlib.h> // for malloc, free
#include <stdio.h>
#include "../include/stack.h"



// Function to create a new stack
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    stack->top = NULL; // Initialize top to NULL indicating an empty stack
    return stack;
}

// Function to create a new node with given data
NodeStack* createNode(int value) {
    NodeStack* newNode = (NodeStack*)malloc(sizeof(NodeStack));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to push an element onto the stack
void push(Stack* stack, int value) {
    NodeStack* newNode = createNode(value);
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop the top element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    NodeStack* temp = stack->top;
    int poppedValue = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return poppedValue;
}

// Function to peek the top element of the stack without removing it
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return stack->top->data;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return (stack->top == NULL);
}