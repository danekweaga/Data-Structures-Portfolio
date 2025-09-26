#include "Stack.h"

stack* makeStack()
{
    stack* newStack = (stack*) malloc (sizeof(stack));
    newStack -> head = makeNode(0);
    return newStack;
}

void push(int data,stack* stack)
{
    node* temp = stack->head;
    stack -> head = NULL;
    stack->head->next = temp;
}

int pop(stack* stack)
{
    node* current = stack->head;
    int out = current->data;
    current = current -> next;
    freeNode(current);
    return out;
}

int peek(stack* stack)
{
    return stack->head->data;
}

bool isStackEmpty(stack* stack)
{
    return stack->head == NULL;
}

void freeStack(stack* stack)
{ node* current = stack -> head;
    
    while(current != NULL)
    {
       
        current = current -> next;
        freeNode(current);
    }
    free(stack);
}