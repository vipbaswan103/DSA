#include "fun.h"

int main(int argc, char * argv[])
{
	if(argc!=2)
		exit(1);
	
	FILE * fp=fopen(argv[1],"r");
	
	int tmp;
	node * head=NULL;
	while(fscanf(fp,"%d",&tmp)!=EOF)
	{
		insertNode(&head,tmp);
	}	
	printList(head);


	node * start=head;
	node * end=head;
	while(end->next!=NULL)
	{
		end=end->next;
	}
//	printf("\n%d\n",end->ele);
//	node * q=partitionList(&head,start,end);
//	printf("\n%d\n",q->ele);
	quickSort(&head,&start,&end);
	printList(head);	
	return 0;
}
