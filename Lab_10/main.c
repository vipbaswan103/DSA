#include "tree.h"

int main(int argc, char * argv[])
{
	if(argc!=2)
		exit(0);
	FILE * fp=fopen(argv[1],"r");
	
	Node * root=NULL;
	int key;
	while(fscanf(fp,"%d\n",&key)!=EOF)
	{
		//inOrder(root);
		root=addBalanced(root,key);
	}
	inOrder(root);
	
	printf("\n");
	root=delete(root,2);
	root=delete(root,3);
	inOrder(root);
	//rangeQuery(root,1,20);

	//for(int i=0;i<Range.index;i++)
	//{
	//	printf("%d\t",Range.arr[i]);
	//}
	printf("\n");
	return 0;
}
