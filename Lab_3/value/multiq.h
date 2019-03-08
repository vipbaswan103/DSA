#include "que.h"

typedef struct MultiQ
{
	Queue * q;
}MultiQ;

typedef struct Task
{
	int p;
	int tid;
}Task;

MultiQ createMQ(int num);
MultiQ addMQ(MultiQ mq, Task t);
Task nextMQ(MultiQ mq);
MultiQ delNextMQ(MultiQ mq);
int isEmptyMQ(MultiQ mq);
int sizeMQ(MultiQ mq);
int sizeMQbyPriority(MultiQ mq, int p);
Queue getQueueFromMQ(MultiQ mp, int p);
void printMQ(MultiQ mq);
