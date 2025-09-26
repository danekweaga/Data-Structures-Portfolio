#ifndef BST_H
#define BST_H

#include "TNode.h"
#include <stdbool.h>

typedef struct BST {
    tnode* root;
} bst;

bst* makeBST();
void insert(char* data, bst* tree);
void printLNR(bst* tree);
void printNLR(bst* tree);
void printLRN(bst* tree);
bool searchBST(char* data, bst* tree);
bool removeBST(char* data, bst* tree);
void freeBST(bst* tree);  // Added this function

#endif