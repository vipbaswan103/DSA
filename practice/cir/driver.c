#include "cirl.h"

int main(int argc, char * argv[])
{
	if(argc!=2)
	{
		printf("ERROR !!!\n");
		exit(1);
	}
	
	FILE * fp=fopen(argv[1],"r");

	circlist * head=(circlist *)malloc(sizeof(circlist));
	head->count=0;
	head->first=NULL;

	int tmp;
	while(fscanf(fp,"%d",&tmp)!=EOF)
	{
		insertEnd(head,tmp);
	}
	print(head);
	
	printf("After deletiom:\n");
	deleteEnd(head);

	print(head);
	fclose(fp);
	return 0;
}
