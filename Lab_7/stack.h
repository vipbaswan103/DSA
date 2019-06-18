#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{
	int p;
	struct node * next;
}node;

void push(node ** top, int p);
node * pop(node ** top);
int isEmpty(node * top);
int isFull(node * top);
