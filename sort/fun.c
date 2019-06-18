#include "fun.h"

void print(int * arr, int size)
{
	for(int i=0;i<size;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
void bubbleSort(int arr[],int size)
{
	int tmp;
	int flag;
	for(int i=0;i<size;i++)
	{
		flag=0;
		for(int j=size-1;j>=(i+1);j--)	//start from the last element and go till the element just after ith element
		{
			if(arr[j]<arr[j-1])	//it means you have to bring the ligter arr[j] element to the top
			{
				flag=1;
				tmp=arr[j];
				arr[j]=arr[j-1];
				arr[j-1]=tmp;
			}
		}
		if(flag==0)	//If array doesn't change in the single pass, return it
			return;
	}
}

void selectionSort(int arr[], int size)
{
	int tmp;
	for(int i=0;i<size-1;i++)
	{
		for(int j=i+1;j<size;j++)
		{
			if(arr[i]>arr[j])		//we are comparing each element arr[i] with all other elements arr[j]
			{
				tmp=arr[i];
				arr[i]=arr[j];
				arr[j]=tmp;
			}
		}
	}
}
void insertInOrder(int arr[], int key, int size)
{
	int i=size-1;
	while(i>=0 && arr[i]>key)
	{
		arr[i+1]=arr[i];
		i-=1;
	}
	arr[i+1]=key;
}

void insertionSortIter(int arr[],int size)
{
	for(int i=1;i<size;i++)
	{
		int size=i;		//since a single element is always sorted
		int key=arr[i];		
		insertInOrder(arr,key,size);	//insert key=arr[i] in correct place in the array arr[0...size-1]
	}
}

void insertionSortRecur(int arr[], int size)
{
	if(size<=1)
		return;
	insertionSortRecur(arr,size-1);		//keep on shortening the array until you reach a single element array, which is by default sorted
	insertInOrder(arr,arr[size-1],size-1);
}

void sortedMerge(int tot[], int arr1[], int arr2[], int s1, int s2)
{
	int s=s1+s2;
	int i=0,j=0,k=0;

	while(i<s1 && j<s2)
	{
		if(arr1[i]<=arr2[j])
		{
			tot[k]=arr1[i];
			i+=1;
		}
		else
		{
			tot[k]=arr2[j];
			j++;
		}
		k++;
	}

	/* Now either arr1[] has reached an end or arr2[] has reached an end*/

	for(int m=i;m<s1;m++)	// if arr2[] has been successfuly placed in tot[], place rest of arr1[] into tot[]
	{
		tot[k]=arr1[m];
		k++;
	}
	for(int n=j;n<s2;n++)	// if arr1[] has been successfuly places in tot[], place rest of arr2[] into tot[]
	{
		tot[k]=arr2[n];
		k++;
	}
}

void mergeSortRecur(int arr[], int p, int r)
{
	if(p>=r)	/* if arr is shortened to a single element, return as it is trivially sorted*/
		return;
	int q=(p+r)/2;	
	mergeSortRecur(arr,p,q);
	mergeSortRecur(arr,q+1,r);
	
	/* Merge the arr[p..q] and arr[q+1...r] into arr[p...r] in sorted order*/
	int s1=q-p+1, s2=r-q, s3=r-p+1;
	int arr1[q-p+1], arr2[r-q], arr3[r-p+1];

	int k=0;
	for(int i=p;i<=q;i++)
	{
		arr1[k]=arr[i];
		k++;
	}
	k=0;
	for(int i=q+1;i<=r;i++)
	{
		arr2[k]=arr[i];
		k++;
	}
	k=0;
	sortedMerge(arr3,arr1,arr2,s1,s2);

	for(int i=p;i<=r;i++)
	{
		arr[i]=arr3[k];
		k++;
	}
}

/*void mergeSortIter(int arr[], int p, int r)
{	
	int size=(r-p+1),m=1,flag=1;
	for(int i=(size+1)/2;i>=1;i=(i+1)/2)
	{
		int add=pow(2,m)-1;
		int s=0;
		for(int j=0;j<i;j++)
		{

			int p,q,r;
			p=s;
			if((s+add)>size)
			{
				r=size-1;
				q=p+pow(2,m-1)-1;
				printf("%d\t%d\t%d\t%d\n",p,q,r,m);
			}
			else
			{
				r=p+add;
				q=(p+r)/2;
			}
			int s1=(q-p+1), s2=(r-q), s3=(r-p+1);
			int arr1[s1], arr2[s2], arr3[s3];

			int k=0;
			for(int i=p;i<=q;i++)
			{
				arr1[k]=arr[i];
				k++;
			}
			k=0;
			for(int i=q+1;i<=r;i++)
			{
				arr2[k]=arr[i];
				k++;
			}
			sortedMerge(arr3,arr1,arr2,s1,s2);
	
			k=0;
			for(int i=p;i<=r;i++)
			{
				arr[i]=arr3[k];
				k++;
			}
				//printf("%d\t%d\t%d\n",p,q,r);
				print(arr1,s1);
				print(arr2,s2);
				print(arr,size);
			s=s+add+1;
		}
		m++;
	}
	printf("\n\n");
}*/

int min(int x, int y)
{
	return x<y ? x :y;
}
void mergeSortIter(int arr[], int x, int y)
{
	int size=(y-x+1);
	int curr=1;
	int p=0;

	/* Use a BOTTOM UP approach. 
	 * We know that a single element is already sorted, we start from 2 element long array and build up a complete sorted array*/
	
	// curr gives the size of the arrays to be sorted, curr=3 means we have to merge 2 subarrays of size 3 each */
	for(curr=1;curr<=size-1;curr=curr*2)	/* max curr can be size/2*/	
	{
		for(p=0;p<size-1;p+=2*(curr))	/* p gives the left index of the array*/
		{
			int q=p+curr-1;		/* we calculate the middle index*/
			int r=min(p+(2*curr)-1,size-1);	/* we calculate the right index*/

			/* Now
			 * we have p,q and r
			 * simple merge arr[p..q] and arr[q+1...r] into arr[p..r]*/
					
			int s1=q-p+1, s2=r-q, s3=r-p+1;	
			int arr1[q-p+1], arr2[r-q], arr3[r-p+1];

			int k=0;
			for(int i=p;i<=q;i++)
			{
				arr1[k]=arr[i];
				k++;
			}
			k=0;
			for(int i=q+1;i<=r;i++)
			{
				arr2[k]=arr[i];
				k++;
			}
			k=0;
			sortedMerge(arr3,arr1,arr2,s1,s2);

			for(int i=p;i<=r;i++)
			{
				arr[i]=arr3[k];
				k++;
			}
		}
	}
}

/*void mergeSort(int arr[], int p, int r)
{
	int stack1[(r-p+1)];
	int top1=0;
	int stack2[(r-p+1)];
	int top2=0;
	int size=r-p+1;
	stack1[top1++]=p;
	stack1[top1++]=r;
	while(p<r)
	{	
		int q=(p+r)/2;
		stack1[top1++]=p;
		stack1[top1++]=q;
		r=q;	
	}
	top1--;
	top1--;
	int q;
	for(int i=top1-1;i>=0;i--)
	{
		printf("%d\t",stack1[i]);
	}
	printf("\n");
	while(top1!=0)
	{
		r=stack1[--top1];
		p=stack1[--top1];
		int flag=0;
		stack2[top2++]=p;
		stack2[top2++]=r;
		while(p<r)
		{
			q=(p+r)/2;
			printf("%d\t%d\t%d\n",p,q,r);
			if(p<q)
			{
				flag=1;
				stack1[top1++]=p;
				stack1[top1++]=q;
				break;	
			}
			if((q+1)<r)
			{
				stack2[top2++]=q+1;
				stack2[top2++]=r;
				p=(q+1);
			}
			else
				break;
		}
		if(flag==1)
			continue;
		while(top2!=0)
		{
			r=stack2[--top2];
			p=stack2[--top2];
			int q=(p+r)/2;

			int s1=q-p+1, s2=r-q, s3=r-p+1;
			int arr1[q-p+1], arr2[r-q], arr3[r-p+1];

			int k=0;
			for(int i=p;i<=q;i++)
			{
				arr1[k]=arr[i];
				k++;
			}
			k=0;
			for(int i=q+1;i<=r;i++)
			{
				arr2[k]=arr[i];
				k++;
			}
			k=0;
			sortedMerge(arr3,arr1,arr2,s1,s2);

			for(int i=p;i<=r;i++)
			{
				arr[i]=arr3[k];
				k++;
			}
		}
		print(arr,size);
	}
}*/

void mergeSort(int arr[],int p, int r)
{
	int size=(r-p+1);
	int stack[size*10];
	int top=0;
	stack[top++]=p;
	stack[top++]=r;
	int q;
	while(top!=0)
	{
		int x=top;
		r=stack[--x];
		p=stack[--x];
		q=(p+r)/2;

		if(p<q)
		{
			stack[top++]=p;
			stack[top++]=q;
		}
		if((q+1)<r)
		{
				stack[top++]=q+1;
				stack[top++]=r;
		}
		if(p>=q && (q+1)>=r) 
		{
			for(int i=0;i<=2;i++)
			{
				p=stack[--top];
				r=stack[--top];
				q=(p+r)/2;
				int s1=q-p+1, s2=r-q, s3=r-p+1;
				int arr1[q-p+1], arr2[r-q], arr3[r-p+1];
		
				int k=0;
				for(int i=p;i<=q;i++)
				{
					arr1[k]=arr[i];
					k++;
				}
				k=0;
				for(int i=q+1;i<=r;i++)
				{
					arr2[k]=arr[i];
					k++;
				}
				k=0;
				sortedMerge(arr3,arr1,arr2,s1,s2);

				for(int i=p;i<=r;i++)
				{
					arr[i]=arr3[k];
					k++;
				}
			}
		}
		for(int i=top-1;i>=0;i--)
		{
			printf("%d\t",stack[i]);
		}
		printf("\n");
	}	
}
int partition(int arr[], int lo, int hi)
{
	int i=lo-1;
	int pivot=arr[hi];
	int tmp;
	for(int j=lo;j<=hi-1;j++)
	{
		if(arr[j]<=pivot)
		{
			i++;
			tmp=arr[i];
			arr[i]=arr[j];
			arr[j]=tmp;	
		}
	}
	tmp=arr[i+1];
	arr[i+1]=arr[hi];
	arr[hi]=tmp;
	return i+1;
}

void quickSortRecur(int arr[], int lo, int hi)
{
	if(lo>=hi)
		return;
	int q=partition(arr,lo,hi);
	quickSortRecur(arr,lo,q-1);
	quickSortRecur(arr,q+1,hi);
}


void quickSortIter(int arr[], int lo, int hi)
{
	int stack[hi-lo+1];
	int top=-1;
	
	stack[++top]=lo;
	stack[++top]=hi;
	
	int piv;
	while(top!=-1)		//until stack is not empty*/
	{
		hi=stack[top--];
		lo=stack[top--];
		piv=partition(arr,lo,hi);

		if(lo<piv-1)
		{
			stack[++top]=lo;
			stack[++top]=piv-1;
		}	
		if(piv+1<hi)
		{
			stack[++top]=piv+1;
			stack[++top]=hi;
		}
	}
}
/*Non comparison Sorting Algorithms*/

void countingSort(int arr[],int l, int h,int n)
{
	int c[h+1];
	for(int i=0;i<=h;i++)
	{
		c[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		c[arr[i]]++;
	}
	for(int i=l;i<=h;i++)
	{
		c[i]=c[i]+c[i-1];
	}
	int x=c[h];
	int b[x+1];
	print(c,h+1);
	for(int i=0;i<=x;i++)
	{
		b[i]=0;
	}
	int s=0;
	for(int i=n-1;i>=0;i--)
	{
		//if(c[arr[i]]!=-1)
		//{
			b[c[arr[i]]]=arr[i];
			c[arr[i]]=-1;
			s++;
		//}
	}
	print(b,x+1);
	/*int w[s];
	int k=0;
	for(int i=0;i<=x;i++)
	{
		if(b[i]!=-1)
		{
			w[k]=b[i];
			k++;
		}
	}
	print(w,s);*/
}

void stableSort(int digit[],int arr[],int k,int n)
{
	int c[k+1];
	for(int i=0;i<=k;i++)
	{
		c[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		c[digit[i]]++;
	}

	for(int i=1;i<=k;i++)
	{
		c[i]=c[i]+c[i-1];
	}
	int x=c[k]+1;
	int b[x];
	int w[x];
	for(int i=0;i<x;i++)
	{
		b[i]=-1;
		w[i]=-1;
	}
	for(int i=n-1;i>=0;i--)
	{
		b[c[digit[i]]]=digit[i];
		w[c[digit[i]]]=arr[i];
		c[digit[i]]--;
	}

	int s=0;
	for(int i=0;i<x;i++)
	{
		if(b[i]!=-1)
		{
			digit[s]=b[i];
			arr[s]=w[i];
			s++;
		}
	}
}
void radixSort(int arr[], int n, int d)
{
	int digit[n],div;
	for(int i=1;i<=d;i++)
	{
		int x=pow(10,i);
		int y=pow(10,i-1);
		for(int j=0;j<n;j++)
		{
			digit[j]=((arr[j]%x)-(arr[j]%y));
			digit[j]=digit[j]/y;
		}
		stableSort(digit,arr,9,n);
	}
}

struct Node insert(struct Node head, double ele)
{
	node newNode=(node)malloc(sizeof(struct Node));

	if(head.next==NULL)
	{
		newNode->next==NULL;
		newNode->ele=ele;
		head.next=newNode;
		head.ele++;
		return head;
	}
	
	newNode->ele=ele;
	newNode->next=NULL;
	node tmp=head.next;
	while(tmp->next!=NULL)
	{
		tmp=tmp->next;
	}	
	tmp->next=newNode;
	head.ele++;
	return head;
}
void printBucket(struct Node head)
{
	node tmp=(head.next);
	while(tmp!=NULL)
	{
		printf("%lf\t",tmp->ele);
		tmp=tmp->next;
	}
	printf("\n");
}
void bucketSort(double arr[], int n)
{
	struct Node buckets[n];

	for(int i=0;i<n;i++)
	{
		buckets[i].ele=0;
		buckets[i].next=NULL;
	}

	for(int i=0;i<n;i++)
	{
		int x=(floor(n*arr[i]));
		buckets[x]=insert(buckets[x],arr[i]);
	}

	for(int i=0;i<n;i++)
	{
		if(buckets[i].next!=NULL)
		{
			ListSort(&buckets[i]);
			printBucket(buckets[i]);
		}
	}
	int k=0;
	for(int i=0;i<n;i++)
	{
		node tmp=buckets[i].next;
		while(tmp!=NULL)
		{
			arr[k]=tmp->ele;
			k++;
			tmp=tmp->next;
		}
	}	
}

void inOrder(node * head, node newNode)
{
	node tmp=*head;
	if(*head==NULL)
	{
		newNode->next=NULL;
		*head=newNode;
		return;
	}
	if(newNode->ele < tmp->ele)
	{
		newNode->next=tmp;
		*head=newNode;
		return;
	}
	while(tmp->next!=NULL)
	{
		if(tmp->ele <= newNode->ele && newNode->ele < tmp->next->ele)
		{
			node front = tmp->next;
			tmp->next=newNode;
			newNode->next=front;
			return;			
		}
		tmp=tmp->next;
	}
	tmp->next=newNode;
	newNode->next=NULL;
	return;
}
void ListSort(node head)
{
	node sorted=NULL;

	node tmp=(head)->next;
	while(tmp!=NULL)
	{
		node save=tmp->next;
		inOrder(&sorted,tmp);
		tmp=save;
	}
	(head)->next=sorted;
}

int left(int arr[], int i)
{
	return (2*i)+1;
}
int right(int arr[], int i)
{
	return 2*(i+1);
}
void maxHeapify(int arr[], int i, int n)
{
	int l=left(arr,i);
	int r=right(arr,i);
	int largest;
	//printf("i %d\tLeft %d\tRight %d\n",i,arr[l],arr[r]);
	if(l<=n-1 && arr[l] > arr[i])
		largest=l;	
	else
		largest=i;

	if(r<=n-1 && arr[r]>arr[largest])
		largest=r;
	
	if(largest!=i)
	{
		int tmp=arr[largest];
		arr[largest]=arr[i];
		arr[i]=tmp;
		maxHeapify(arr,largest,n);
	}
}

void buildMaxHeap(int arr[], int n)
{
	int i=(floor(n/2))-1;
	for(int j=i;j>=0;j--)
	{
		maxHeapify(arr,j,n);
	}	
}

void heapSort(int arr[], int n)
{
	buildMaxHeap(arr,n);
	//print(arr,n);
	for(int i=n-1;i>=1;i--)
	{
		int tmp=arr[0];
		arr[0]=arr[i];
		arr[i]=tmp;
		maxHeapify(arr,0,i);
		//print(arr,n);
	}
}

void twayMergeSort(int arr[], int p, int r)
{
	if(p<r)
	{
		int q1=p+(p-r)/3;
		int q2=p+(2*((p-r)/3))+1;

		twayMergeSort(arr,p,q1);
		twayMergeSort(arr,q1+1,q2);
		twayMergeSort(arr,q2+1,r);
	}
}


