#ifndef STACK_H
#define STACK_H

// Node structure for stack elements
typedef struct NodeStack {
    int data;          // Data of the node
    struct NodeStack* next; // Pointer to the next node
} NodeStack;


// Structure to represent a stack
typedef struct {
    NodeStack* top; // Pointer to the top of the stack
} Stack;

// Function to create a new stack
Stack* createStack();

// Function to push an element onto the stack
void push(Stack* stack, int value);

// Function to pop the top element from the stack
int pop(Stack* stack);

// Function to peek the top element of the stack without removing it
int peek(Stack* stack);

// Function to check if the stack is empty
int isEmpty(Stack* stack);

#endif /* STACK_H */
