#include "treearr.h"
#include <math.h>
#include <stdlib.h>

int size=0;
void insert(int arr[], int ele)
{
	if(size==0)
	{
		arr[size]=ele;
		size++;
		return;
	}
	arr[size]=ele;
	size+=1;
}

int delete(int arr[])
{
	int tmp=arr[size-1];
	size-=1;
	return tmp;
}

void print(int arr[])
{
	int height=floor( ( log(size)/log(2) ) );

	for(int i=0;i<size;i++)
		printf("%d  ",arr[i]);
	
	printf("\nHeight of the tree is : %d\n",height);

	for(int i=0;i<size;i++)
	{
		if(((2*i)+1)<size || 2*(i+1)<size)
		{
			printf("Node : %d ",arr[i]);
		
			if((2*i + 1)  <size)
		       		printf("Left Child : %d", arr[(2*i)+1]);
			if((2*(i+1)) < size)
				printf("Right Child : %d", arr[2*(i+1)]);
			printf("\n");
		}	
	}
}	
