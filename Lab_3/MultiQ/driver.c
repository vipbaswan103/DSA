#include "multiq.h"
#define NUM 10

struct timeval t1,t2,t3,t4;
double et1=0.0,et2=0.0;
multiq * loadData(FILE * fp)
{
	gettimeofday(&t1,NULL);
	multiq * mq=createMQ(NUM);
	int tid,p;
	while(fscanf(fp,"%d,%d",&tid,&p)!=EOF)
	{
		//printf("%d\t%d",tid,p);
		addMQ(mq,NUM,tid,p);
	}
	gettimeofday(&t2,NULL);
	return mq;
}

multiq * testDel(int n, multiq * mq)
{
	gettimeofday(&t3,NULL);
	for(int i=0;i<n;i++)
	{
		delNextMQ(mq,NUM);
	}
	gettimeofday(&t4,NULL);
	return mq;
}
int main(int argc, char * argv[])
{
	if(argc!=2)
	{
		printf("Error: Wrong number of arguments\n");
		exit(0);
	}

	FILE * fp=fopen(argv[1],"r");

	multiq * mq=loadData(fp);
	
	printMQ(mq,NUM);
	
	mq=testDel(7,mq);
	printMQ(mq,NUM);

	task * t=nextMQ(mq, NUM);
	if(t!=NULL)
		printf("\nTask id: %d\t Priority: %d\n",t->tid,t->p);

	printf("Is MQ empty?? %d\n",isEmpty(mq,NUM));

	printf("\nTotal Size: %d\n",sizeMQ(mq,NUM));
	
	queue * q=getQueueFromMQ(mq,NUM,5);

	task * trav=q->head;
	while(trav!=NULL)
	{
		printf("%d\t",trav->tid);
		trav=trav->next;
	}

	printf("\n\n**************************************************  MEASUREMENTS  ************************************************************\n\n");
	et1=(t2.tv_sec-t1.tv_sec)*1000.0;
	et1+=(t2.tv_usec-t1.tv_usec)/1000.0;
	printf("Time taken for loading the data in MQ is %f ms\n",et1);

	et2=(t4.tv_sec-t3.tv_sec)*1000.0;
	et2+=(t4.tv_usec-t3.tv_usec)/1000.0;
	printf("\nTime taken for deletion in testDel is %f ms\n",et2);
	fclose(fp);
}
