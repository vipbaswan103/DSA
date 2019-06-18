#include<stdio.h>

int main()
{
	int i,j,num;
	
	printf("Enter the number: ");
	scanf("%d",&num);

	j=1;
	for(i=1;i<=num;i++)
		j=j*i;

	printf("\nThe factorial of %d is %d\n",num,j);
}
