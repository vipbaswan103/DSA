#include "fun.h"

int main(int argc, char * argv[])
{
	if(argc!=2)
		exit(0);

	FILE * fp=fopen(argv[1],"r");

	if(fp==NULL)
		exit(0);
	
	char name[11];
	int key;
	
	queue * q=(queue *)malloc(sizeof(queue));
	q->first=NULL;
	q->last=NULL;

	while(fscanf(fp,"\"%[^,],%d\"\n",name,&key)!=EOF)
	{
		createQueue(q,name,key);
	}	
	print(q);

	mergeSort(q);

	printf("\n");
	print(q);
	return 0;
}
