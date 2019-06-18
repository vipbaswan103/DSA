#include "treearr.h"
#include <stdlib.h>
int main(int argc, char * argv[])
{
	if(argc!=2)
	{
		printf("Error!! Wrong no of arguments\n");
		exit(1);
	}

	FILE * fp=fopen(argv[1],"r");

	int tmp;
	fscanf(fp,"%d",&tmp);
	int tree[tmp];

	while(fscanf(fp,"%d",&tmp)!=EOF)
	{
		insert(tree,tmp);
	}

	print(tree);
	fclose(fp);
}
