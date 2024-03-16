#ifndef QUEUE_H
#define QUEUE_H

#define SIZE 100



typedef struct NodeQueue {
    int data;
    struct NodeQueue *next;
}NodeQueue;

typedef struct {
    NodeQueue *front;
    NodeQueue *rear;
}Queue;

Queue *createQueue();
void enqueue(Queue* queue, int value);
int dequeue(Queue* queue);
int peekFromQueue(Queue* queue);
int checkQueue(Queue* queue);



#endif // QUEUE_H