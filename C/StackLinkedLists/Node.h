#ifndef NODES_H
#define NODES_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int data;
    struct Node* next;
} node;

node* makeNode(int data);
node* makeFirstNode(int data, node* next);
void freeNode(node* node);
void printNode(node* node);
#endif