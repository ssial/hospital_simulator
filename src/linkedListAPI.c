#include <stdio.h>
#include <stdlib.h>
#include "LinkedListAPI.h"
#include "queue.h"

List *initializeList(void (*printFunction)(void *toBePrinted),void (*deleteFunction)(void *toBeDeleted),int (*compareFunction)(const void *first,const void *second)) {
    List *list1 = malloc(sizeof (List));
    list1->head = NULL;
    list1->tail = NULL;
    list1->printNode = printFunction;
    list1->compare = compareFunction;
    list1->deleteNode = deleteFunction;
    return list1;
}

Node *initializeNode(void *data) {
    if (data==NULL) {
        return;
    }
    else {
       	Node *n = (Node*)malloc(sizeof(Node));
        n->data = data;
        n->previous = NULL;
        n->next = NULL;
        n->priority = ((Queue*)(data))->priority;
        return n;
    }
}

void insertFront(List* list, void* toBeAdded){
    Node *temp = initializeNode(toBeAdded);
    if(list==NULL){//if list doesn't exist
		return;
	}
    else if(list->head == NULL){//if there's no head
		list->head = temp; //set temp equal to the new head
		list->tail = list->head; //also set the tail equal to the head because there's only one node
	}
	else{
		list->head->previous = temp;
		temp->next = list->head;
		list->head = temp;
	}
}

void insertBack(List *list, void *toBeAdded) {
    Node *temp = initializeNode(toBeAdded);
    if(list==NULL){
		return;
	}
    else if(list->tail == NULL){
		list->tail = temp;
		list->head = list->tail;
	}
	else {
        list->tail->next = temp;
        temp->previous = list->tail;
        list->tail = temp;
	}
}

void deleteList(List *list) {
    Node *temp1 = list->head;
    Node *temp2;
    while(temp1!=NULL) {
        temp2 = temp1->next;
        free(temp1);
        temp1 = temp2;
    }
    list->head = NULL;
    list->tail = NULL;
}

void *getFromFront(List *list) {
    void *headData;
    Node *temp = list->head;
    if (list->head==NULL) {
        printf("Head is empty!\n");
        return;
    }
    else {
        headData = temp->data;
        return headData;
    }
}

void *getFromBack(List *list){
    void *tailData;
    Node *temp = list->tail;
    if (list->head==NULL) {
        return;
    }
    else {
        tailData = temp->data;
        return tailData;
    }
}

void printForward(List *list) {
    Node *temp1;
    if (list->head!=NULL) {
        temp1 = list->head;
        while(temp1!=NULL) {
            printList(temp1->data);
            temp1 = temp1->next;
        }

    }
    else {
        printf("Empty list\n");
        return;
    }



}

void printBackwards(List *list) {
    Node *temp1 = list->tail;
    if (list->head==NULL) {
        printf("Empty list\n");
        return;
    }
    else {
        while(temp1!=NULL) {
            printList(temp1->data);
            temp1 = temp1->previous;
        }
    }

}


int deleteNodeFromList(List *list, void *toBeDeleted) {
    Node *temp = list->head;
	Node *temp2;
	Node *temp4 = list->tail;
    if (list==NULL) {
		return EXIT_FAILURE;
	}
	else if (compareID(temp->data,toBeDeleted)==1) {
        temp2 = temp->next;
        list->head = temp2;
        free(temp);
        return EXIT_SUCCESS;
	}

	//else if (compareID((Queue*)(temp4->data)->id,toBeDeleted)==1) {
    else if (compareID(temp4->data,toBeDeleted)==1) {
        temp2 = temp4->previous;
        temp2->next = NULL;
        list->tail = temp2;
        free(temp4);
        return EXIT_SUCCESS;
	}
	else {
        Node *temp3 = list->head;
        Node *store_next;
        Node *store_prev;
        while (compareID(temp3->data,toBeDeleted)==0) {
            temp3 = temp3->next;
        }
        store_next = temp3->next;
        store_prev = temp3->previous;
        store_next->previous = store_prev;
        store_prev->next = store_next;
        free(temp3);
        return EXIT_SUCCESS;
	}
}

/*int insertSorted(List *list, void *toBeAdded) {
    Node *temp = initializeNode(toBeAdded);
    Node *temp2 = list->head;
    if(list==NULL){//if list doesn't exist
        return EXIT_FAILURE;
    }
    else if(list->head == NULL){//if there's no head
        list->head = temp; //set temp equal to the new head
        list->tail = list->head; //also set the tail equal to the head because there's only one node
    }
    else if(compareIntegers(list->head->data,toBeAdded)==1) {//if head > item then make it the new head
        insertFront(list,toBeAdded);
    }
    else if(compareIntegers(list->tail->data,toBeAdded)==-1) {//if tail < item then make it the new tail
        insertBack(list,toBeAdded);
    }
    else {
        Node *store_prev;
        while (compareIntegers(temp2->data,toBeAdded)==-1) {//while temp2 < item, keep going until bigger element is found
            temp2 = temp2->next;
        }
        //exits loop when temp2 > item
        store_prev = temp2->previous;
        temp2->previous = temp;
        temp->next = temp2;
        store_prev->next = temp;
        temp->previous = store_prev;

    }

}*/

