#include "quick.h"
#include <sys/time.h>
#include <time.h>

struct timeval t1,t2,t3,t4;
double et1=0,et2=0;

void quickSort(emp * arr, int p, int r)
{
	if(p<r)
	{
		int q=partition(arr,p,r);
		quickSort(arr,p,q-1);
		quickSort(arr,q+1,r);
	}
}

void quickSortIter(emp * arr, int s,int p, int r)
{
	node * top=NULL;
	push(&top,p);
	push(&top,r);
	node * get;
	int st,end;
	int piv;
	
	if(s<=1)
		s=1;

	while(isEmpty(top)==0)
	{
		get=pop(&top);
		end=get->p;
		get=pop(&top);
		st=get->p;
		piv=partition(arr,st,end);
		if(st+s<piv-1)
		{
			
			push(&top,st);
			push(&top,piv-1);
		}
		if(piv+s+1<end)
		{
			
			push(&top,piv+1);
			push(&top,end);
		}
	}
}

void insertionSort(emp * arr,int size)
{
	int i;
	for(int j=1;j<size;j++)
	{
		emp piv=arr[j];
		i=j-1;
		while(i>=0 && arr[i].empid>piv.empid)
		{
			arr[i+1].empid=arr[i].empid;
			strcpy(arr[i+1].name,arr[i].name);
			i=i-1;
		}
		arr[i+1].empid=piv.empid;
		strcpy(arr[i+1].name,piv.name);
	}
}

void sort(emp * arr,int s, int p,int r)
{	
	node * top=NULL;
	push(&top,p);
	push(&top,r);
	node * get;
	int st,end;
	int piv;
	
	if(s<=1)
		s=1;

	while(isEmpty(top)==0)
	{
		get=pop(&top);
		end=get->p;
		get=pop(&top);
		st=get->p;
		piv=partition(arr,st,end);
		if(st+s<piv)
		{
			push(&top,st);
			push(&top,piv-1);
		}
		else
		insertionSort(arr+st,(end-st)+1);
		if(piv+s<end)
		{
			
			push(&top,piv+1);
			push(&top,end);
		}
		else
		insertionSort(arr+st,(end-st)+1);
			
	}
}
void swap(emp * e1, emp* e2)
{
	char tname[11];
	int tid;
	
	strcpy(tname,e1->name);
	tid=e1->empid;
	
	strcpy(e1->name,e2->name);
	e1->empid=e2->empid;
	
	strcpy(e2->name, tname);
	e2->empid=tid;
}

int partition(emp * arr, int p, int r)
{
	int i=p-1,j;
	emp piv=arr[r];
	for(j=p;j<=r-1;j++)
	{
		if(arr[j].empid <= piv.empid)
		{
			i++;
			swap(&arr[i],&arr[j]);
		        	
		}
	}
	swap(&arr[i+1],&arr[r]);
		return i+1;
}

void testRun(emp * arr, int size)
{
	emp * tmp1=(emp *)malloc(sizeof(emp)*size);
	emp * tmp2=(emp *)malloc(sizeof(emp)*size);
	for(int i=0;i<size;i++)
	{
		tmp1[i]=arr[i];
		tmp2[i]=arr[i];
	}

	gettimeofday(&t1,NULL);
	quickSortIter(tmp1,1,0,size-1);
	gettimeofday(&t2,NULL);
	
	et1=(t2.tv_sec-t1.tv_sec)*1000.0;
	et1+=(t2.tv_usec-t1.tv_usec)/1000.0;
	
	
	gettimeofday(&t3,NULL);
	insertionSort(tmp2,size);
	gettimeofday(&t4,NULL);

	et2=(t4.tv_sec-t3.tv_sec)*1000.0;
	et2+=(t4.tv_usec-t3.tv_usec)/1000.0;
}

int estimateCutoff(emp * arr,int size)
{
	double eps=0.00001;
	
	int min=1,mid;
	int max=size;
	
	testRun(arr,min);
	testRun(arr,max);
	double t=100.0;
	while(t>eps)
	{
		mid=(min+max)/2;
		testRun(arr,mid);
		printf("%f\t%f\t%d\n",et1,et2,mid);
		t=et2-et1;
		if(et1<et2)
			max=mid;	
		else
			min=mid;
	}
	return mid;
}
void print(emp * arr, int size)
{
	for(int i=0;i<size;i++)
	{
		printf("%s %d\n",arr[i].name,arr[i].empid);
	}
}
