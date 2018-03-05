#include "LinkedListAPI.h"
#include "queue.h"
// Standard Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printList (void *toBePrinted) {
    printf("%s\t\t%d\t%s\t\t%d\n",((Queue*)(toBePrinted))->id, ((Queue*)(toBePrinted))->priority, ((Queue*)(toBePrinted))->symptom, ((Queue*)(toBePrinted))->timeFinished);
}

int compareID (const void *first,const void *second) {
    Queue* patient1 = (Queue*)first;
    Queue* patient2 = (Queue*)second;
    //char* patientID = (char*)second;
    //if (strcmp(*((char*)first), *((char*)second))==0) {
    if (strcmp(patient1->id, patient2->id)==0) {
        //printf("EQUAL\n");
        return 1;
    }

    else {
        //printf("NOT EQUAL\n");
        return 0;
    }

}

void deleteListNode(void *toBeDeleted) {
    
}
