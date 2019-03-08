#include "cycle.h"

node * insert(node * list, int ele)
{
	node * newNode=(node *)malloc(sizeof(node));
	if(list==NULL)
	{
		newNode->next=NULL;
		newNode->ele=ele;
		list=newNode;
		return list;
	}
	
	node * tmp=list;
	while(tmp->next!=NULL)
	{
		tmp=tmp->next;
	}
	tmp->next=newNode;
	newNode->next=NULL;
	newNode->ele=ele;
	return list;
}

node * makeCyclic(node * list, int ele)
{
	node * tmp=list;
	while(tmp!=NULL)
	{
		if(tmp->ele==ele)
			break;
		tmp=tmp->next;
	}
	if(tmp==NULL)
	{
		printf("ERROR: Element not found\n");
		return list;
	}
	node * last=list;
	while(last->next!=NULL)
	{
		last=last->next;
	}

	last->next=tmp;
	return list;
}
int detectCycle(node * list)
{
	if(list==NULL)
		return 0;
	if(list->next==list)
		return 1;
	node * hare=list;
	node * tort=list;
	int x=0;
	while(hare!=NULL && hare->next!=NULL)
	{
		if(hare==tort&& x!=0)
		{
			return 1;
		}
		x=1;
		tort=tort->next;
		hare=hare->next->next;
	}
	return 0;
}

node * startNode(node * list)
{
	node * hare=list;
	node * tort=list;
	int x=0;
	while(hare!=tort || x==0)
	{
		x=1;
		tort=tort->next;
		hare=hare->next->next;
	}
	node * meetFirst=hare;
	node * tmp=list;

	while(tmp!=meetFirst)
	{
		tmp=tmp->next;
		meetFirst=meetFirst->next;
	}
	return tmp;
}

int lengthCycle(node * list)
{
	node * start=startNode(list);

	node * tmp=start->next;
	int k=1;
	while(tmp!=start)
	{
		k++;
		tmp=tmp->next;
	}
	return k;
}

void print(node * list)
{
	if(detectCycle(list)==1)
	{
		node * start=startNode(list);
		//printf("Start: %d", start->ele);
		node * tmp=list;

		while(tmp!=start)
		{
			printf("%d\t",tmp->ele);
			tmp=tmp->next;
		}
		printf("%d\t",tmp->ele);
		tmp=start->next;

		while(tmp!=start)
		{
			printf("%d\t",tmp->ele);
			tmp=tmp->next;
		}
		printf("Points to %d",tmp->ele);
	}
	else
	{
		node * tmp=list;
		while(tmp!=NULL)
		{
			printf("%d\t",tmp->ele);
			tmp=tmp->next;
		}
	}
}
