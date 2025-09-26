#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

void displayStackMenu() {
    printf("\n=== STACK OPERATIONS ===\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Peek\n");
    printf("4. Check if empty\n");
    printf("5. Print stack\n");
    printf("6. Auto-demo\n");
    printf("7. Clear stack\n");
    printf("0. Exit\n");
    printf("Choice: ");
}

void stackDemo() {
    printf("\n=== STACK DEMONSTRATION ===\n");
    stack* s = makeStack();
    
    printf("Pushing 10, 20, 30...\n");
    push(10, s);
    push(20, s);
    push(30, s);
    
    printf("Peek: %d\n", peek(s));
    printf("Popped: %d\n", pop(s));
    printf("Popped: %d\n", pop(s));
    printf("Peek: %d\n", peek(s));
    
    printf("Pushing 40, 50...\n");
    push(40, s);
    push(50, s);
    
    printf("Stack empty? %s\n", isEmpty(s) ? "Yes" : "No");
    
    printf("Popping all elements:\n");
    while (!isEmpty(s)) {
        printf("Popped: %d\n", pop(s));
    }
    
    printf("Stack empty? %s\n", isEmpty(s) ? "Yes" : "No");
    
    freeStack(s);
    printf("Demo completed!\n");
}

int main() {
    stack* s = makeStack();
    int choice, value;
    
    printf("STACK DRIVER PROGRAM\n");
    printf("====================\n");
    
    do {
        displayStackMenu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value, s);
                printf("Pushed %d\n", value);
                break;
                
            case 2:
                if (!isEmpty(s)) {
                    value = pop(s);
                    printf("Popped: %d\n", value);
                } else {
                    printf("Stack is empty!\n");
                }
                break;
                
            case 3:
                if (!isEmpty(s)) {
                    value = peek(s);
                    printf("Top element: %d\n", value);
                } else {
                    printf("Stack is empty!\n");
                }
                break;
                
            case 4:
                printf("Stack is %s\n", isEmpty(s) ? "empty" : "not empty");
                break;
                
            case 5:
                printf("Stack contents (top to bottom): ");
                // Since stacks don't typically have print functions, 
                // we'll pop and push to show contents
                if (isEmpty(s)) {
                    printf("Empty\n");
                } else {
                    stack* temp = makeStack();
                    while (!isEmpty(s)) {
                        value = pop(s);
                        printf("%d ", value);
                        push(value, temp);
                    }
                    // Restore original stack
                    while (!isEmpty(temp)) {
                        push(pop(temp), s);
                    }
                    freeStack(temp);
                    printf("\n");
                }
                break;
                
            case 6:
                stackDemo();
                break;
                
            case 7:
                freeStack(s);
                s = makeStack();
                printf("Stack cleared!\n");
                break;
                
            case 0:
                printf("Exiting...\n");
                break;
                
            default:
                printf("Invalid choice!\n");
        }
        
    } while (choice != 0);
    
    freeStack(s);
    printf("Stack driver ended.\n");
    return 0;
}