#include "sorts.h"

void merge(int arr[], int p, int q, int r)
{
	int n1=q-p+1;
	int n2=r-q;

	int left[n1], right[n2];

	for(int i=0;i<n1;i++)
		left[i]=arr[p+i];
	for(int j=0;j<n2;j++)
		right[j]=arr[q+j+1];
	//left[n1]=2147483647;
	//right[n2]=2147483647;

	int j=0,k=p,i=0;
	while(i<n1 && j<n2)
	{
		if(left[i]<=right[j])
		{
			arr[k]=left[i];
			i++;
		}
		else
		{
			arr[k]=right[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		arr[k]=left[i];
		k++;
		i++;
	}
	while(j<n2)
	{
		arr[k]=right[j];
		k++;
		j++;
	}
}	

void sort(int arr[], int p , int r)
{
	if(p<r)
	{
		int q=floor((p+r)/2);
		sort(arr,p,q);
		sort(arr,q+1,r);
		merge(arr,p,q,r);
	}
}
