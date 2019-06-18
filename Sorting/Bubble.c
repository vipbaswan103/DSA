#include "sorts.h"

void sort(int arr[], int size)
{
	int tmp;
	int flag=0;
	for(int i=0;i<size-1;i++)
	{
	//	flag=0;
		for(int j=size-1;j>=i+1;j--)
		{
			if(arr[j]<arr[j-1])
			{
				tmp=arr[j-1];
				arr[j-1]=arr[j];
				arr[j]=tmp;
				flag=1;
			}
		}
	//	if(flag==0)
	//		break;
	}
}
