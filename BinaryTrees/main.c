#include "fun.h"

int main(int argc, char * argv[])
{
	if(argc!=2)
		exit(0);
	
	FILE * fp=fopen(argv[1],"r");

	Node * root=NULL;
	int x;
	while(fscanf(fp,"%d",&x)!=EOF)
	{
		insertInTree(&root,x);	
	}
	inOrder(root);
	printf("\n");
	preOrder(root);
	printf("\n");
	postOrder(root);
	printf("\n");
	//int s=size(root);
	//printf("Size is : %d\n",s);
	int min=minValue(root);
	int max=maxValue(root);
	printf("Min : %d \t Max : %d\n",min,max);
	
	int sta=hasPathSum(root,20);
	printf("Status : %d\n",sta);
	return 0;
}
