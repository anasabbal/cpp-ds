#include <stdlib.h> // for malloc, free
#include <stdio.h>
#include "../include/queue.h"


Queue *createQueue(){
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    free(queue);
    return queue;
}
void enqueue(Queue* queue, int value){

}
int dequeue(Queue* queue){
    return 0;
}
int peekFromQueue(Queue* queue) {
    if (checkQueue(queue)) {
        printf("Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    return queue->front->data;
}
int checkQueue(Queue* queue) {
    return (queue->front == NULL);
}