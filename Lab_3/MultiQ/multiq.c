#include "multiq.h"

multiq * createMQ(int num)
{
	multiq * mq=(multiq *)malloc(sizeof(multiq)*num);
	for(int i=0;i<num;i++)
	{
		mq[i].q=(queue*)malloc(sizeof(queue));
		mq[i].q->head=NULL;
		mq[i].q->tail=NULL;
	}
	return mq;
}

void addMQ(multiq * mq, int num, int tid, int p)
{	
	task * obj=(task *)malloc(sizeof(task));
	obj->tid=tid;
	obj->p=p;

	if(p>num)
	{
		printf("Error: Out of range Priority number");
		return;
	}

	if(mq[p-1].q->head==NULL && mq[p-1].q->tail==NULL)
	{
	//	printf("Here");
		mq[p-1].q->head=obj;
		mq[p-1].q->tail=obj;
		obj->next=NULL;
		return;
	}
	//printf("TOO");
	task * tmp=mq[p-1].q->tail;
	tmp->next=obj;
	obj->next=NULL;
	mq[p-1].q->tail=obj;
}

task * nextMQ(multiq * mq, int num)
{
	for(int i=num-1;i>=0;i--)
	{
		if(mq[i].q->head!=NULL)
		{
			return mq[i].q->head;
		}
	}
	printf("Error: All Queues are empty\n");
	return NULL;
}

void printMQ(multiq * mq, int num)
{
	task * trav;
	printf("Priority\t\tQueue\n");
	for(int i=0;i<num;i++)
	{
		printf("%d\t\t\t",i+1);
		trav=mq[i].q->head;
		while(trav!=NULL)
		{
			printf("%d, ",trav->tid);
			trav=trav->next;
		}
		printf("\n");
	}
	printf("***END***\n\n");
}
void delNextMQ(multiq * mq, int num)
{
	for(int i=num-1;i>=0;i--)
	{
		if(mq[i].q->head!=NULL)
		{
			if(mq[i].q->head==mq[i].q->tail && mq[i].q->head!=NULL)
			{
				task * tmp=mq[i].q->head->next;
				free(mq[i].q->head);
				mq[i].q->head=tmp;
				mq[i].q->tail=tmp;
				return;
			}
			task * tmp=mq[i].q->head->next;
			free(mq[i].q->head);
			mq[i].q->head=tmp;
			return;
		}
	}	
}
bool isEmpty(multiq * mq, int num)
{
	for(int i=0;i<num;i++)
	{
		if(mq[i].q->head!=NULL)
			return false;
	}
	return true;
}

int sizeMQbyPriority(multiq * mq, int p)
{
	int k=0;
	if(mq[p].q->head==mq[p].q->tail && mq[p].q->head==NULL)
		return k;
	task * trav=mq[p].q->head;
	while(trav!=NULL)
	{
		k++;
		trav=trav->next;
	}	
	return k;
}

int sizeMQ(multiq * mq, int num)
{
	int sum=0;
	for(int i=0;i<num;i++)
	{
		sum+=sizeMQbyPriority(mq,i);
	}
	return sum;
}
queue * getQueueFromMQ(multiq * mq, int num,int p)
{
	if(p>num)
	{
		printf("Error: No such queue\n");
		return NULL;
	}
	return mq[p-1].q;
}
