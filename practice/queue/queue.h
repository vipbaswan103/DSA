#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node {
	char *name;
	struct node * next;
}node;

typedef struct queue{
	int count;
	struct node * first;
	struct node * last;
}queue;

void enqueue(queue * head, char * name);
node * dequeue(queue * head);

void print(queue * head);
int search(queue * head, char * name);
