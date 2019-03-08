#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<sys/time.h>
typedef struct task
{
	int tid;	
	int p;
	struct task * next;
}task;

typedef struct queue
{
	task * head;
	task * tail;
}queue;

typedef struct multiq
{
	queue * q;
}multiq;

multiq * createMQ(int num);
void addMQ(multiq * mq, int num, int tid, int p);
task * nextMQ(multiq * mq, int num);
void printMQ(multiq * mq, int num);
void delNextMQ(multiq * mq, int num);
task * nextMQ(multiq * mq, int num);
bool isEmpty(multiq * mq, int num);
int sizeMQbyPriority(multiq * mq, int p);
int sizeMQ(multiq * mq, int num);
queue * getQueueFromMQ(multiq * mq, int num, int p);
