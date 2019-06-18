#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
	char name[11];
	int key;
	struct node * next;
}node;

typedef struct queue
{
	node * first;
	node * last;
}queue;

void createQueue(queue * q, char * name, int key);
void print(queue * q);
void deleteNode(queue *q);
void quickSort(queue * q, node * lo, node * hi);
void mergeSort(queue * q);
void split(queue *q , queue * q1, queue *q2);
