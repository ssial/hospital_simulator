#include "LinkedListAPI.h"
#include "queue.h"
// Standard Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

List* createQueue ( void (*printFunction)(void *toBePrinted), void (*deleteFunction)(void *toBeDeleted), int (*compareFunction)(const void *first,const void *second)) {
    List *l;
    l = initializeList (printFunction, deleteFunction, compareFunction);
    return l;
}

void insert (List *list1, void *data) {
    Node *n = initializeNode(data);
    insertBack(list1,n->data);
}

void *peek (List *list1) {
    return getFromFront(list1);
}

int isEmpty (List *list1) {
    if (list1->head==NULL) {
        printf("Empty list!\n");
        return 1;
    }
    else {
        return 0;
    }
}

void pop(List *list1) {
    deleteNodeFromList(list1,list1->head->data);
}

void removePatient(List *list1, void *data) {
    deleteNodeFromList(list1,data);
}

void destroy (List *list1) {
    deleteList(list1);
}