

#ifndef STACK_H
#define STACK_H

#include <stdbool.h>


// define the type of the data
typedef int StackItem;

// define the structure of the stack node
typedef struct StackNode {
    StackItem data;
    struct StackNode *next;
}StackNode;

// define the structure of the stack
typedef struct {
    StackNode *top;
    int size;
}Stack;

// Function prototypes
Stack* createStack();
void destroyStack(Stack* stack);
bool isEmpty(Stack* stack);
void push(Stack* stack, StackItem item);
StackItem pop(Stack* stack);
StackItem peek(Stack* stack);
int getSize(Stack* stack);
void displayStack(Stack *stack);

#endif 