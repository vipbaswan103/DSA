#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int ele;
	struct node * next;
}node;

void insertNode(node ** head, int ele);
int length(node * head);
int lengthRecursive(node * head);
int getNth(node * head, int n);
void deleteList(node ** head);
void push(node ** head, int ele);
int pop(node ** head);
int insertNth(node ** head, int n, int ele);
void sortedInsert(node ** head, node * newNode);
void insertionSort(node ** head);
void recursiveInsertionSort(node ** head);
void printList(node * head);
void append(node ** a, node ** b);
void frontBackSplit(node * src, node ** front, node ** back);
void moveNode(node ** dest, node ** src);
void moveNodeLast(node ** dest, node ** src);
void alternatingSplit(node * src, node ** a, node ** b);
node * shuffleMerge(node * a, node * b);
node * sortedMerge(node * a, node * b);
void mergeSort(node ** head);
node * sortedIntersect(node * a, node * b);
void reverse(node ** head);
void reverseOther(node ** head);
void recursiveReverse(node ** head);
node * partitionList(node ** head, node ** start, node ** end);
void quickSort(node ** head, node ** low, node ** high);
