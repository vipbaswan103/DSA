#include "list.h"

int main(int argc, char * argv[])
{
	if(argc!=2)
	{
		printf("ERROR: Wrong number of arguments\n");
		exit(0);
	}
	
	FILE * fp=fopen(argv[1],"r");
	
	node * head=NULL;
	int tmp;
	while(fscanf(fp,"%d\n",&tmp)!=EOF)
	{
		head=insert(head,tmp);
	}
	print(head);

	//printf("hello");
	node * trav=head;
	while(trav->next!=NULL)
	{
		trav=trav->next;
	}
	//printf("hi");
	mergeSort(head,head,trav);
	//insertionSort(&head);
	print(head);
}
