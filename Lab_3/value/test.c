#include "multiq.h"
#include <sys/time.h>
struct timeval t1,t2,t3,t4;
double et1,et2;
MultiQ loadData(MultiQ mq, FILE * fp)
{
	Task t;
	int id,p;

	while(fscanf(fp,"%d,%d\n",&id,&p)!=EOF)
	{
		t.tid=id;
		t.p=p;
		mq=addMQ(mq,t);
	}
	return mq;
}
MultiQ testDel(MultiQ mq, int num)
{
	for(int i=0;i<num;i++)
	{
		mq=delNextMQ(mq);
	}
	return mq;
}
int main(int argc, char * argv[])
{
	if(argc!=2)
		exit(0);
	FILE * fp=fopen(argv[1],"r");
	if(fp==NULL)
	{
		printf("Error in opening file\n");
		exit(0);
	}

	MultiQ mq=createMQ(10);
	
	gettimeofday(&t1,NULL);
	mq=loadData(mq,fp);
	gettimeofday(&t2,NULL);
	
	printMQ(mq);	
	printf("Current size: %d\n",sizeMQ(mq));
	
	gettimeofday(&t3,NULL);
	mq=testDel(mq,100);
	gettimeofday(&t4,NULL);
	
	printMQ(mq);
	printf("Current size: %d\n",sizeMQ(mq));

	et1=(t2.tv_sec-t1.tv_sec)*1000.0;
	et1+=(t2.tv_usec-t1.tv_usec)/1000.0;

	et2=(t4.tv_sec-t3.tv_sec)*1000.0;
	et2+=(t4.tv_usec-t3.tv_usec)/1000.0;

	printf("**********MEASUREMENTS**************\n");
	printf("Time taken for laoding: %f\n",et1);
	printf("Time taken for 5 deletions: %f\n",et2);
	printf("Time taken per deletion: %f\n",et2/5);

	/*printf("\nQueue with priority 6 is :\n");
	Queue q=getQueueFromMQ(mq,6);
	printQ(q);
	printf("\n");*/
	return 0;
}
