#include "fun.h"

int main(int argc, char * argv[])
{
	if(argc!=2)
		exit(1);

	FILE * fp=fopen(argv[1],"r");

	Node * root=NULL;

	int tmp;
	while(fscanf(fp,"%d",&tmp)!=EOF)
	{
		root=insert(root,tmp);
	}
	inOrder(root);
	printf("\n");

	root=delete(root,5);
	inOrder(root);
	printf("\n");
}
