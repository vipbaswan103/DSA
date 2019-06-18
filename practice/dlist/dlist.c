#include "dlist.h"

void insertEnd(dlist * head, int ele)
{
	node * ptr=head->first;
	
	node * nptr=malloc(sizeof(node));

	if(ptr==NULL)
	{
		head->first=nptr;
		nptr->next=NULL;
		nptr->prev=NULL;
		nptr->ele=ele;
		head->count++;
		return;
	}

	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}

	ptr->next=nptr;
	nptr->next=NULL;
	nptr->prev=ptr;
	nptr->ele=ele;
	head->count++;
}

void deleteEnd(dlist * head)
{
	node * ptr=head->first;
	if(ptr==NULL)
	{
		printf("Linked List is empty!!");
		return;
	}
	
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}

	node * tmp1=ptr->prev;
	tmp1->next=NULL;
	ptr->prev=NULL;
	head->count--;
}

void printStr(dlist * head)
{
	printf("List is forward traversal:\n");

	node * ptr=head->first;

	while(ptr!=NULL)
	{
		printf("%d\n",ptr->ele);
		ptr=ptr->next;
	}
}

 
void printRev(dlist * head)
{
	printf("List is backward traversal:\n");

	node * ptr=head->first;

	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}

	while(ptr!=NULL)
	{
		printf("%d\n",ptr->ele);
		ptr=ptr->prev;
	}
}

int search(dlist * head, int ele)
{
	node * ptr=head->first;
	if(ptr==NULL)
	{
		printf("List is empty\n");
		return 0;
	}
	int pos=1;
	while(ptr!=NULL)
	{
		if(ptr->ele==ele)
		{
			return pos;
		}
		pos++;
		ptr=ptr->next;
	}
	return -1;
}
