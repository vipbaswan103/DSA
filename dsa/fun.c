#include "fun.h"

void print(queue * q)
{
	node * tmp=q->first;
	while(tmp!=NULL)
	{
		printf("%s,%d\n",tmp->name,tmp->key);
		tmp=tmp->next;
	}
}

void createQueue(queue * q, char name[], int key)
{
	node * newNode=(node *)malloc(sizeof(node));
	
	newNode->key=key;
	strcpy(newNode->name, name);
	
	if(q->first==NULL)
	{
		q->first=newNode;
		q->last=newNode;
		newNode->next=NULL;
		return;
	}
	q->last->next=newNode;
	newNode->next=NULL;
	q->last=newNode;
}

void deleteNode(queue * q)
{
	if(q->first==NULL)
	{
		printf("Empty queue\n");
		return;
	}
	if(q->first->next==NULL)
	{
		node * save=q->first;
		q->first=NULL;
		q->last=NULL;
		save->next=NULL;
		free(save);
		return;
	}
	node * save=q->first;
	q->first=save->next;
	save->next=NULL;
	free(save);
}
node * getPrev(queue * q, node * n)
{
	if(q->first==NULL)
		return NULL;
	if(q->first==n)
		return NULL;

	node * tmp=q->first;
	node * prev;
	while(tmp!=NULL)
	{
		if(tmp==n)
			return prev;
		prev=tmp;
		tmp=tmp->next;
	}
}
node * partition(queue * q, node * lo, node * hi)
{
	node * i=getPrev(q,lo);
	node * j=lo;
	int piv=hi->key;
	while(j!=hi)
	{
		if(j->key <= piv)
		{
			if(i==NULL)
				i=q->first;
			else
				i=i->next;

			int tmp=i->key;
			i->key=j->key;
			j->key=tmp;

			char name[11];
			strcpy(name,i->name);
			strcpy(i->name,j->name);
			strcpy(j->name,name);
		}	
		j=j->next;
	}
	if(i==NULL)
		i=q->first;
	else
		i=i->next;
	int tmp=i->key;
	i->key=j->key;
	j->key=tmp;

	char name[11];
	strcpy(name,i->name);
	strcpy(i->name,j->name);
	strcpy(j->name,name);
	return i;	
}
int isPrevious(queue * q, node * lo, node * hi)
{
	if(q->first==NULL)
		return 0;
	if(hi==NULL)
		return 0;

	int f1=0, f2=0;

	node * tmp=q->first;
	while(tmp!=NULL)
	{
		if(tmp==lo)
		{
			f1=1;
			if(tmp==hi)
				f2=1;
			break;
		}
		if(tmp==hi)
		{
			f2=1;
			break;
		}
		tmp=tmp->next;
	}
	if(f1==1 && f2==0)
		return 1;
	return 0;
}
void quickSort(queue * q, node * lo, node * hi)
{
	if(isPrevious(q,lo,hi)==1)
	{
		node * piv=partition(q,lo,hi);
		quickSort(q,lo,getPrev(q,piv));
		quickSort(q,piv->next,hi);
	}
}

int length(queue * q)
{
	node * tmp=q->first;
	int k=0;
	//print(q);
	while(tmp!=NULL)
	{
		k++;
		tmp=tmp->next;
	}
	return k;
}
void split(queue * q, queue *q1, queue *q2)
{
	if(q->first==NULL)
	{
		return;
	}
	if(q->first->next==NULL)
	{
		q1->first=q->first;
		q->first=NULL;
		return;
	}
	//printf("yesssssssss\n");
	//printf("5\n");
	int len=length(q);
	int k=0;
	if(len%2!=0)
		k=(len+1)/2;
	else
		k=len/2;
	
	int s=0;
	node * tmp=q->first;
	//print(q);
	while(s<k-1)
	{
		s++;
		tmp=tmp->next;
	}	
	node * save=tmp->next;
	tmp->next=NULL;
	q1->first=q->first;
	q2->first=save;
}

void insertInQueue(queue * q, node * newNode)
{
	if(q->first==NULL)
	{
		q->first=newNode;
		q->last=newNode;
		newNode->next=NULL;
		return;
	}
	q->last->next=newNode;
	newNode->next=NULL;
	q->last=newNode;
}

void merge(queue * q1, queue * q2, queue * q)
{
	node * t1=q1->first;
	node * t2=q2->first;
	
	node * s1, *s2;
	while(t1!=NULL && t2!=NULL)
	{
		if(t1->key <= t2->key)
		{
			s1=t1->next;
			insertInQueue(q,t1);
			t1=s1;
		}
		else
		{
			s2=t2->next;
			insertInQueue(q,t2);
			t2=s2;
		}
	}

	while(t1!=NULL)
	{
		s1=t1->next;
		insertInQueue(q,t1);
		t1=s1;
	}
	while(t2!=NULL)
	{
		s2=t2->next;
		insertInQueue(q,t2);
		t2=s2;
	}
}

void mergeSort(queue * q)
{
	if(q->first==NULL || (q->first)->next==NULL)
	{
		return;
	}
	queue * q1=(queue *)malloc(sizeof(queue));
	queue * q2=(queue *)malloc(sizeof(queue));
	q1->first=NULL;
	q1->last=NULL;
	q2->first=NULL;
	q2->last=NULL;
	split(q,q1,q2);

	mergeSort(q1);
	mergeSort(q2);

	queue * q3=(queue *)malloc(sizeof(queue));
	q3->first=NULL;
	q3->last=NULL;
	merge(q1,q2,q3);
	q->first=q3->first;
	q->last=q3->last;	
}
