#include <stdio.h>
#include<stdlib.h>
#include "linkedlist.h"

int main(int argc, char *argv[])
{
	FILE *fp=fopen(argv[1],"r");
	int temp;
	struct linkedlist * head = (struct linkedlist*) malloc(sizeof(struct linkedlist));
	head->count=0;
	head->first=NULL;
	while(fscanf(fp,"%d",&temp)!=EOF)
	{
		insertFirst(head,temp);
	}	
	fclose(fp);
	printList(head);
	struct node *ptr;
	/*ptr=deleteFirst(head);
	printf("\nDeleted ele: %d\nFinal list is:\n",ptr->ele);
	printList(head);*/
	
	//fp=fopen(argv[2],"w");
	
	int x,s;
	/*printf("Enter element to search :");
	scanf("%d",&s);
	printf("\n");
	x=search(head,s);
	printf("Search Status: %d\n",x);*/

	/*printf("Enter position to insert an element , pos (pos>=0 and pos<=count):");
	scanf("%d",&s);
	printf("\nEnter the element :");
	scanf("%d",&x);
	printf("\n");
	insertMid(head,x,s);
	printf("Final List:\n");
	printList(head);*/

	printf("\nEnter the element to delete :");
	scanf("%d",&x);
	printf("\n");
	deleteEle(head,x);
	printf("Final List:\n");
	printList(head);
	printf("\nList in sorted order is:\n");
	printSort(head);	
	return 0;
}
