#ifndef STACK_H
#define STACK_H
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack
{
 ll* headLL;
}stack; 

stack* makeStack();
int pop (stack* stack);
void push ( int data, stack* stack);
bool isEmpty(stack* stack);
int peek(stack* stack);
void freeStack(stack* stack);

#endif