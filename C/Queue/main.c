#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

void displayQueueMenu() {
    printf("\n=== QUEUE OPERATIONS ===\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Peek\n");
    printf("4. Check if empty\n");
    printf("5. Print queue\n");
    printf("6. Auto-demo\n");
    printf("7. Clear queue\n");
    printf("0. Exit\n");
    printf("Choice: ");
}

void queueDemo() {
    printf("\n=== QUEUE DEMONSTRATION ===\n");
    queue* q = makeQueue();
    
    printf("Enqueue 10, 20, 30...\n");
    enqueue(10, q);
    enqueue(20, q);
    enqueue(30, q);
    
    printf("Peek: %d\n", peek(q));
    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));
    printf("Peek: %d\n", peek(q));
    
    printf("Enqueue 40, 50...\n");
    enqueue(40, q);
    enqueue(50, q);
    
    printf("Queue empty? %s\n", isQueueEmpty(q) ? "Yes" : "No");
    
    printf("Dequeue all elements:\n");
    while (!isQueueEmpty(q)) {
        printf("Dequeued: %d\n", dequeue(q));
    }
    
    printf("Queue empty? %s\n", isQueueEmpty(q) ? "Yes" : "No");
    
    freeQueue(q);
    printf("Demo completed!\n");
}

int main() {
    queue* q = makeQueue();
    int choice, value;
    
    printf("QUEUE DRIVER PROGRAM\n");
    printf("====================\n");
    
    do {
        displayQueueMenu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value, q);
                printf("Enqueued %d\n", value);
                break;
                
            case 2:
                if (!isQueueEmpty(q)) {
                    value = dequeue(q);
                    printf("Dequeued: %d\n", value);
                } else {
                    printf("Queue is empty!\n");
                }
                break;
                
            case 3:
                if (!isQueueEmpty(q)) {
                    value = peek(q);
                    printf("Front element: %d\n", value);
                } else {
                    printf("Queue is empty!\n");
                }
                break;
                
            case 4:
                printf("Queue is %s\n", isQueueEmpty(q) ? "empty" : "not empty");
                break;
                
            case 5:
                printf("Queue contents (front to rear): ");
                if (isQueueEmpty(q)) {
                    printf("Empty\n");
                } else {
                    // For simplicity, just show without modifying queue
                    printf("[Cannot display without dequeue - use operations to see contents]\n");
                    printf("Queue size can be observed through operations.\n");
                }
                break;
                
            case 6:
                queueDemo();
                break;
                
            case 7:
                freeQueue(q);
                q = makeQueue();
                printf("Queue cleared!\n");
                break;
                
            case 0:
                printf("Exiting...\n");
                break;
                
            default:
                printf("Invalid choice!\n");
        }
        
    } while (choice != 0);
    
    freeQueue(q);
    printf("Queue driver ended.\n");
    return 0;
}