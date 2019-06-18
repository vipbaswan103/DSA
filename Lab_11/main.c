#include "fun.h"

int main(int argc, char * argv[])
{
	if(argc!=2)
		exit(1);

	FILE * fp=fopen(argv[1],"r");
	Node * root;
	root=createTree();
	readData(fp,root);
	
	printDFS(root);
	printf("\n");

	lookUp(root,"goo.co.in");	
	return 0;
}
