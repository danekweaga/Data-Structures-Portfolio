#include "BST.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

bst* makeBST() 
{
    bst* tree = (bst*)malloc(sizeof(bst));
    tree->root = NULL;
    return tree;
}

void insert(char* data, bst* tree) 
{
    insertTNode(data, &(tree->root));  
}


void printLNRHelper(tnode* node)
 {
    if (node == NULL) return;
    printLNRHelper(node->left);
    printf("%s ", node->word);
    printLNRHelper(node->right);
}

void printLNR(bst* tree) 
{
    if (tree->root == NULL) 
    {
        printf("Empty tree\n");
        return;
    }
    printf("LNR (In-order): ");
    printLNRHelper(tree->root);
    printf("\n");
}

void printNLRHelper(tnode* node) 
{
    if (node == NULL) return;
    printf("%s ", node->word);
    printNLRHelper(node->left);
    printNLRHelper(node->right);
}

void printNLR(bst* tree) 
{
    if (tree->root == NULL) 
    {
        printf("Empty tree\n");
        return;
    }
    printf("NLR (Pre-order): ");
    printNLRHelper(tree->root);
    printf("\n");
}

void printLRNHelper(tnode* node) 
{
    if (node == NULL) return;
    printLRNHelper(node->left);
    printLRNHelper(node->right);
    printf("%s ", node->word);
}

void printLRN(bst* tree) 
{
    if (tree->root == NULL) 
    {
        printf("Empty tree\n");
        return;
    }

    printf("LRN (Post-order): ");
    printLRNHelper(tree->root);
    printf("\n");
}

bool searchBST(char* data, bst* tree) 
{
    return searchTNode(data, tree->root);
}

bool removeBST(char* data, bst* tree) 
{
    if (tree->root == NULL) {
        printf("Empty tree\n");
        return false;
    }
    
    
    if (!searchBST(data, tree)) {
        printf("Word '%s' not found in tree\n", data);
        return false;
    }
    
    tree->root = deleteTNode(data, tree->root);
    return true;
}


void freeBSTHelper(tnode* node) 
{
    if (node == NULL) return;
    freeBSTHelper(node->left);
    freeBSTHelper(node->right);
    freeTNode(node);
}

void freeBST(bst* tree) 
{
    freeBSTHelper(tree->root);
    free(tree);
}