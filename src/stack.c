#include <stdio.h>
#include "../include/stack.h"


void initializedStack(Stack *stack){
    stack->top = -1;
}

int isEmpty(Stack *stack){
    return (stack->top == -1);
}

// function to check if the stack is full
int isFull(Stack *stack){
    return (stack->top == MAX_SIZE - 1);
}

// function to push an element onto the stack
void push(Stack *stack, int value){
    if(isFull(stack)){
        printf("Error: Stack overflow\n");
        return;
    }
    stack->items[++stack->top] = value;
}

// function to pop an element from the stack
int pop(Stack *stack){
    return 0;
}

// function to peek at the top element of the stack
int peek(Stack *stack){
    return 0;
}