#include "que.h"

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
	Queue q=newQ();

	int tmp;
	while(fscanf(fp,"%d",&tmp)!=EOF)
	{
		q=addQ(q,tmp);
	}
	printQ(q);
	printf("\n");
	q=delQ(q);
	printQ(q);
}
