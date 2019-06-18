#include "fun.h"

int main(int argc, char * argv[])
{
	if(argc!=2)
		exit(0);
	
	FILE * fp=fopen(argv[1],"r");
	Head list;
	list=createList(list,fp);
	printList(list->next);

	Node * first=&(list->next);
	insertionSort(first);
	printList(list->next);

	fclose(fp);
}
