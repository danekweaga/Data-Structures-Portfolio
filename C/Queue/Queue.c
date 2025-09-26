#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

queue* makeQueue() {
    queue* newQ = (queue*) malloc(sizeof(queue));
    newQ->head = NULL;
    newQ->tail = NULL;
    return newQ;
}

void enqueue(int data, queue* que) {
    node* newNode = makeNode(data);
    
    // Handle empty queue case
    if (isQueueEmpty(que)) {
        que->head = newNode;
        que->tail = newNode;
    } else {
        que->tail->next = newNode;
        que->tail = newNode;
    }
}

int peek(queue* que) {
    if (isQueueEmpty(que)) {
        printf("Error: Queue is empty\n");
        exit(1);
    }
    return que->head->data;
}

int dequeue(queue* que) {
    if (isQueueEmpty(que)) {
        printf("Error: Queue is empty\n");
        exit(1);
    }
    
    node* temp = que->head;
    int data = temp->data;
    que->head = que->head->next;
    
    // If queue becomes empty, update tail
    if (que->head == NULL) {
        que->tail = NULL;
    }
    
    freeNode(temp);
    return data;
}

bool isQueueEmpty(queue* que) {
    return que->head == NULL;
}

void freeQueue(queue* que) {
    while (!isQueueEmpty(que)) {
        dequeue(que);
    }
    free(que);
}