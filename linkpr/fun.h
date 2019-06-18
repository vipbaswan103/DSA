#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct node 
{
	int ele;
	struct node * next;
}node ;

typedef struct head
{
	struct node * next;
}head;
int count(head * h, int key);
int GetNth(head * h, int index);
void insertNth(head * h, int index, int data);
int pop(head * h);
void deleteList(head * h);
int GetNth(head * h, int index);
int count(head *h , int key);
void makeList(head * h);
void printList(head * h);
void insertSort(head * h);
void frontBackSplit(head * h, head * front, head * back);
void removeDuplicates(head * h);
void append(head * h1, head * h2);
void moveNode(head * dst, head * src);
void alternatingSplit(head * src, head * dest1, head *dest2);
