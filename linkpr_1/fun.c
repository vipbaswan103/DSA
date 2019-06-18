#include "fun.h"

void insertNode(node ** head, int ele)
{
	node * trav=*head;

	node * newNode=(node*)malloc(sizeof(node));
	if(*head==NULL)
	{
		newNode->ele=ele;
		newNode->next=NULL;
		*head=newNode;
		return;
	}
	
	while(trav->next!=NULL)
	{
		trav=trav->next;
	}
	newNode->next=NULL;
	newNode->ele=ele;
	trav->next=newNode;
	return;
}
void printList(node * head)
{
	node * trav=head;
	while(trav!=NULL)
	{
		if(trav->next!=NULL)
			printf("%d -> ",trav->ele);
		else
			printf("%d\n",trav->ele);
		trav=trav->next;
	}
}
int length(node * head)
{
	int k=0;
	node * tmp=head;
	while(tmp!=NULL)
	{
		k++;
		tmp=tmp->next;
	}
	return k;
}
int getNth(node * head, int n)
{
	node * tmp=head;
	int len=length(head), k=0;
	
	if(len==0 || k>n-1)
	{
		return -1;
	}
	
	if(n==0)
		return head->ele;
	while(k!=n && tmp!=NULL)
	{
		k++;
		tmp=tmp->next;	
	}
	return tmp->ele;
}

void deleteList(node ** head)
{
	node * tmp=*head;

	while(tmp!=NULL)
	{
		node * save=tmp->next;
		free(tmp);
		tmp=save;
	}
	*head=NULL;
}

void push(node ** head, int ele)
{
	node * tmp=*head;
	node * newNode=(node *)malloc(sizeof(node));
	newNode->next=*head;
	newNode->ele=ele;
	*head=newNode;
}

int pop(node ** head)
{
	if(*head==NULL)
	{
		return -1;
	}
	node * save=(*head)->next;
	int tmp=(*head)->ele;
	free(*head);
	*head=save;
	return tmp;
}

int insertNth(node ** head, int n, int ele)
{
	node * newNode=(node *)malloc(sizeof(node));
	node * tmp=*head;
	if(*head==NULL)
	{
		if(n==0)
		{
			newNode->next=NULL;
			newNode->ele=ele;
			*head=newNode;
			return 1;
		}
		return -1;
	}
	int k=0;
	node * prev;
	while(k!=n && tmp!=NULL)
	{
		k++;
		prev=tmp;
		tmp=tmp->next;
	}
	if(tmp!=NULL)
	{
		node * save=tmp->next;
		tmp->next=newNode;
		newNode->next=save;
		newNode->ele=ele;
		return 1;
	}
	if(k==n)
	{
		prev->next=newNode;
		newNode->next=NULL;
		newNode->ele=ele;
		return 1;
	}
	return -1;	
}

void sortedInsert(node ** head, node * newNode)
{	
	node * trav=*head;
	if(*head==NULL)
	{
		newNode->next=NULL;
		*head=newNode;
	}
	else
	{
		if(newNode->ele <= trav->ele)
		{
			newNode->next=*head;
			*head=newNode;
			return;
		}
		while(trav->next!=NULL)
		{
			if(newNode->ele >=trav->ele && newNode->ele <trav->next->ele)
			{
				node * save=trav->next;
				trav->next=newNode;
				newNode->next=save;
				return;
			}
			trav=trav->next;
		}
		newNode->next=NULL;
		trav->next=newNode;
	}
}
void insertionSort(node ** head)
{
	node * sorted=NULL;

	node * trav=*head;
	while(trav!=NULL)
	{
		node * tmp=trav->next;
		sortedInsert(&sorted,trav);
		trav=tmp;
	}
	*head=sorted;
}

