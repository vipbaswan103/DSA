#include<stdio.h>
#include<stdlib.h>
int totSpace=0;
void * myAlloc(int size)
{
	void * ptr=malloc(size+sizeof(int));
	int * tmp=(int *)ptr;
	tmp[0]=size;
	totSpace+=size+sizeof(int);
	return (void *)tmp;
}
void myFree(void * ptr)
{
	int * tmp=(int *) ptr;
	totSpace-=tmp[0]+sizeof(int);
	free(ptr);
}
void insertList(node * list, int ele)
{
	node * newNode=(node *)myAlloc(sizeof(node));
	if(list==NULL)
	{
		newNode->next=NULL:
		newNode->ele=ele;
		list=newNode;
		return;		
	}
	node * tmp=list;
	while(tmp->next!=NULL)
	{
		tmp=tmp->next;
	}
	tmp->next=newNode;
	newNode->next=NULL;
	newNode->ele=ele;
}
node * createList(int n)
{
	int ele;
	node * list=(node *)myAlloc(sizeof(node));
	list=NULL;
 	for(int i=0;i<n;i++)
	{
		ele=(rand()%40)+10;
		insertList(list,ele);
	}
	return list;
}
void print(node * list)
{
	node * tmp=list;
	while(tmp!=NULL)
	{
		printf("%d\t",tmp->ele);
		tmp=tmp->next;
	}
}
