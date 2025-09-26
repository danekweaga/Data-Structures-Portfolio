#include "BST.h"
#include <stdio.h>
#include <string.h>

int main() {
    bst* tree = makeBST();
    int choice;
    char word[100];
    
    printf("Binary Search Tree Demo\n");
    printf("=======================\n");
    
    // Insert some initial data
    printf("Inserting initial words...\n");
    insert("dog", tree);
    insert("cat", tree);
    insert("elephant", tree);
    insert("bird", tree);
    insert("fish", tree);
    
    do {
        printf("\nOptions:\n");
        printf("1. Insert word\n");
        printf("2. Search word\n");
        printf("3. Delete word\n");
        printf("4. Print tree (in-order)\n");
        printf("5. Print tree (pre-order)\n");
        printf("6. Print tree (post-order)\n");
        printf("7. Run quick test\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter word to insert: ");
                scanf("%s", word);
                insert(word, tree);
                printf("Inserted '%s'\n", word);
                break;
                
            case 2:
                printf("Enter word to search: ");
                scanf("%s", word);
                if (searchBST(word, tree)) {
                    printf("'%s' FOUND in tree\n", word);
                } else {
                    printf("'%s' NOT FOUND in tree\n", word);
                }
                break;
                
            case 3:
                printf("Enter word to delete: ");
                scanf("%s", word);
                if (removeBST(word, tree)) {
                    printf("'%s' deleted from tree\n", word);
                } else {
                    printf("'%s' not found - cannot delete\n", word);
                }
                break;
                
            case 4:
                printLNR(tree);
                break;
                
            case 5:
                printNLR(tree);
                break;
                
            case 6:
                printLRN(tree);
                break;
                
            case 7:
                printf("\n--- Quick Test ---\n");
                printf("Current tree (in-order): ");
                printLNR(tree);
                
                printf("Searching for 'cat': %s\n", 
                       searchBST("cat", tree) ? "FOUND" : "NOT FOUND");
                printf("Searching for 'zebra': %s\n", 
                       searchBST("zebra", tree) ? "FOUND" : "NOT FOUND");
                
                printf("Deleting 'cat'...\n");
                removeBST("cat", tree);
                printf("Tree after deletion: ");
                printLNR(tree);
                printf("--- End Test ---\n");
                break;
                
            case 0:
                printf("Exiting...\n");
                break;
                
            default:
                printf("Invalid choice\n");
        }
        
    } while (choice != 0);
    
    freeBST(tree);
    printf("Done!\n");
    return 0;
}