#include "LinkedListAPI.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int time (char *symptom) {
	int result = 0;
	if (strcmp(symptom,"CV")==0) {
		result = 5;
	}
	else if (strcmp(symptom,"HN")==0) {
		result = 3;
	}
	else if (strcmp(symptom,"EV")==0) {
		result = 10;
	}
	else if (strcmp(symptom,"GI")==0) {
		result = 2;
	}
	else if (strcmp(symptom,"MH")==0) {
		result = 5;
	}
	else if (strcmp(symptom,"NC")==0) {
		result = 5;
	}
	else if (strcmp(symptom,"EC")==0) {
		result = 1;
	}
	else if (strcmp(symptom,"RC")==0) {
		result = 1;
	}
	else if (strcmp(symptom,"SK")==0) {
		result = 2;
	}
	else if (strcmp(symptom,"SA")==0) {
		result = 7;
	}
	else if (strcmp(symptom,"TR")==0) {
		result = 4;
	}
	else {
		printf("Incorrect symptom\n");
		return -1;
	}
	return result;
}


int main( int argc, const char** argv[] ) {
	FILE *file;
	//int userInput = 0;
    //Queue *q1 = malloc(sizeof(Queue));
    List *list;
    //int *p1;
    //int array[100];
    char buffer[100];
    char buffer2[100];
    char line[100];
    char symptom[3];
    char symptom2[3];
    int priority;
    int priority2;
    Node *n;
    int i = 0;

    if(argv[1]==NULL) {
        printf("Error: file not found!\n");
    }
    else if (argc<2) {
        printf("Incorrect number of parameters\n");
    }

    file = fopen(argv[1], "r");
    if(file == NULL)
    {
        printf("ERROR opening the file\n");
        exit(1);
    }

    list = createQueue (&printList, &deleteListNode, &compareID);

    while( fgets(line,100,file) != NULL )
    {
        sscanf(line,"%s %d %s", buffer, &priority, symptom);
        Queue* q1 = malloc(sizeof(Queue));
        q1->id = malloc(sizeof(char[strlen(buffer+1)]));
        strcpy(q1->id,buffer);
        strcpy(q1->symptom,symptom);
        q1->priority = priority;
        insert(list,q1);
     }

    Node *temp; 
    int clock = 1;
    int processTime = 0;
    int timeFinished = 0;

    int input = 0;
    
    
    int result = 0;
    while (input!=3) {
        printf("\nPlease choose an option from the menu (1-3)\n");
        printf("1. Add a new patient\n");
        printf("2. Process the simulation\n");
        printf("3. Exit\n\n");
    	input = 0;
    	printf("Choose option: \n");
    	scanf("%d",&input);
    	if (input==3) {
            destroy(list);  
    		break;
    	}
    	else if (input==1) {
    		printf("Please enter patient ID (no spaces): \n");
    		scanf("%s", buffer2);
    		Queue* q2 = malloc(sizeof(Queue));
        	q2->id = malloc(sizeof(char[strlen(buffer2+1)]));
        	strcpy(q2->id,buffer2);
        	printf("Please enter symptom (no more than 2 characters):\n");
        	scanf("%s",symptom2);
        	while(strlen(symptom2)>2 || time(symptom2)==-1) {
        		printf("Error: symptom must be 2 characters\n");
        		scanf("%s",symptom2);
        	}
        	strcpy(q2->symptom,symptom2);
        	printf("Please enter priority (1-5): \n");
        	scanf("%d",&priority2);
        	while (priority2<1 || priority2>5) {
        		printf("Error: priority must be 1-5\n");
        		scanf("%d",&priority2);
        	}
        	q2->priority = priority2;
        	n = initializeNode(q2);
        	insertBack(list,n->data);
    			//break;

    	}

    	else if(input==2) {
    		clock = 1;
    		for (int i=1;i<=5;i++) {
    			temp = list->head;
    			while(temp!=NULL) {
    				if (temp->priority==i) {
    					processTime = time(((Queue*)(temp->data))->symptom);
    					timeFinished = clock + processTime;
    					((Queue*)(temp->data))->timeFinished = timeFinished;
    					clock = timeFinished + 1;
    					//printList(temp->data);
    					//removePatient(list,temp->data);
    				}
    				temp = temp->next;
    			}
    		}

    		printf("Patient ID  Priority  Symptom Code  Time Finished(seconds)\n");
    		if(isEmpty(list)==0) {
    			printForward(list);
    		}
    			
    	}
    	else {
    		printf("Must enter 1, 2, or 3\n");
    	}

    }

}