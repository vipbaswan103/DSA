#include "que.h"

Queue newQ()
{
	Queue q;
	q.head=NULL;
	q.tail=NULL;
	return q;
}

Queue addQ(Queue q, Element e)
{
	node * newNode=(node *)malloc(sizeof(node));

	if(q.head==NULL && q.tail==NULL)
	{
		q.head=newNode;
		q.tail=newNode;
		newNode->next=NULL;
		newNode->ele=e;
		return q;
	}
	q.tail->next=newNode;
	newNode->ele=e;
	newNode->next=NULL;
	q.tail=newNode;
	return q;
}

int lengthQ(Queue q)
{
	node * tmp=q.head;

	int count=0;
	while(tmp!=NULL)
	{
		count++;
		tmp=tmp->next;
	}
	return count;
}

Element front(Queue q)
{
	if(q.head==NULL)
		return -1;
	return q.head->ele;
}

Queue delQ(Queue q)
{
	if(q.head==NULL)
	{
		printf("Error: Empty queue\n");
		return q;
	}

	if(q.head==q.tail)
	{
		node * tmp=q.head;
		tmp->next=NULL;
		q.head=NULL;
		q.tail=NULL;
		return q;
	}
	node * tmp=q.head;
	q.head=tmp->next;
	tmp->next=NULL;
	return q;
}

int isEmptyQ(Queue q)
{
	if(q.head==NULL)
		return 1;
	return 0;
}

void printQ(Queue q)
{
	node * tmp=q.head;
	while(tmp!=NULL)
	{
		printf("%d, ",tmp->ele);
		tmp=tmp->next;
	}
}
