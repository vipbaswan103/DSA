#include "fun.h"
#define max 5
typedef int Ele;
int main(int argc,char * argv[])
{
	if(argc!=2)
		exit(0);
	FILE * fp=fopen(argv[1],"r");
	if(fp==NULL)
		exit(0);

	Ele * arr=(Ele *)malloc(sizeof(Ele)*max);
	int i=0;
	Ele tmp;
	int m=max;
	while(fscanf(fp,"%d",&tmp)!=EOF)
	{
		if(i>=5)
		{
			arr=(Ele *)realloc(arr,sizeof(Ele)*m*2);
			m=m*2;
		}
		arr[i]=tmp;
		i++;
	}
	int size=i;
	print(arr,size);
	//bubbleSort(arr,size);
	//selectionSort(arr,size);
	//insertionSortIter(arr,size);
	//insertionSortRecur(arr,size);
	//mergeSortRecur(arr,0,size-1);
	//mergeSort(arr,0,size-1);
	//quickSortRecur(arr,0,size-1);
	//quickSortIter(arr,0,size-1);
	//countingSort(arr,1,10,size);
	//radixSort(arr,size,2);
	//bucketSort(arr,size);
	heapSort(arr,size);
	print(arr,size);
}
