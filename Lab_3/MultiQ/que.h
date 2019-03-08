#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int ele;
	struct Node * next;
}Node;

typedef struct Queue
{
	struct Node * Head;
	struct Node * Tail;
}Queue;

void print(Queue * que);
Queue* newQ();
int isEmptyQ(Queue * que);
Queue* delQ(Queue * que);
Node* front(Queue * que);
Queue* addQ(Queue * que, int ele);
int lengthQ(Queue * que);
