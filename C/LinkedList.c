#include "LinkedList.h"


ll* makeLL()
{
    ll* LinkedList = (ll*) malloc (sizeof(ll));
    LinkedList ->head = NULL;
    return LinkedList;
}

void freeLL(ll* list)
{
    node* current = list->head;
    while(current != NULL)
    {
        node* temp = current;
        current = current-> next;
        freeNode(temp);
    }
    list-> head = NULL;
    free(list);
}

bool isEmptyLL(ll* list)
{
    return list->head == NULL;
}

void insertFrontLL(int data, ll* list)
{
    node* newNode = makeFirstNode(data,list->head);
    list-> head = newNode;
    
}

void insertEndLL(int data,ll* list)
{
    node* current = list->head;
    node* temp = makeNode(data);
    while(current != NULL)
    {
        current = current -> next;
    }
        current -> next = temp;
}

int removeFrontLL(ll* list)
{

    node* current = list -> head;
    //first move current node to next 
    list->head = list->head->next;

    int data = current-> data;
    freeNode(current);
    return data;
}

int removeEndLL(ll* list)
{
    node* current = list->head;
    while(current != NULL)
    {
        current = current -> next;
    }
    current = current->next;
    int out = current -> data;
    freeNode(current);
    return out;
}

void printLL(ll* list)
{
    node* current = list -> head;
    while(current != NULL)
    {
        printNode(current);
        current = current -> next;
    }
}