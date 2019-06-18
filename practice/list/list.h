#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int val;
	struct node * next;
}node;
node * insert(node * head,int val);
node * merge(node * h1, node * h2, node * out);
void mergeSort(node * head, node * p, node * r);
void print(node * head);
void insertionSort(node ** head);
