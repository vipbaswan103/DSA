#include "stack.h"

void push(node ** top, int p)
{
	node * newNode=(node *)malloc(sizeof(node));
	if(*top==NULL)
	{
		newNode->next=NULL;
		newNode->p=p;
		*top=newNode;
		return;
	}
	
	node * tmp=*top;
	newNode->next=tmp;
	newNode->p=p;
	*top=newNode;
}

node * pop(node ** top)
{
	if(*top==NULL)
	{
		return NULL;
	}
	node * tmp=*top;
	(*top)=tmp->next;
	tmp->next=NULL;
	return tmp;
}

int isEmpty(node * top)
{
	if(top==NULL)
		return 1;
	return 0;
}

