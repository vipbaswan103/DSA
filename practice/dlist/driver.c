#include "dlist.h"

int main(int argc, char *argv[])
{
	if(argc!=2)
	{
		printf("Error!! Wrong number of command line arguments!");
		exit(1);
	}

	FILE * fp=fopen(argv[1],"r");

	int tmp;

	dlist * head = malloc(sizeof(dlist));
	head->count=0;
	head->first=NULL;

	int arr[5];
	while(fscanf(fp,"%d",&tmp)!=EOF)
	{
		insertEnd(head,tmp);	
	}
	printStr(head);
	printRev(head);

	printf("List after deletion (in forward traversal):\n");
	deleteEnd(head);
	printStr(head);

	printf("Enter ele to search:\n");
	int x;
	scanf("%d",&x);
	printf("\n");

	tmp=search(head,x);

	if(tmp==-1)
		printf("Not found\n");
	else
	{
		if(tmp!=0)
		{
			printf("Found at: %d\n",tmp);
		}
	}
	fclose(fp);
	return 0;
}