node * splitList(node * head)
{
	if(head==NULL)
		return head;
	node * tmp=head;

	if(tmp->next==NULL)
	{
		return NULL;
	}
	node * prev=tmp;
	while(tmp->next!=NULL)
	{
		prev=tmp;
		tmp=tmp->next;
	}
	prev->next=NULL;
	return tmp;
}
void recursiveInsertionSort(node ** head)
{
	if((*head)->next!=NULL)
	{
		node * last=splitList(*head);
		recursiveInsertionSort(head);
		sortedInsert(head,last);
	}
}
void append(node ** a, node ** b)
{
	if(*a==NULL)
	{
		*a=*b;
		*b==NULL;
		return;
	}
	node * tmp=*a;

	while(tmp->next!=NULL)
	{
		tmp=tmp->next;
	}
	tmp->next=*b;
	*b=NULL;
}
void frontBackSplit(node * src, node ** front, node ** back)
{
	if(src==NULL)
	{
		*front=NULL;
		*back=NULL;
		return;
	}
	if(src->next==NULL)
	{
		*front = src;
		*back=NULL;
		return;
	}
	int len=length(src);

	int crit;
	if(len%2==0)
		crit=(len/2)-1;
	else
		crit=(len/2);

	node * tmp=src;

	int k=0;
	while(k!=crit)
	{
		k++;
		tmp=tmp->next;
	}
	*back=tmp->next;
	tmp->next=NULL;
	*front=src;
}
void moveNode(node ** dest, node ** src)
{
	if(*src==NULL)
	{
		printf("ERROR: Src list empty!\n");
		return;
	}
	node * first=(*src);
	node * tmp=(*src)->next;
	*src=tmp;
	first->next=*dest;
	*dest=first;
}

void alternatingSplit(node * src, node ** a, node ** b)
{
	if(src==NULL)
	{
		*a=NULL;
		*b=NULL;
		return;
	}
	int len=length(src);
	for(int k=0;k<len;k++)
	{
		if(k%2==0)
			moveNode(a,&src);
		else
			moveNode(b,&src);
	}
}

void moveNodeLast(node ** dest, node ** src)
{
	if(*src==NULL)
	{
		printf("ERROR: Src list empty!\n");
		return;
	}
	node *last=*dest;
	if(last!=NULL)
	{
		while(last->next!=NULL)
			last=last->next;
	}
	node * first=(*src);
	node * tmp=(*src)->next;
	*src=tmp;
	if(last==NULL)
	{
		first->next=NULL;
		*dest=first;
	}
	else
	{
		last->next=first;
		first->next=NULL;
	}
}

node * shuffleMerge(node * a, node * b)
{
	node * tmp=NULL;
	node * t1=a, *t2=b;

	int i=0;
	while(t1!=NULL && t2!=NULL)
	{
		if(i%2==0)
			moveNodeLast(&tmp,&t1);
		else
			moveNodeLast(&tmp,&t2);
		i++;
	}
	while(t1!=NULL)
	{
		moveNodeLast(&tmp,&t1);
	}
	while(t2!=NULL)
	{
		moveNodeLast(&tmp,&t2);
	}
	return tmp;
}
node * sortedMerge(node * a, node * b)
{
	node * sorted=NULL;
	node * t1=a, *t2=b;
	while(t1!=NULL && t2!=NULL)
	{
		if(t1->ele <= t2->ele)
			moveNodeLast(&sorted,&t1);
		else
			moveNodeLast(&sorted,&t2);
	}
	while(t1!=NULL)
	{
		moveNodeLast(&sorted,&t1);
	}
	while(t2!=NULL)
	{
		moveNodeLast(&sorted,&t2);
	}
	return sorted;
}

void mergeSort(node ** head)
{
	node *front=NULL, *back=NULL;
	if((*head)->next!=NULL)
	{
		frontBackSplit(*head,&front,&back);
		mergeSort(&front);
		mergeSort(&back);
		*head=sortedMerge(front,back);
	}
}

node * sortedIntersect(node * a, node * b)
{
	node * t1=a, *t2=b;

	node * intersect=NULL;
		
}

void reverse(node ** head)
{
	node * tmp=*head;
	node * prev=NULL;
	node * front=(*head)->next;

	while(tmp!=NULL)
	{
		tmp->next=prev;
		prev=tmp;
		tmp=front;
		if(front!=NULL)
		{
			front=front->next;
		}	
	}
	*head=prev;
}

void reverseOther(node ** head)
{
	node * reverse=NULL;
	node * tmp=*head;
	node * save;
	while(tmp!=NULL)
	{
		save=tmp->next;
		if(reverse==NULL)
		{
			reverse=tmp;
			tmp->next=NULL;
		}
		else
		{
			tmp->next=reverse;
			reverse=tmp;	
		}
		tmp=save;
	}
	*head=reverse;
}

