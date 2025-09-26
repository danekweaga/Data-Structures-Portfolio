#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void displayLinkedListMenu() {
    printf("\n=== LINKED LIST OPERATIONS ===\n");
    printf("1. Insert at front\n");
    printf("2. Insert at end\n");
    printf("3. Remove from front\n");
    printf("4. Remove from end\n");
    printf("5. Print list\n");
    printf("6. Check if empty\n");
    printf("7. Auto-demo\n");
    printf("8. Clear list\n");
    printf("0. Exit\n");
    printf("Choice: ");
}

void linkedListDemo() {
    printf("\n=== LINKED LIST DEMONSTRATION ===\n");
    ll* list = makeLL();
    
    // Demo operations
    printf("Inserting 10, 20, 30 at front...\n");
    insertFrontLL(10, list);
    insertFrontLL(20, list);
    insertFrontLL(30, list);
    printLL(list);
    
    printf("Inserting 40 at end...\n");
    insertEndLL(40, list);
    printLL(list);
    
    printf("Removing from front: %d\n", removeFrontLL(list));
    printLL(list);
    
    printf("Removing from end: %d\n", removeEndLL(list));
    printLL(list);
    
    printf("Is list empty? %s\n", isEmptyLL(list) ? "Yes" : "No");
    
    freeLL(list);
    printf("Demo completed!\n");
}

int main() {
    ll* list = makeLL();
    int choice, value;
    
    printf("LINKED LIST DRIVER PROGRAM\n");
    printf("==========================\n");
    
    do {
        displayLinkedListMenu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertFrontLL(value, list);
                printf("Inserted %d at front\n", value);
                break;
                
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertEndLL(value, list);
                printf("Inserted %d at end\n", value);
                break;
                
            case 3:
                if (!isEmptyLL(list)) {
                    value = removeFrontLL(list);
                    printf("Removed from front: %d\n", value);
                } else {
                    printf("List is empty!\n");
                }
                break;
                
            case 4:
                if (!isEmptyLL(list)) {
                    value = removeEndLL(list);
                    printf("Removed from end: %d\n", value);
                } else {
                    printf("List is empty!\n");
                }
                break;
                
            case 5:
                printf("Current list:\n");
                printLL(list);
                break;
                
            case 6:
                printf("List is %s\n", isEmptyLL(list) ? "empty" : "not empty");
                break;
                
            case 7:
                linkedListDemo();
                break;
                
            case 8:
                freeLL(list);
                list = makeLL(); // Create new empty list
                printf("List cleared!\n");
                break;
                
            case 0:
                printf("Exiting...\n");
                break;
                
            default:
                printf("Invalid choice!\n");
        }
        
    } while (choice != 0);
    
    freeLL(list);
    printf("Linked List driver ended.\n");
    return 0;
}