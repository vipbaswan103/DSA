#include "list.h"

node * insert(node * head, int val)
{
	node * newNode=(node *)malloc(sizeof(node));
	if(head==NULL)
	{
		newNode->next=NULL;
		newNode->val=val;
		head=newNode;
		return head;
	}

	node * tmp=head;

	while(tmp->next!=NULL)
	{
		tmp=tmp->next;
	}
	tmp->next=newNode;
	newNode->next=NULL;
	newNode->val=val;
	return head;
}
void print(node * head)
{
	node * tmp=head;
	printf("\n");
	while(tmp!=NULL)
	{
		if(tmp->next!=NULL)
			printf("%d->",tmp->val);
		else
			printf("%d\n",tmp->val);
			
		tmp=tmp->next;
	}
}

node * merge(node * h1, node * h2, node * out)
{
	node * tmp1=h1;
	node * tmp2=h2;
	node * tmp3=out;
	
	int toput;
	while(tmp1!=NULL && tmp2!=NULL)
	{
		if(tmp1->val<=tmp2->val)
		{
			toput=tmp1->val;
			tmp1=tmp1->next;
		}
		else
		{
			toput=tmp2->val;
			tmp2=tmp2->next;
		}
		tmp3=insert(tmp3,toput);
	}
	while(tmp1!=NULL)
	{
		tmp3=insert(tmp3,tmp1->val);
		tmp1=tmp1->next;
	}
	while(tmp2!=NULL)
	{
		tmp3=insert(tmp3,tmp2->val);
		tmp2=tmp2->next;
	}
	return tmp3;
}

void mergeSort(node * head, node * p, node * r)
{
	node * h1, *h2, *out;
	if(p<r)
	{
		node * tmp1=p;
		node * tmp2=r;
		int c=0;
		while(tmp1!=tmp2)
		{
			c++;
			tmp1=tmp1->next;
		}
		int k=0;
		tmp1=p;
		node * q;
		while(k<=c/2)
		{
			q=tmp1;
			k++;
			tmp1=tmp1->next;
		}

		mergeSort(head, p,q);
		mergeSort(head,q->next,r);
		out=NULL;
		tmp1=p;	
		h1=NULL;
		h2=NULL;
		while(tmp1!=q->next)
		{
			h1=insert(h1,tmp1->val);
			tmp1=tmp1->next;
		}
		tmp1=q->next;
		while(tmp1!=r->next)
		{
			h2=insert(h2,tmp1->val);
			tmp1=tmp1->next;
		}
		out=merge(h1,h2,out);
		if(p==head)
		{
			tmp1=head;
			tmp2=out;
			while(tmp2!=NULL)
			{
				tmp1->val=tmp2->val;
				tmp1=tmp1->next;
				tmp2=tmp2->next;
			}
		}
		else
		{
			node * t1, * t2;
			t1=head;			
			while(t1!=p)
			{
				t1=t1->next;
			}
			
			t2=out;
			while(t2!=NULL)
			{
				t1->val=t2->val;
				t1=t1->next;
				t2=t2->next;
			}
		}
	}
}

void insertInOrder(node ** head, node * add)
{
	node * trav=*head;
	if(*head==NULL || add->val <= trav->val)
	{
		node * tmp=*head;
		*head=add;
		add->next=tmp;
		return;
	}
	while(trav->next!=NULL)
	{
		if(add->val >= trav->val && add->val < trav->next->val)
		{
			node * tmp=trav->next;
			trav->next=add;
			add->next=tmp;
			return;
		}
		trav=trav->next;
	}
	trav->next=add;
	add->next=NULL;
	return;
}

void insertionSort(node ** head)
{
	node * sorted=NULL;
	node * trav=*head;

	while(trav!=NULL)
	{
		node * n=trav->next;
		insertInOrder(&sorted,trav);
		trav=n;
	}
	*head=sorted;
}
