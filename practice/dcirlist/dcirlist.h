#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int ele;
	struct node * next;
	struct node * prev;		
}node;

node * search(node * sentinel, int key);

node * deleteNode(node * sentinel, int key);

void insertNode(node * sentinel, int ele);

void printForward(node * sentinel);

void printBackward(node * sentinel);
