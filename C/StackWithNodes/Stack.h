#ifndef STACKNODE_H
#define STACKNODE_H
#include "Node.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct StackNode{
    node* head;
}stack;

stack* makeStack();
int pop(stack* stack);
void push(int data,stack* stack);
int peek(stack* stack);
bool isStackEmpty(stack* stack);
void freeStack(stack* stack);
#endif