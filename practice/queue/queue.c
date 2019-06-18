#include "queue.h"

void enqueue(queue * head, char * name)
{
	node * ptr1=head->first;
	node * ptr2=head->last;

	node * newptr=(node *)malloc(sizeof(node));
	node * tail=(node *) malloc(sizeof(node));
	if(ptr1==ptr2)
	{
		head->first=newptr;
		newptr->next=tail;
		newptr->name=malloc(sizeof(strlen(name)));
		strcpy(newptr->name,name);
		head->last=tail;
		head->count++;
		return;
	}

	(head->last)->next=tail;
	(head->last)->name=malloc(sizeof(strlen(name)));
	strcpy((head->last)->name, name);
	head->last=tail;
	head->count++;
}

node * dequeue(queue * head)
{

	if(head->first == head->last)
	{
		printf("Queue is empty!!");
		return NULL;
	}
	node * ptr=head->first;
	head->first=(ptr->next);
	head->count--;
	ptr->next==NULL;
	return ptr;
}

int search(queue* head, char * name)
{
	node * ptr=head->first;

	int k=1;
	while(ptr!=(head->last))
	{
		if(strcmp(ptr->name,name)==0)
			return k;
		k++;
		ptr=ptr->next;
	}
	return -1;
}

void print(queue * head)
{
	node * ptr=head->first;
	printf("Size : %d\n",head->count);
	while(ptr!=head->last)
	{
		printf("%s\n",ptr->name);
		ptr=ptr->next;
	}
}
