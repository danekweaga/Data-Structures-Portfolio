#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"
#include <stdbool.h>

typedef struct Queue {
    node* head;
    node* tail;
} queue;

// Function declarations
queue* makeQueue();
void enqueue(int data, queue* que);
int peek(queue* que);
int dequeue(queue* que);
bool isQueueEmpty(queue* que);
void freeQueue(queue* que);

#endif // QUEUE_H