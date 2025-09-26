#include <stdio.h>
#include <stdlib.h>
#include "Node.h"
node* makeNode(int data)
{
    node* newNode = (node*) malloc (sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

node* makeFirstNode(int data, node* next)
{
    node* newNode = (node*) malloc (sizeof(node));
    newNode->data = data;
    newNode->next = next;
    return newNode; 
}
void freeNode(node* node)
{
    node->data = 0;
    node->next = NULL;
    free(node);
}

void printNode(node* node)
{
    printf("Node:%d Data:%d, points to %d\n",node,node->data,node->next);
}