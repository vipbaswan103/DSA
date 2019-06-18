#include "fun.h"

int main(int argc, char * argv[])
{
	if(argc!=2)
		exit(0);
	
	FILE * fp=fopen(argv[1],"r");

	node * root=NULL;
	int tmp;

	while(fscanf(fp,"%d",&tmp)!=EOF)
	{
		insert(&root,tmp);	
	}
	inOrder(root);

	printf("Enter the key to delete: \n");
	scanf("%d",&tmp);
	deleteNode(&root,tmp);
	
	inOrder(root);
	printf("\n");
	int x=numberOfNodes(root);
	printf("Size: %d\n",x);
}
