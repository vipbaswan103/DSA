#include "cirl.h"

void insertEnd(circlist * head, int ele)
{
	node * ptr=head->first;	
	node * newptr=(node *)malloc(sizeof(node));
	if(ptr==NULL)
	{
		head->first=newptr;
		newptr->next=head->first;
		newptr->ele=ele;
		head->count++;
		return;
	}
	while((ptr->next)!=(head->first))
	{
		ptr=ptr->next;
	}
	node * tmp=ptr->next;
	ptr->next=newptr;
	newptr->next=tmp;
	newptr->ele=ele;
	head->count++;
}

void deleteEnd(circlist * head)
{
	node * ptr=head->first;

	if(ptr==NULL)
	{
		printf("Error!! List is empty\n");
		return;
	}
	node * prev=NULL;
	while((ptr->next)!=(head->first))
	{
		prev=ptr;
		ptr=ptr->next;
	}
	prev->next=ptr->next;
	ptr->next=NULL;
	head->count--;
}

void print(circlist * head)
{
	node * ptr=head->first;

	while((ptr->next)!=(head->first))
	{
		printf("%d\t",ptr->ele);
		ptr=ptr->next;
	}
	printf("%d\t",ptr->ele);
}
int search(circlist * head, int ele)
{
	node * ptr=head->first;

	if(ptr==NULL)
	{
		printf("Error!! List is empty\n");
		return;
	}
	
	while((ptr->next)!=(head->first))
	{
		if(ptr->ele==ele)
			return 1;
		ptr=ptr->next;
	}
	return -1;
}
