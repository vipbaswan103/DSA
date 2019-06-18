#include "dcirlist.h"
#include "compare.h"
int main(int argc, char * argv[])
{
	if(argc!=2)
	{
		printf("Wrong no. of arguments\n");
		exit(1);
	}

	FILE * fp=fopen(argv[1],"r");

	node * sentinel=(node *)malloc(sizeof(node));

	sentinel->ele=0;
	sentinel->next=sentinel;
	sentinel->prev=sentinel;

	int tmp;
	while(fscanf(fp,"%d",&tmp)!=EOF)
	{
		insertNode(sentinel,tmp);
	}

	printForward(sentinel);
	printBackward(sentinel);

	printf("Enter the element to delete :\t");
	scanf("%d",&tmp);

	node * ptr=deleteNode(sentinel, tmp);

	if(ptr!=NULL)
		printf("Prev ele :%d\t Next ele:%d\n",ptr->prev->ele, ptr->next->ele);
	printf("Final list\n");
	printForward(sentinel);
	printBackward(sentinel);	
	return 0;
}
