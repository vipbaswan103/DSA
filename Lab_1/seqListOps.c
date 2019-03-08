/***********file:   Ops.c *********/
#include <stdio.h>

#include "storage.h"
#include "compare.h"
int nextfreeloc = 0;
Store st;

SeqList createlist()
{
 SeqList sl;
 sl.head = nextfreeloc++;
 sl.size = 0;
 st[sl.head].next = -1;
 return (sl);
}

void printJob (Job j)
{
	printf ("JOB ID = %d, Priority = %d, Execution time = %d, Arrival time = %d \n",j.id,j.pri,j.et,j.at);
}


int inputJobs (JobList list)
{
 int i; int size;

 printf("\n Enter the Number of Jobs :");
 scanf("%d", &size);

 for (i=0;i<size;i++)
 {
  printf ("\nEnter job ID");
  scanf ("%d",&list[i].id);
  printf ("Enter Priority (from 0 - 2)");
  scanf ("%d",&list[i].pri);
  printf ("Execution Time");
  scanf ("%d",&list[i].et);
  printf ("Arrival Time");
  scanf ("%d",&list[i].at);
 }
 return size;
}

SeqList insert(Job j , SeqList sl)
{

//Implement this function
	int index=sl.head;
	
	if(st[index].next==-1)	/*no elements are there in sl SeqList*/
	{
		int loc=nextfreeloc;
		st[loc].ele=j;
		st[loc].next=-1;
		st[index].next=loc;
		nextfreeloc++;
		sl.size++;
		return sl;
	}

	int last;

	while(index!=-1)
	{
		if(st[index].next==-1)
		{
			last=index;
			break;
		}
		if(compare(j,st[index].ele)==GREATER  || compare(j,st[index].ele)==EQUAL)
		{
			int in=st[index].next;
			if(compare(j,st[in].ele)==LESSER || compare(j,st[in].ele)==EQUAL)
			{
				int t=nextfreeloc;
				int tmp=st[index].next;
				st[index].next=t;
				st[t].ele=j;
				st[t].next=tmp;
				nextfreeloc++;
				sl.size++;
				return sl;
			}
		}
		index=st[index].next;
	}
	int x=nextfreeloc;
	st[last].next=x;
	nextfreeloc++;
	st[x].ele=j;
	st[x].next=-1;
	sl.size++;
	return sl;	
 }
  
void insertelements (JobList list , int size, SeqList s[3])
{

// Implement this function
	for(int i=0;i<size;i++)
	{
		if(list[i].pri==0)
			s[0]=insert(list[i], s[0]);
		if(list[i].pri==1)
			s[1]=insert(list[i],s[1]);
		if(list[i].pri==2)
			s[2]=insert(list[i],s[2]);
	}
}

void copy_sorted_ele(SeqList s[3] , JobList ele)
{

// Implement this function
	int k=0,index;
	for(int i=2;i>=0;i--)
	{
		index=s[i].head;
		if(st[index].next==-1)
		{
		}
		else
		{
			index=st[index].next;
			while(index!=-1)
			{
				ele[k]=st[index].ele;
				index=st[index].next;
				k++;
			}
		}	
	}
}

void printlist(SeqList sl)
{

// Implement this function

	int index=sl.head;
	index=st[index].next;
	while(index!=-1)
	{
		printJob(st[index].ele);
		index=st[index].next;
	}
}

void printJobList(JobList list, int size)
{

// Implement this function
	for(int i=0;i<size;i++)
	{
		printJob(list[i]);
	}
}

void sortJobList(JobList list, int size)
{
 SeqList seq[3];
 seq[0] = createlist();
 seq[1] = createlist();
 seq[2] = createlist();
 insertelements (list, size, seq);
 printlist(seq[0]);   
 printlist(seq[1]);
 printlist(seq[2]);
 copy_sorted_ele (seq , list); 
}
