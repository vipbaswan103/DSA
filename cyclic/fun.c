#include "fun.h"
void insert(head * head, int ele)
{
	node * tmp=head->next;
	node * newNode=(node *)malloc(sizeof(node));
	if(tmp==NULL)
	{
		newNode->next=NULL;
		newNode->ele=ele;
		head->next=newNode;
		return;
	}

	while(tmp->next!=NULL)
	{
		tmp=tmp->next;
	}
	tmp->next=newNode;
	newNode->next=NULL;
	newNode->ele=ele;
	return;
}
void print(head * head)
{
	node * tmp=head->next;
	while(tmp!=NULL)
	{
		printf("%d ",tmp->ele);
		tmp=tmp->next;
	}
}

int detectCycle(head * h)
{
	node * tmp=h->next;

	node * hare=tmp;
	node * tort=tmp;
	int x=0;
	while(hare!=NULL && hare->next!=NULL)
	{
		//printf("a\n");
		if(hare==tort && x!=0)
		{
			return 1;
		}
		hare=hare->next->next;
		tort=tort->next;
		x=1;
	}
	return -1;
}
node * search( head * h, int x)
{
	node * tmp=h->next;
	while(tmp!=NULL)
	{
		if(tmp->ele==x)
			return tmp;
		tmp=tmp->next;
	}
	return NULL;
}
node * searchRecursive(node * h, int x)
{
	if(h==NULL)
		return NULL;
	if(h->ele==x)
		return h;

	return searchRecursive(h->next,x);
}
void makeCyclic(head * h, int x)
{
	node * tmp=h->next;
	node * to=search(h,x);
	//printf("%p\t",to);
	if(to!=NULL)
	{
		while(tmp->next!=NULL)
		{
			tmp=tmp->next;
		}
		tmp->next=to;
	}
}

node * startNode(head * h)
{
	node * tmp=h->next;
	int x=detectCycle(h);
	if(x!=-1)
	{
		printf("yes\n");
		node * hare=tmp;
		node * tort=tmp;
		int x=0;
		while(hare!=NULL && hare->next!=NULL)
		{
			if(x!=0 && hare==tort)
				break;
			hare=hare->next->next;
			tort=tort->next;
			x=1;
		}
		tmp=hare;
		node * start=h->next;

		while(tmp!=start)
		{
			start=start->next;
			tmp=tmp->next;
		}
		return start;
	}
	return NULL;
}

int lengthOfCycle(head * h)
{
	node * start=startNode(h);
	if(start!=NULL)
	{
		node * tmp=start->next;
		int count=1;
		while(tmp!=start)
		{
			tmp=tmp->next;
			count++;
		}
		return count;		
	}
	return 0;
}

