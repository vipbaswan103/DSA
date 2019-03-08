#include "que.h"

int main(int argc, char * argv[])
{
	if(argc!=2)
		exit(1);

	FILE * fp=fopen(argv[1],"r");
	
	Queue * que=newQ();
	int tmp;
	while(fscanf(fp,"%d",&tmp)!=EOF)
	{
		que=addQ(que,tmp);
	}
	print(que);

	printf("Deleting ...");
	que=delQ(que);
	
	printf("\n");
	print(que);
	Node * ptr=front(que);
	printf("\nFront: %d",ptr->ele);
	printf("\nLenght: %d",lengthQ(que));	
}
