#include <stdlib.h> // for malloc, free
#include "../include/stack.h"


Stack* createStack(){
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    if(stack == NULL){
        exit(EXIT_FAILURE);
    }
    stack->top = NULL;
    stack->size = 0;
    return stack;
}
void destroyStack(Stack* stack){
    while (!isEmpty(stack)){
        pop(stack);
    }
    free(stack);
}
bool isEmpty(Stack* stack){
    return stack->top == NULL;
}
void push(Stack* stack, StackItem item){
    StackNode *newNode = (StackNode*)malloc(sizeof(StackNode));
    if(newNode == NULL){
        exit(EXIT_FAILURE);
    }
    newNode->data = item;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}
StackItem pop(Stack* stack){
    if(isEmpty(stack)){
        printf("Error: Stack is empty.\n");
        exit(EXIT_FAILURE);
    }
    StackNode *temp = stack->top;
    StackItem item = temp->data;
    stack->top = temp->next;
    free(temp);
    stack->size--;
    return item;
}
StackItem peek(Stack* stack){
    if(isEmpty(stack)){
        printf("Error: Stack is empty.\n");
        exit(EXIT_FAILURE);
    }
    return stack->top->data;
}
int getSize(Stack* stack){
    return stack->size;
}
void displayStack(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack contents (top to bottom):\n");
    StackNode *current = stack->top;
    while (current != NULL) {
        printf("%f\n", current->data); // Change %f to %c for char
        current = current->next;
    }
}