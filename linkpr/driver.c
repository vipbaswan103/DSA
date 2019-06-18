#include "fun.h"

int main(int argc, char * argv[])
{
	if(argc!=2)
		exit(1);
	
	FILE * fp=fopen(argv[1],"r");
	
	head * h=(head *)malloc(sizeof(head));
	h->next=NULL;

	int tmp;
	int i=0;
	while(fscanf(fp,"%d",&tmp)!=EOF)
	{
		insertNth(h,i,tmp);
		i++;
	}
	printf("\nPrinting List...\n");
	printList(h);
	insertSort(h);
	
	printf("\nPrinting List...\n");
	printList(h);
	
	removeDuplicates(h);
	printf("\nPrinting List...\n");
	printList(h);

	/*head * h2=(head *)malloc(sizeof(head));
	h2->next=NULL;

	i=0;
	fp=fopen(argv[2],"r");
	while(fscanf(fp,"%d",&tmp)!=EOF)
	{
		insertNth(h2,i,tmp);
		i++;
	}*/
	//insertSort(h2);
	//printList(h2);

	/*moveNode(h,h2);
	moveNode(h,h2);
	printList(h);
	printList(h2);*/
	
	/*head * a=(head *)malloc(sizeof(head));
	head * b=(head *)malloc(sizeof(head));

	alternatingSplit(h,a,b);
	printf("a :\t");
	printList(a);

	printf("\nb:");
	printList(b);

	printList(h);*/

	/*head * front=malloc(sizeof(head));
	head * back=malloc(sizeof(head));
	frontBackSplit(h,front,back);

	printList(front);
	printList(back);*/
	return 0;		
}
