#include "Stack.h"


stack* makeStack()
{
    stack* newStack = (stack*) malloc (sizeof(stack));
    newStack->headLL = makeLL();
    return newStack;
}

int pop (stack* stack)
{
    return removeFrontLL(stack->headLL);
}

void push ( int data, stack* stack)
{
    insertFrontLL(data,stack->headLL);
}

bool isEmpty(stack* stack)
{
    return isEmptyLL(stack->headLL);
}

int peek(stack* stack)
{
    return stack -> headLL -> head ->data;
}

void freeStack(stack* stack)
{
    freeLL(stack->headLL);
    free(stack);
}
