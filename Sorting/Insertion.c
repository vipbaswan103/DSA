#include "sorts.h"
void sort(int arr[], int size)
{
	int i=0,key;
	for(int j=1;j<size;j++)
	{
		i=j-1;
		key=arr[j];
		while(i>=0 && arr[i]>key)
		{
			arr[i+1]=arr[i];
			i-=1;
		}
		arr[i+1]=key;
	}
}
