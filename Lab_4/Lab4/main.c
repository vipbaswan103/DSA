#include "Exer3.h"

int main()
{
	node * list=createList(5);
	print(list);

	int ele,res;
	scanf("%d",&ele);
	list=createCycle(list,ele);
	
	res=testCycle(list);
	printf("Result: %d\n",res);
	
	//printf("Length of the loop is %d\n",findLengthLoop(list));
	//printf("\nCreating Circular...\n");
	//list=createCircular(list);
	//printCircular(list);
	printf("\nHeap memory used:  %d\n",totSpace);
	return 0;	
}
