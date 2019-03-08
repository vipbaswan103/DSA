#include "Exer3.h"

int totSpace=0;
void * myAlloc(int size)
{
	void * ptr=malloc(size+sizeof(int));
	int * tmp=(int *)ptr;
	tmp[0]=size;
	totSpace+=size;
	tmp=tmp+1;
	void * x=(void *)tmp;
	return x;
}
void myFree(void * ptr)
{
	int * tmp=(int *) ptr;
	tmp=tmp-1;
	totSpace-=tmp[0];
	void * x=(void *)tmp;
	free(x);
}
node * insertList(node * list, int ele)
{
	node * newNode=(node *)myAlloc(sizeof(node));
	if(list==NULL)
	{
		newNode->next=NULL;
		newNode->ele=ele;
		list=newNode;
		return list;		
	}
	node * tmp=list;
	while(tmp->next!=NULL)
	{
		tmp=tmp->next;
	}
	tmp->next=newNode;
	newNode->next=NULL;
	newNode->ele=ele;
	return list;
}
node * createList(int n)
{
	int ele;
	node * list=(node *)myAlloc(sizeof(node));
	list=NULL;
	int tmp=1;
 	for(int i=0;i<n;i++)
	{
		//ele=(rand()%41)+10;
		ele=tmp;
		list=insertList(list,ele);
		tmp+=3;
	}
	return list;
}

node* createCycle(node * list, int x)
{
	//int x=(rand()%41)+10;
	node * tmp=list;
	while(tmp!=NULL)
	{
		if(tmp->ele==x)
			break;
		tmp=tmp->next;
	}
	if(tmp!=NULL)
	{
		node * last=list;
		while(last->next!=NULL)
		{
			last=last->next;
		}
		last->next=tmp;
	}
	return list;
}
int isBack(node * hare, node * tort, node * list)
{
	node * h=hare;
	node * t=tort;
	
	int f1=0,f2=0;
	node * tmp=list;
	while(tmp!=NULL)
	{
		if(tmp==h)
		{
			f1=1;
			break;
		}
		if(tmp==t)
		{
			f2=1;
			break;
		}
		tmp=tmp->next;
	}

	if(f1==1 && f2==0)
		return 1;
	else
		return 0;
}
/*node * findStart(node * list)
{
	if(list==NULL)
		return NULL;
	
	node * hare=list;
	node * tort=list;
	int x=0;
	int tmp=0;
	while(hare->next!=NULL )
	{
		if((hare==tort || isBack(hare,tort,list)==1) && x!=0)
		{
			tmp=1;
			break;
		}		
		x=1;
		hare=hare->next->next;
		tort=tort->next;
		if(hare==NULL)
			break;
	}
	if(tmp==1)
		return hare;
	return NULL;
}*/

node * findStart(node * list)
{
	node * hare=list;
	node * tort=list;

	node * save;
	int x=0;
	while(hare->next!=NULL)
	{
		if(x!=0 &&hare==tort)
		{
			save=hare;
			break;
		}
		hare=hare->next->next;
		tort=tort->next;
		x=1;
	}

	node * tmp=list;
	while(tmp!=save)
	{
		tmp=tmp->next;
		save=save->next;
	}
	return tmp;
}
int findLengthLoop(node * list)
{
	node * tmp=findStart(list);
	node * trav=tmp->next;
	int k=1;
	while(trav!=tmp)
	{
		k++;
		trav=trav->next;
	}
	return k;
}
node * createCircular(node * list)
{
	int flag=testCycle(list);
	node * tmp=list;
	if(flag==0)
	{
		while(tmp->next!=NULL)
		{
			tmp=tmp->next;
		}		
		tmp->next=list;
		return list;
	}	
	node * point=findStart(list);
	printf("Start:%d\n",point->ele);	
	node * saveMe;
	tmp=list;
	while(tmp!=point)
	{
		saveMe=tmp->next;
		myFree(tmp);
		tmp=saveMe;
	}
	list=tmp;
	return list;
}

void printCircular(node * list)
{
	if(list->next==list)
	{
		printf("\n%d\t",list->ele);
		return;
	}
	node * first=list;
	node * tmp=list->next;
	printf("\n%d\t",list->ele);
	while(tmp!=first)
	{
		printf("%d\t",tmp->ele);
		tmp=tmp->next;
	}	
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
