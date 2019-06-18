#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
	int ele;	
	struct node* next;
	struct node* prev;
}node;

typedef struct dlist
{
	int count;
	struct node* first;
}dlist;


void insertEnd(dlist * head, int ele);
void deleteEnd(dlist * head);

void printStr(dlist * head);
void printRev(dlist * head);

int search(dlist * head, int ele);
