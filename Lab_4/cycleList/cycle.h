#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int ele;
	struct node * next;
}node;

node * insert(node * list, int ele);
int detectCycle(node * list);
int lengthCycle(node * list);
node * startNode(node * list);
node * makeCyclic(node * list, int ele);
void print(node * list);
