#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int ele;
	struct node * next;
} node;

typedef struct circlist
{
	int count;
	struct node * first;
} circlist;

void insertEnd(circlist * head, int ele);
void deleteEnd(circlist * head);
void print(circlist *head);
int search(circlist * head, int key);
