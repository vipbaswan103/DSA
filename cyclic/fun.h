#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int ele;
	struct node * next;
}node;

typedef struct head
{
	struct node * next;
}head;

void insert(head * head, int ele);
void makeCyclic(head * head, int ele);

int detectCycle(head * head);
node * startNode(head * head);
int lengthOfCycle(head * head);
void makeCircular(head * head);

node* searchRecursive(node * h, int x);
void print(head * head);
