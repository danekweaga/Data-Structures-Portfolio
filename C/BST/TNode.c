#include "TNode.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

tnode* makeTNode(const char* data) {
    tnode* Node = (tnode*)malloc(sizeof(tnode));
    Node->left = NULL;
    Node->right = NULL;
    Node->word = (char*)malloc(sizeof(char) * (strlen(data) + 1));
    strcpy(Node->word, data);
    return Node;
}

void printTNode(tnode* node) {
    if (node == NULL) {
        printf("Node: NULL\n");
        return;
    }
    printf("Value: %s | Left: %p | Right: %p\n", 
           node->word, (void*)node->left, (void*)node->right);
}

char* toString(tnode* node) {
    return (node != NULL) ? node->word : "NULL";
}

void freeTNode(tnode* node) {
    if (node == NULL) return;
    free(node->word);
    free(node);
}

// FIXED: Use pointer-to-pointer to handle root updates
void insertTNode(const char* data, tnode** nodeRef) {
    if (*nodeRef == NULL) {
        *nodeRef = makeTNode(data);
        return;
    }
    
    int cmp = strcmp(data, (*nodeRef)->word);
    
    if (cmp < 0) {
        insertTNode(data, &((*nodeRef)->left));
    } else if (cmp > 0) {
        insertTNode(data, &((*nodeRef)->right));
    }
    // if equal, do nothing (no duplicates)
}

bool searchTNode(const char* data, tnode* node) {
    if (node == NULL) return false;
    
    int cmp = strcmp(data, node->word);
    if (cmp == 0) return true;
    if (cmp < 0) return searchTNode(data, node->left);
    return searchTNode(data, node->right);
}

int childCount(tnode* node) {
    if (node == NULL) return -1;
    
    int count = 0;
    if (node->left != NULL) count++;
    if (node->right != NULL) count++;
    return count;
}

// Helper function to find minimum value node
tnode* findMin(tnode* node) {
    if (node == NULL) return NULL;
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

// COMPLETELY REWRITTEN DELETE FUNCTION
tnode* deleteTNode(const char* data, tnode* root) {
    if (root == NULL) return root;
    
    int cmp = strcmp(data, root->word);
    
    // Search for the node to delete
    if (cmp < 0) {
        root->left = deleteTNode(data, root->left);
    } else if (cmp > 0) {
        root->right = deleteTNode(data, root->right);
    } else {
        // Found the node to delete
        
        // Case 1: No child or one child
        if (root->left == NULL) {
            tnode* temp = root->right;
            freeTNode(root);
            return temp;
        } else if (root->right == NULL) {
            tnode* temp = root->left;
            freeTNode(root);
            return temp;
        }
        
        // Case 2: Two children - find inorder successor (min in right subtree)
        tnode* temp = findMin(root->right);
        
        // Copy the successor's content to this node
        free(root->word);
        root->word = (char*)malloc(strlen(temp->word) + 1);
        strcpy(root->word, temp->word);
        
        // Delete the successor
        root->right = deleteTNode(temp->word, root->right);
    }
    return root;
}