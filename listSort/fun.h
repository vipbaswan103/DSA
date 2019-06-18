#include<stdio.h>
#include<stdlib.h>

struct node
{
	int key;
	struct node * next;
	struct node * prev;
};
typedef struct node * Node;

struct head
{
	int count;
	Node next;	
};
typedef struct head * Head;

void printList(Node h);
void insertNode(Head list, int key);
Head createList(Head list, FILE * fp);
void deleteNode(Head list, int key);

void splitIntoTwo(Head list, Head front, Head back);
Node sortedMerge(Node l1, Node l2);
void mergeSort(Head list);

Node partition(Head list, Node lo, Node hi);
void quickSort(Head list, Node lo, Node hi);

void insertionSort(Node * list);
Node shortList(Node * list);
