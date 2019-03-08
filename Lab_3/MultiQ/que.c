#include "que.h"

Queue* newQ()
{
	Queue * que =(Queue *)malloc(sizeof(Queue));
	que->Head=NULL;
	que->Tail=NULL;
	return que;
}

int isEmptyQ(Queue * que)
{
	if(que->Head==NULL && que->Tail==NULL)
		return 1;
	return 0;
}

Queue * addQ(Queue * que, int ele)
{
	Node * newNode=(Node *)malloc(sizeof(Node));
	if(que->Head==NULL && que->Tail==NULL)
	{
		newNode->next=NULL;
		newNode->ele=ele;
		que->Head=newNode;
		que->Tail=newNode;
		return que;
	}
	Node * tmp;
	tmp=que->Tail;
	tmp->next=newNode;
	newNode->next=NULL;
	newNode->ele=ele;
	que->Tail=newNode;
	return que;
}

Queue * delQ(Queue * que)
{
	if(que->Head==NULL && que->Tail==NULL)
		return NULL;
	
	if(que->Head==que->Tail)
	{
		que->Head=NULL;
		que->Tail=NULL;
		return que;
	}
	que->Head=(que->Head)->next;
	return que;
}

Node * front(Queue * que)
{
	return que->Head;
}

int lengthQ(Queue *que)
{
	int k=0;
	Node * tmp=que->Head;
	while(tmp!=NULL)
	{
		k++;
		tmp=tmp->next;
	}
	return k;
}

void print(Queue * que)
{
	Node * tmp=que->Head;
	while(tmp!=NULL)
	{
		printf("%d\n",tmp->ele);
		tmp=tmp->next;
	}
}
