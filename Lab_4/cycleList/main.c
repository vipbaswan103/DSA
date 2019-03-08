#include "cycle.h"

int main(int argc, char * argv[])
{
	if(argc!=2)
		exit(1);
	
	FILE * fp=fopen(argv[1],"r");
	
	node * list=NULL;
	
	int tmp;
	while(fscanf(fp,"%d",&tmp)!=EOF)
	{
		list=insert(list,tmp);	
	}
	printf("Result : %d\n",detectCycle(list));	
	print(list);
	printf("Enter ele : ");
	int ele;
	scanf("%d",&ele);

	list=makeCyclic(list,ele);

	int res=detectCycle(list);
	if(res==1)
	{
		printf("Start Node: %d\n",startNode(list)->ele);
		printf("Result : %d\n",res);
	}
	printf("\n");
	print(list);	
}
