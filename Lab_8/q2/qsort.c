#include "qsort.h"

void printArray(int* studArray, int arrSize)
{
	// printing the array
	int i = 0;
	for(i=0;i<arrSize;i++)
	{
		printf("Arr[%d] is %d\n", i, studArray[i]);
	}
}

int * readData(char * filename)
{
	FILE * fp=fopen(filename,"r");
	fscanf(fp,"%d",&size);
	
	int * arr=(int *)malloc(sizeof(int)*size);
	
	int tmp;
	int i=0;
	while(fscanf(fp,"%*s %d",&tmp)!=EOF)
	{
		arr[i]=tmp;
		i++;
	}
	return arr;
}

void print(int arr[], int x)
{
	for(int i=0;i<x;i++)
		printf("%d\t",arr[i]);
	printf("\n");
}
KeyStruct extractKeys(int * Ls, int lsSize, int loKey, int hiKey)
{
	int c[hiKey+1];	
	for(int i=0;i<=hiKey;i++)
	{
		c[i]=0;
	}

	for(int i=0;i<lsSize;i++)
	{
		c[Ls[i]]+=1;
	}	
	for(int i=loKey+1;i<=hiKey;i++)
	{
		c[i]=c[i]+c[i-1];
	}

	int b[lsSize],z=0;
	for(int i=0;i<=lsSize-1;i++)
	{
		b[i]=-1;
	}

	for(int i=lsSize-1;i>=0;i--)
	{
		if(c[Ls[i]]!=-1)
		{
			b[c[Ls[i]]-1]=Ls[i];
			c[Ls[i]]=-1;
			z++;
		}
	}

	KeyStruct arr=(KeyStruct)malloc(sizeof(struct keyStruct));
	arr->Keys=(int *)malloc(sizeof(int)*z);
	arr->keysSize=z;
	int s=0;

	for(int i=0;i<=lsSize-1;i++)
	{
		if(b[i]!=-1)
		{
			(arr->Keys)[s]=b[i];
			s++;
		}
	}
	return arr;
}
int part2Loc(int * Ls, int lo, int hi, int piv)
{
	int i=lo-1;
	int j=lo;

	while(j<=hi)
	{
		if(Ls[j]<=piv)
		{
			i++;
			int tmp=Ls[j];
			Ls[j]=Ls[i];
			Ls[i]=tmp;
		}
		j++;
	}
	return i;
}

void quickSortKnownKeyRange(int * Ls, int size, int loKey, int hiKey)
{
	KeyStruct ptr=extractKeys(Ls,size,loKey,hiKey);
	int kSize=ptr->keysSize;
	int stack[size];
	int top=0;
	
	stack[top++]=0;
	stack[top++]=size-1;

	int p,q,r;
	int z=0;
	while(z!=kSize)
	{
		r=stack[--top];
		p=stack[--top];
		q=part2Loc(Ls,p,r,(ptr->Keys)[z]);
		
		if(p<q)
		{
			stack[top++]=p;
			stack[top++]=q;
		}
		if(q<r)
		{
			stack[top++]=q+1;
			stack[top++]=r;
		}
		z++;
	}
}
