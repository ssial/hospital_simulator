#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

typedef struct queue {
    char *id;
    char symptom[3];
    int priority;
    int timeFinished;
} Queue;

/**
 *This function determines the time it takes to treat each symptom
 *Parameter: takes in a string representing the patient's symptom
 *Return: returns the time it takes to teat that symptom or returns -1 if incorrect symptom is given
*/
int time (char *symptom);

/**
 *This function prints the data in a single node
 *Parameter: takes in a pointer to the data store in a node
 *Return: nothing
*/
void printList (void *toBePrinted);

/**
 *This function compares two strings (patient IDs)
 *Parameter: takes in pointers to the data
 *Return: return 1 if strings are equal or 0 if they are not equal
*/
int compareID (const void *first,const void *second);

/**
 *This function initializes the priority queue
 *Parameter: takes in pointers to three functions
 *Return: return pointer to the new list
*/
List* createQueue ( void (*printFunction)(void *toBePrinted), void (*deleteFunction)(void *toBeDeleted), int (*compareFunction)(const void *first,const void *second));

void deleteListNode(void *toBeDeleted);

/**
 *This function deletes the top member of the queue
 *Parameter: takes in pointer to the data to be deleted
 *Return: nothing
*/
void pop(List *list1);

/**
 *This function gets the data stored at the top of the queue
 *Parameter: takes in pointer to the list
 *Return: pointer to data
*/
void *peek (List *list1);

/**
 *This function checks if the list is empty
 *Parameter: takes in pointer to the list
 *Return: returns 0 is list is not empty and 1 if list is empty
*/
int isEmpty (List *list1);

/**
 *This function adds a node to the back of the queue
 *Parameter: takes in pointer to list and pointer to data
 *Return: nothing
*/
void insert(List *list1, void *data);

/**
 *This function removes a patient from the queue
 *Parameter: takes in pointer to list and pointer to data to be delted
 *Return: nothing
*/
void removePatient(List *list1, void *data);

/**
 *This function deltes the entire queue
 *Parameter: takes in pointer to list
 *Return: nothing
*/
void destroy (List *list1);
#endif // STACK_H_INCLUDED