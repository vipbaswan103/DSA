#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int ele;
	struct node * next;
}node;

extern int totSpace;

node * insertList(node * list,int ele);
node * createList(int n);
int testCycle(node * list);
node * createCycle(node * list, int ele);
node * createCircular(node * list);
void print(node * list);
void * myAlloc(int size);
void myFree(void * ptr);
void printCircular(node * list);
int findLengthLoop(node * list);
