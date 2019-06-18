#include "fun.h"

void makeList(head * h)
{
	/*srand(time(NULL));
	for(int i=0;i<10;i++)
	{
		int x=rand();
		x=x%60+20;
		insertNth(h,i,x);
	}*/
}

void printList(head * h)
{
	node * tmp=h->next;
	printf("\n");
	while(tmp!=NULL)
	{
		printf("%d\t",tmp->ele);
		tmp=tmp->next;
	}
	printf("\n");
}
int count(head * h, int key)
{
	node * tmp=h->next;
	int k=0;
	
	while(tmp!=NULL)
	{
		if(tmp->ele==key)
			k++;
		tmp=tmp->next;
	}
	return k;
}

int GetNth(head * h, int index)
{
	node * tmp=h->next;
	int k=0;
	while(tmp!=NULL)
	{
		if(index==k)
			return tmp->ele;
	       	tmp=tmp->next;
		k++;	
	}
	printf("Error: Index out of range\n");
	return -1;
}

void deleteList(head * h)
{
	node * tmp=h->next;
	h->next=NULL;
	node * save;
	while(tmp!=NULL)
	{
		save=tmp->next;
		free(tmp);
		tmp=save;
	}
}

int pop(head * h)
{
	if(h->next==NULL)
	{
		printf("Error: No node to delete\n");
		return -1;
	}
	node * tmp=h->next->next;
	int ele=h->next->ele;
	free(h->next);
	h->next=tmp;
	return ele;
}

void insertNth(head * h, int index, int data)
{
	node * newPtr=(node *)malloc(sizeof(node));
	if(h->next==NULL)
	{
		if(index==0)
		{
			newPtr->next=NULL;
			newPtr->ele=data;
			h->next=newPtr;
			return;
		}
		printf("Error: Invalid Index\n");
		return;
	}
	node * tmp=h->next;
	node * prev;
	int k=0;
	while(tmp!=NULL)
	{
		if(k==index)
		{
			if(k==0)
			{
				newPtr->next=h->next;
				newPtr->ele=data;
				h->next=newPtr;
				return;			
			}
			newPtr->next=prev->next;
			prev->next=newPtr;
			newPtr->ele=data;
			return;
		}
		prev=tmp;
		tmp=tmp->next;
		k++;
	}
	if(index==k)
	{
		prev->next=newPtr;
		newPtr->next=NULL;
		newPtr->ele=data;
		return;
	}
}

void sortedInsert(head * h, node * newNode)
{
	node * prev;
	node * front;
	node * second;
	int k=-1;	
	if(h->next==newNode)
	{
		second=h->next->next;
		k=1;
	}
	else
	{
		k=2;
		node * tmp2=h->next;
		prev=NULL;
		while(tmp2!=NULL)
		{
			if(tmp2==newNode)
			{
				break;
			}
			prev=tmp2;
			tmp2=tmp2->next;
		}
		front=newNode->next;
	//	printf("%d\t%d\n",prev->ele,front->ele);
	}	
	node * tmp=h->next;	
	if(newNode->ele < tmp->ele)
	{
		printf("Yes");
		newNode->next=tmp;
		prev->next=front;
		h->next=newNode;
		return;
	}
	/*if(newNode->ele <= trav->ele)
	{
		if(k==1)
			return;
		newNode->next=trav;
		h->next=newNode;
		prev->next=front;
		return;
	}*/
	node * trav=h->next;
	while(trav->next!=NULL)
	{
		if((trav->ele <= newNode->ele) && (newNode->ele < trav->next->ele))
		{
		//	printf("YES");
			if(trav==newNode)
			{
				trav=trav->next;
				continue;
			}
			node * save=trav->next;
			trav->next=newNode;
			newNode->next=save;
			if(k==1)
			{
				h->next=second;
				return;
			}
			prev->next=front;
			return;
		}
		trav=trav->next;
	}

	if(newNode->ele >= trav->ele)
	{
		printf("NO");
		if(newNode==trav)
			return;
		trav->next=newNode;
		newNode->next=NULL;
		if(k==1)
		{
			h->next=second;
			return;
		}
		prev->next=front;
		return;
	}
}

/*void sortedInsert(head * h, node * newNode)
{
	node * key=newNode;
	node * trav=h->next;
	node * tmp;
	node * prev;
	while(trav->next!=NULL)
	{

		tmp=trav;
		trav=trav->next;
	}
	
	trav=h->next;
	while(trav!=tmp)
	{
		prev=trav;
		trav=trav->next;
	}
	while(tmp!=NULL && tmp->ele>key->ele)
	{
		prev
	}

}*/
void insertSort(head * h)
{
	//node * tmp=h->next->next;
	//sortedInsert(h,tmp);
	node * tmp=h->next;
	node * save;
	printf("\n");
	int val=tmp->ele;
	while(tmp!=NULL)
	{
		printf("\n%d\t%u\n",tmp->ele,tmp);
		save=tmp->next;
		if(save!=NULL && val==tmp->ele)
		{
			if(tmp->ele == save->ele)
			{
				val=tmp->ele;	
				if(save==NULL)
					break;
				tmp=save->next;
				continue;
			}
		}
		val=tmp->ele;
		sortedInsert(h,tmp);
		printList(h);
		printf("\n");
		tmp=save;
	}
}
void append(head * h1, head * h2)
{
	node * tmp1=h1->next;
	if(tmp1==NULL)
	{
		h1->next=h2->next;
		h2->next=NULL;
		return;
	}
	while(tmp1->next!=NULL)
	{
		tmp1=tmp1->next;
	}
	tmp1->next=h2->next;
	h2->next=NULL;
}

int length(head * h)
{
	int k=0;
	node * trav=h->next;
	while(trav!=NULL)
	{
		trav=trav->next;
		k++;
	}
	return k;
}

void frontBackSplit(head * h, head * front, head * back)
{
	int len=length(h);
	if(h==0)
	{
		front->next=NULL;
		back->next=NULL;
		return;
	}

	int k;
	if(len%2==0)
		k=len/2;
	else
		k=(len+1)/2;
	int c=1;
	node * tmp=h->next;
	while(c!=k)
	{
		tmp=tmp->next;
		c++;
	}
	back->next=tmp->next;
	tmp->next=NULL;
	front->next=h->next;
	h->next=NULL;
	free(h);
}
void removeDuplicates(head * h)
{
	node * tmp=h->next;
	
	while(tmp->next!=NULL)
	{
		if(tmp->ele == tmp->next->ele)
		{
			node * save=tmp->next->next;
			free(tmp->next);
			tmp->next=save;
		}
		else
			tmp=tmp->next;
	}
}

void moveNode(head * dest, head * src)
{
	if(src->next==NULL)
	{
		printf("ERROR: Source is empty\n");
		return;
	}
	node * tmp=src->next;
	src->next=tmp->next;
	
	tmp->next=dest->next;
	dest->next=tmp;
}

void alternatingSplit(head * h, head * first, head * second)
{
	if(h->next==NULL)
	{
		first->next=NULL;
		second->next=NULL;
		return;
	}
	int k=0;
	node * tmp=h->next;
	while(h->next!=NULL)
	{
		if(k%2==0)
		{
			moveNode(first,h);
		}
		else
		{
			moveNode(second,h);
		}
		k++;
	}
}
