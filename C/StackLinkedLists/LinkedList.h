#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include <stdbool.h>

typedef struct LinkedList{
    node* head;
}ll;

ll* makeLL();

void freeLL(ll* list);

bool isEmptyLL(ll* list);
void insertFrontLL(int data, ll* list);
void insertEndLL(int data, ll* list);
int removeFrontLL(ll* list);
int removeEndLL(ll* list);
void printLL(ll* list);
#endif