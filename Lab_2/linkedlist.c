#include <stdio.h>
#include<stdlib.h>
#include "linkedlist.h"

void insertFirst(struct linkedlist* head, int ele)
{
	struct node *tmp;
	tmp=head->first;
	struct node *newptr=(struct node*) malloc(sizeof(struct node));
	head->first=newptr;
	newptr->ele=ele;
	newptr->next=tmp;
	head->count++;	
} 

void insertLast(struct linkedlist * head, int ele)
{
	struct node * ptr=head->first;
	
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}

	struct node * newptr=(struct node*)malloc(sizeof(struct node));
	ptr->next=newptr;
	newptr->ele=ele;
	newptr->next=NULL;
	head->count++;
}

void insertMid(struct linkedlist * head, int ele, int pos)
{
	struct node * ptr=head->first;
	struct node * nptr=(struct node*) malloc(sizeof(struct node));
	int k=1;

	struct node *tmp;
	if(pos==0)
	{
		insertFirst(head,ele);
		return;
	}
		while(ptr->next!=NULL)
		{
			if(k==pos)
			{
				tmp=ptr->next;
				ptr->next=nptr;
				nptr->ele=ele;
				nptr->next=tmp;
				head->count++;
				return;				
			}
			k++;
			ptr=ptr->next;
		}
		if(k==pos)
		{
			insertLast(head,ele);
		}
		else
			printf("Invalid Entry for pos\n");
}

struct node* deleteFirst(struct linkedlist*head)
{
	if(head->first==NULL)
	{	
		printf("List is empty! Exiting...");
		return NULL;
	}
	struct node * tmp;
	tmp=head->first;
	head->first=(head->first)->next;
	tmp->next=NULL;
	head->count--;
	return tmp;
}
void printList(struct linkedlist * head)
{
	struct node * link=head->first;
	printf("Number of elements: %d\n",head->count);
	while(link!=NULL)
	{
		printf("%d\n",link->ele);
		link=link->next;
	}
}

int search(struct linkedlist * head, int elem)
{
	struct node * ptr=head->first;
	while(ptr!=NULL)
	{
		if((ptr->ele)==elem)
			return 1;
		ptr=ptr->next;
	}
	return 0;
}

struct node * deleteEle(struct linkedlist* head, int ele)
{
	struct node * ptr=head->first;
	if(ptr==NULL)
	{
		printf("Empty linked list");
		return NULL;
	}
	if(ptr->ele==ele)
	{
		struct node * tmp=deleteFirst(head);
		return tmp;
	}
	ptr=(head->first)->next;
	struct node * prev=head->first;
	while(ptr!=NULL)
	{
		if(ptr->ele==ele)
		{
			prev->next=ptr->next;
			ptr->next=NULL;
			head->count--;
			return ptr;	
		}
		prev=ptr;
		ptr=ptr->next;
	}
	printf("Element couldn't be found");
}

void printSort(struct linkedlist * head)
{
	struct node * ptr=head->first;

	int arr[head->count], k=0;

	while(ptr!=NULL)
	{
		arr[k]=ptr->ele;
		k++;
		ptr=ptr->next;	
	}
	int tmp;
	for(int i=0;i<head->count;i++)
	{
		for(int j=i;j<head->count;j++)
		{
			if(arr[i]>arr[j])
			{
				tmp=arr[i];
				arr[i]=arr[j];
				arr[j]=tmp;
			}
		}
	}
	for(int i=0;i<head->count;i++)
	{
		printf("%d\t",arr[i]);
	}
}
