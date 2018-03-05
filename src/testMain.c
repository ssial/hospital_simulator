#include "LinkedListAPI.h"
#include "queue.h"
// Standard Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main( int argc, const char** argv[] ) {

	List *list;
	List *list2;

    printf("Test 1: Test createQueue function to see if list is intialized\n");
    list = createQueue (&printList, &deleteListNode, &compareID);
    printf("Expected Output: Head is empty!\n");
    printf("Test 1.1: Check if head pointer is NULL by testing the peek function\n");
    peek(list);
    printf("Test 1.2: Check if tail pointer is NULL\n");
    printf("Expected Output: NULL\n");
	if(list->tail ==  NULL) {
		printf("NULL\n");
	}
	else{
		printf("Test Failed.\n");
	}

	printf("\nTest 2: Test insert fucntion\n");
    printf("Expected Output: ssial	1	CV	0\n");
    char id[6] = "ssial";
	Queue* q1 = malloc(sizeof(Queue));
    q1->id = malloc(sizeof(char[strlen(id+1)]));
    strcpy(q1->id,id);
    strcpy(q1->symptom,"CV");
    q1->priority = 1;
    insert(list,q1);
    printList(list->head->data);
    printf("Test 2.1: Test if next pointer is pointing to nothing\n");
    printf("Expected Output: NULL\n");
    if (list->head->next==NULL){
        printf("NULL\n");
    }
    else{
		printf("Test Failed.\n");
	}
	printf("Test 2.2: Test if previous pointer is pointing to nothing\n");
    printf("Expected Output: NULL\n");
    if (list->head->previous==NULL){
        printf("NULL\n");
    }
    else{
		printf("Test Failed.\n");
	}

	char id2[7] = "smith1";
	Queue* q2 = malloc(sizeof(Queue));
    q2->id = malloc(sizeof(char[strlen(id2+1)]));
    strcpy(q2->id,id2);
    strcpy(q2->symptom,"HN");
    q2->priority = 2;
    insert(list,q2);
    char id3[7] = "smith2";
	Queue* q3 = malloc(sizeof(Queue));
    q3->id = malloc(sizeof(char[strlen(id3+1)]));
    strcpy(q3->id,id3);
    strcpy(q3->symptom,"SA");
    q3->priority = 3;

    printf("\nTest 3: Test print list forwards function\n");
    printf("Expected output:ssial	1	CV	0 \n");
    printf("Expected output:smith1	2	HN	0 \n");
    printForward(list);
    printf("Test 3.1: Test print list forwards function with empty list\n");
    list2 = createQueue (&printList, &deleteListNode, &compareID);
    printf("Expected output: Empty list\n");
    printForward(list2);

    printf("\nTest 4: Test peak function with existing list\n");
    printf("Expected output:ssial	1	CV	0 \n");
    printList(peek(list));
    printf("Test 4.1: Test peak function with empty list\n");
    printf("Expected output: Head is empty! \n");
    peek(list2);

    printf("\nTest 5: Test pop function with existing list\n");   
    printf("Expected output:smith1	2	HN	0 \n");
    pop(list);
    printForward(list);
    printf("Test 5.1: Test pop function with empty list\n");   
    printf("Expected output:segmentation fault\n");
    //pop(list2);
    //printForward(list2);

    printf("\nTest 6: Test isEmpty function with existing list\n"); 
    printf("Expected output: list not empty!\n");
    if(isEmpty(list)==0) {
    	printf("list not empty!\n");
    } 
    printf("Test 6.1: Test isEmpty functino with empty list\n"); 
    printf("Expected output: Empty list\n"); 
    isEmpty(list2);

    printf("\nTest 6: Test removePatient function with head of existing list\n"); 
    insert(list,q2);
    insert(list,q3);
    removePatient(list,list->head->data);
    printf("Expected output:smith1	2	HN	0 \n");
    printf("Expected output:smith2	3	SA	0 \n");
    printForward(list);
    printf("Test 6.1: Test removePatient function with tail of existing list\n"); 
    removePatient(list,list->tail->data);
    printf("Expected output:smith1	2	HN	0 \n");
    printForward(list);

    printf("\nTest 7: Test destroy function with existing list\n");
    printf("Expected output: Empty list \n");
    destroy(list);
    printf("Test 7.1: Test destroy function with empty list\n");
    printf("Expected output: Empty list \n");
    destroy(list2);

}