/*void recursiveReverse(node ** head)
{
	static node * prev=*head;
	if((*head)->next!=NULL)
	{
		node * tmp=*head;
		node * p=NULL;
		while(tmp->next!=NULL)
		{
			p=tmp;
			tmp=tmp->next;
		}	
		p->next=NULL;
		tmp->next=*head;
		prev->next=tmp;
		*head=prev;
		prev=*head;

		recursiveReverse((*head)->next);
	}
}*/

void recursiveReverse(node ** head)
{
	if((*head)->next!=NULL)
	{
		node * first=*head;
		node * rest=first->next;
		
		printf("First = %d  Last= %d\n",first->ele, rest->ele);
		recursiveReverse(&rest);
		
		first->next->next=first;
		first->next=NULL;
		
		printf("First = %d  Last= %d\t",first->ele, rest->ele);
		printf("Before: %p Data: %d\t",(rest), (rest)->ele);
		
		*head=rest;
		printf("After: %p Data: %d\n",(rest), (rest)->ele);
	}
}

node * getPrev(node * head, node * ptr)
{
	node * tmp=head;
	if(head==NULL)
	{
		return NULL;
	}
	if(ptr==head)
	{
		return NULL;
	}
	node * prev;
	while(tmp!=ptr)
	{
		prev=tmp;
		tmp=tmp->next;
	}
	return prev;
}
node * partitionList(node ** head, node ** low, node ** high)
{
	//printf("1\n");		
	node * i=*head;
	node * tmp=*head;
	while(tmp!=*low)
	{
		i=tmp;
		tmp=tmp->next;
	}
	if(*low==*head)
	{
		i=NULL;
	}
	node * j=*low;
	node * pivot=*high;

	while(j!=*high)
	{
		node * save=j->next;
		if(j->ele <= pivot->ele)
		{
			if(i==NULL)
				i=*head;
			else
				i=i->next;
			if(i!=j)
			{
				node * prevj=getPrev(*head, j);
				node * previ=getPrev(*head ,i);
				node * nextj=j->next;
				if(prevj!=NULL && previ!=NULL)
				{
					if(i->next!=j)
					{
						j->next=i->next;
						previ->next=j;
						i->next=nextj;
						prevj->next=i;
					}
					else
					{
						i->next=j->next;
						previ->next=j;
						j->next=i;
					}
				}
				else
				{
					if(previ==NULL)
					{
						j->next=i->next;
						*head=j;
						i->next=nextj;
						prevj->next=i;
					}
				}
				if(i==*low)
				{
					*low=j;
				}
				i=j;
			}
			
		}
		j=save;
	}
	
	if(i!=NULL)
		i=i->next;
	else
		i=*head;
	
	node * previ=getPrev(*head ,i);
	node * nextj=pivot->next;
	node * prevj=getPrev(*head,pivot);	
	if(prevj!=NULL && previ!=NULL)
	{
		if(i->next!=pivot)
		{
			pivot->next=i->next;
			previ->next=pivot;
			i->next=nextj;
			prevj->next=i;
		}
		else
		{
			previ->next=pivot;
			i->next=pivot->next;
			pivot->next=i;
		}
	}
	else
	{
		if(previ==NULL)
		{
			pivot->next=i->next;
			*head=pivot;
			i->next=nextj;
			prevj->next=i;
		}
	}
	if(i==*low)
	{
		*low=pivot;
	}
	*high=i;
	return pivot;
}

int isPrevious(node * head, node * start, node * end)
{
	if(start!=NULL && end==NULL)
		return 1;
	if(start==end)
		return 1;
	
	node * tmp=head;
	while(tmp!=start)
	{
		if(tmp==end)
			return 1;
		tmp=tmp->next;
	}
	return 0;
}
void quickSort(node ** head, node ** start, node ** end)
{
	if(isPrevious(*head, *start, *end)==0)
	{
		node * piv=partitionList(head, start,end);
		node * prev=getPrev(*head,piv);
		quickSort(head,start,&prev);
		quickSort(head,&(piv->next),end);
	}
}

int lengthRecursive(node * head)
{
	if(head==NULL)
		return 0;
	return 1+length(head->next);
}


