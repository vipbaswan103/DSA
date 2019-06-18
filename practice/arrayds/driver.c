#include "stack.h"

int main(int argc, char * argv[])
{
	if(argc!=2)
	{
		printf("ERROR!! Wrong number of arguments. Exiting...");
		exit(1);
	}

	FILE *fp=fopen(argv[1],"r");

	int stack[5], tmp;
	int i=1;
	while(fscanf(fp,"%d",&tmp)!=EOF)
	{
		//printf("In : %d  ",i);
		i++;
		push(stack,tmp);
	}

	printf("Stack is :\n");
	print(stack);

	char ch;
	printf("Do you want to pop (y/n) ?\t");
	scanf("%c",&ch);
	if(ch=='y' || ch=='Y')
	{
		int x=pop(stack);
		printf("\nNode deleted had the content: %d",x);
		printf("\nStack is :\n");
		print(stack);
	}
	else
	{
		if(ch=='n' || ch=='N')
		{}
		else
			printf("\nWrong choice!! Only (y,n) allowed.\n");
		
	}
	fclose(fp);
	return 0;
}
