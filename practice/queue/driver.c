#include "queue.h"

int main(int argc, char* argv[])
{
	if(argc!=2)
	{
		printf("Wrong number of arguments :( ");
		exit(1);
	}

	FILE * fp=fopen(argv[1],"r");

	queue * head=(queue *)malloc(sizeof(queue));
	head->count=0;
	head->first=NULL;
	head->last=NULL;

	char name[101], tmp[101];

	while(fscanf(fp,"%s",name)!=EOF)
	{
		enqueue(head,name);
	}
	
	print(head);

	printf("\nDequeuing ... ");
	node * ptr=dequeue(head);

	printf("\n\nDequeued with return value= %s",ptr->name);

	printf("\n\nFinal queue:\n");
	print(head);

	printf("\nEnter name to search in the queue (max 100 char) :\t");
	scanf("%s",tmp);

	int x=search(head, tmp);

	if(x!=-1)
		printf("\nFound!! Location (Acc to Base 1 indexing scheme): %d\n",x);
	else
		printf("\nNot Found!! :(\n");

	return 0;
}
