#include "fun.h"

int main(int argc, char * argv[])
{
	if(argc!=2)
		exit(0);
	FILE * fp=fopen(argv[1],"r");
	
	head * h=(head *)malloc(sizeof(head));
	int tmp;

	while(fscanf(fp,"%d",&tmp)!=EOF)
	{
		insert(h,tmp);
	}
	print(h);
	
	printf("What to search? \t");
	scanf("%d",&tmp);
	node * ptr=searchRecursive(h->next,tmp);
	if(ptr!=NULL)
	{
		printf("Found : %d",ptr->ele);
	}
	else
	{
		printf("Not Found\n");
	}
	/*makeCyclic(h,1);
	node * start=startNode(h);
	printf("%d\n",detectCycle(h));
	if(start!=NULL)
		printf("\n%d\n",start->ele);
	else
		printf("Not cyclic\n");	

	int len=lengthOfCycle(h);
	printf("Length: %d\n",len);*/
}
