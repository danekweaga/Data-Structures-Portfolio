#ifndef TNODE_H
#define TNODE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct TNode {
    struct TNode* left;
    struct TNode* right;
    char* word;
} tnode;

tnode* makeTNode(const char* data);
void printTNode(tnode* node);
char* toString(tnode* node);
void freeTNode(tnode* node);
void insertTNode(const char* data, tnode** nodeRef);  // Changed to pointer-to-pointer
bool searchTNode(const char* data, tnode* node);
tnode* deleteTNode(const char* data, tnode* root);    // Fixed return type
int childCount(tnode* node);
tnode* findMin(tnode* node);                          // Added helper function

#endif