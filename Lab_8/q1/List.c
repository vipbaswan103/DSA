#include "List.h"

void * myalloc(int size)
{
	void * ptr=(void *)malloc(size+sizeof(int));
	int * p=(int *)ptr;
	p[0]=size;
	p=p+1;
	ptr=(void *)p;
	globalCounter+=size;
	return ptr;
}

void myFree(void * ptr)
{
	int * p=(void *) ptr; 
	int x=*(p-1);
	globalCounter-=x;
	ptr=(void *)p;
	free(ptr);
}
List createList(Student studArray, int arraySize)
{
	List head=(List)myalloc(sizeof(struct list));
	head->first=NULL;
	head->last=NULL;
	head->count=0;

	Node newNode=(Node)myalloc(sizeof(struct node));
	newNode->record=&studArray[0];
	newNode->next=NULL;
	
	head->first=newNode;
	head->last=newNode;
	head->count++;

	for(int i=1;i<arraySize;i++)
	{	
		newNode=(Node)myalloc(sizeof(struct node));
		newNode->record=&studArray[i];
		newNode->next=NULL;
		head->last->next=newNode;
		head->last=newNode;
		head->count++;	
	}
	return head;
}

void insertInOrder(List list, Node newNode)
{
	if(list->first==NULL)
	{
		newNode->next=NULL;
		list->first=newNode;
		list->last=newNode;
		list->count++;
		return;
	}	

	if(newNode->record->marks <=  list->first->record->marks)
	{
		newNode->next=list->first;
		list->first=newNode;
		list->count++;
		return;
	}

	Node tmp=list->first;
	while(tmp->next!=NULL)
	{
		if(tmp->record->marks <= newNode->record->marks && newNode->record->marks < tmp->next->record->marks)
		{
			Node save=tmp->next;
			tmp->next=newNode;
			newNode->next=save;
			list->count++;
			return;
		}	
		tmp=tmp->next;
	}

	tmp->next=newNode;
	newNode->next=NULL;
	list->last=newNode;
	list->count++;
}

List insertionSort(List list)
{
	List sorted=(List)myalloc(sizeof(struct list));
	sorted->first=NULL;
	sorted->last=NULL;
	sorted->count=0;

	Node tmp=list->first;
	while(tmp!=NULL)
	{
		Node save=tmp->next;
		insertInOrder(sorted,tmp);
		tmp=save;
	}
	return sorted;
}
double measureSortingTime(List list)
{
	struct timeval t1,t2;
	double et=0;

	gettimeofday(&t1,NULL);
	list=insertionSort(list);
	gettimeofday(&t2,NULL);

	et=(t2.tv_sec-t1.tv_sec)*1000.0;
	et+=(t2.tv_usec-t1.tv_usec)/1000.0;
	return et;
}
