#include "dcirlist.h"
#include "compare.h"

void insertNode(node * sentinel, int ele)
{
	node * nptr=(node *)malloc(sizeof(node));
	if(sentinel->next==sentinel && sentinel->prev==sentinel)
	{	
		sentinel->next=nptr;
		nptr->prev=sentinel;
		nptr->next=sentinel;
		sentinel->prev=nptr;
		sentinel->ele++;
		nptr->ele=ele;
		return ;
	}
	
	node * ptr=sentinel->next;

	if(compare(sentinel->next->ele,ele)==GREATER || compare(sentinel->next->ele,ele)==EQUAL)
	{		
		nptr->next=sentinel->next;
		nptr->prev=sentinel;
		sentinel->next->prev=nptr;
		sentinel->next=nptr;
		nptr->ele=ele;
		sentinel->ele++;
		return;
	}	
	while(ptr->next!=sentinel)
	{
		if(compare(ele,ptr->ele)==GREATER || compare(ele,ptr->ele)==EQUAL)
		{
			if(compare(ele,ptr->next->ele)==LESSER)
			{
				nptr->next=ptr->next;
				nptr->prev=ptr;
				ptr->next->prev=nptr;
				ptr->next=nptr;
				nptr->ele=ele;
				sentinel->ele++;
				return;
			}
		}
		ptr=ptr->next;		
	}
	ptr->next=nptr;
	nptr->prev=ptr;
	nptr->next=sentinel;
	sentinel->prev=nptr;
	nptr->ele=ele;
	sentinel->ele++;
}

node * search(node * sentinel, int key)
{
	node * ptr=sentinel->next;
	while(ptr!=sentinel)
	{
		if(ptr->ele==key)
			return ptr;
		ptr=ptr->next;
	}
	return NULL;
}
node * deleteNode(node * sentinel, int key)
{
	node * res=search(sentinel, key);
	if(res==NULL)
	{
		printf("Element not found!");
		return NULL;
	}
	res->prev->next=res->next;
	res->next->prev=res->prev;
	sentinel->ele--;
	return res;
}

void printForward(node * sentinel)
{
	node * ptr=sentinel->next;

	printf("Size: %d\n",sentinel->ele);
	while(ptr!=sentinel)
	{
		printf("%d\n",ptr->ele);
		ptr=ptr->next;
	}
}

void printBackward(node * sentinel)
{
	node * ptr=sentinel->prev;

	printf("Size: %d\n",sentinel->ele);
	while(ptr!=sentinel)
	{
		printf("%d\n",ptr->ele);
		ptr=ptr->prev;
	}
}
