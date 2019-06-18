#include "fun.h"

int main(int argc, char * argv[])
{
	if(argc!=2)
		exit(1);
	
	FILE * fp=fopen(argv[1],"r");

	Node * root=NULL;
	Node * dup=NULL;
	int tmp;
	while(fscanf(fp,"%d\n",&tmp)!=EOF)
	{
		insertIterative(&root,tmp);
		insertIterative(&dup,tmp);
	}
	insertIterative(&dup,9);
	insertIterative(&root,10);
	inOrder(root);
	printf("\n");
	//inOrder(dup);

	printf("\n");
	//int x=isBST(root);
	//printf("%d\n",x);
	
	/*Array.i=0;
	makeArray(root);
	for(int i=0;i<Array.i;i++)
	{
		printf("%d\t",Array.arr[i]);
	}*/
	int sum=sumTree(root);
	printf("%d\n",sum);
}
