#include "multiq.h"
#define max 10
MultiQ createMQ(int num)
{
	MultiQ mq;

	mq.q=(Queue *)malloc(sizeof(Queue)*num);

	for(int i=0;i<num;i++)
	{
		mq.q[i]=newQ();
	}
	return mq;
}

MultiQ addMQ(MultiQ mq, Task t)
{
	int p=(t.p)-1;
	mq.q[p]=addQ(mq.q[p], t.tid);
	return mq;
}

Task nextMQ(MultiQ mq)
{
	for(int i=max-1;i>=0;i--)
	{
		if(mq.q[i].head!=NULL)
		{
			Task t;
			t.p=i+1;
			t.tid=(mq.q[i].head)->ele;
			return t;
		}
	}
	printf("Empty MultiQ!!\n");
	Task t;
	t.p=-1;
	t.tid=-1;
	return t;
}

MultiQ delNextMQ(MultiQ mq)
{
	for(int i=max-1;i>=0;i--)
	{
		if(mq.q[i].head!=NULL)
		{
			mq.q[i]=delQ(mq.q[i]);
			return mq;
		}
	}
	printf("Error: MultiQ is empty\n");
	return mq;
}

int isEmptyMQ(MultiQ mq)
{
	for(int i=0;i<max;i++)
	{
		if(mq.q[i].head!=NULL)
			return 0;
	}
	return 1;
}

int sizeMQbyPriority(MultiQ mq, int p)
{
	int count=0;
	
	node * tmp=mq.q[p-1].head;

	while(tmp!=NULL)
	{
		count++;
		tmp=tmp->next;
	}
	return count;
}
int sizeMQ(MultiQ mq)
{
	int size=0;
	for(int i=0;i<max;i++)
	{
		size+=sizeMQbyPriority(mq,i+1);
	}
	return size;
}

Queue getQueueFromMQ(MultiQ mq, int p)
{
	Queue que=mq.q[p-1];
	return que;
}

void printMQ(MultiQ mq)
{
	printf("Priority\t\t\tTaskID\n");
	for(int i=0;i<max;i++)
	{
		printf("%d\t\t\t\t",i+1);
		printQ(mq.q[i]);
		printf("\n");
	}
}
