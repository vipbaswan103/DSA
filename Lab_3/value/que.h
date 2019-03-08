#include<stdio.h>
#include<stdlib.h>

typedef int Element;

struct node
{
	Element ele;
	struct node * next;
};
typedef struct node node;

typedef struct Queue
{
	node * head;
	node * tail;
}Queue;

Queue newQ();
int isEmptyQ(Queue q);
Queue delQ(Queue q);
Element front(Queue q);
Queue addQ(Queue q, Element ele);
int lengthQ(Queue q);
void printQ(Queue q);
