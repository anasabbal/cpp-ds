

#ifndef STACK_H
#define STACK_H

#define MAX_SIZE 100

typedef struct STACK {
    int items[MAX_SIZE];
    int top;
}Stack;

// function to initialize the stack
void initializeStack(Stack *stack);

// function to check if the stack is empty
int isEmpty(Stack *stack);

// function to check if the stack is full
int isFull(Stack *stack);

// function to push an element onto the stack
void push(Stack *stack, int value);

// function to pop an element from the stack
int pop(Stack *stack);

// function to peek at the top element of the stack
int peek(Stack *stack);

#endif 