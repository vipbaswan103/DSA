#include "fun.h"

void insertNode(Head list, int key)
{
	Node tmp=list->next;
	Node newNode=(Node)malloc(sizeof(struct node));
	if(tmp==NULL)
	{
		//printf("hi\n");
		newNode->next=NULL;
		newNode->prev=NULL;
		newNode->key=key;
		list->next=newNode;
		list->count++;
		return;
	}

	//printf("hello\n");
	while(tmp->next!=NULL)
	{
		tmp=tmp->next;
	}
	tmp->next=newNode;
	newNode->next=NULL;
	newNode->prev=tmp;
	newNode->key=key;
	list->count++;
	return;
}

Head createList(Head list, FILE * fp)
{
	list=(Head) malloc(sizeof(struct head));
	list->count=0;
	list->next=NULL;
	if(fp==NULL)
	{
		printf("Error in opening file...");
		return list;
	}
	int key;

	while(fscanf(fp,"%d",&key)!=EOF)
	{
		insertNode(list,key);
	}
	return list;
}

void printList(Node list)
{
	Node tmp=list;
	while(tmp!=NULL)
	{
		printf("%d\t",tmp->key);
		tmp=tmp->next;
	}
	printf("\n");
}

void deleteNode(Head list, int key)
{
	Node tmp=list->next;
	if(tmp==NULL)
	{
		printf("List is empty\n");
		return;
	}

	if(tmp->key==key)
	{
		Node save=tmp;
		tmp=tmp->next;
		tmp->prev=NULL;
		list->next=tmp;
		free(save);
		list->count--;
		return;
	}
	while(tmp->next!=NULL)
	{
		if(tmp->key==key)
		{
			tmp->prev->next=tmp->next;
			tmp->next->prev=tmp->prev;
			tmp->next=NULL;
			tmp->prev=NULL;
			free(tmp);
			list->count--;
			return;
		}
		tmp=tmp->next;
	}
	if(tmp->key==key)
	{
		tmp->prev->next=NULL;
		tmp->next=NULL;
		tmp->prev=NULL;
		free(tmp);
		list->count--;
		return;
	}
	else
	{
		printf("Key not found\n");
		return;
	}
}

int length(Head list)
{
	Node tmp=list->next;
	int k=0;
	while(tmp!=NULL)
	{
		k++;
		tmp=tmp->next;
	}
	return k;
}
void splitIntoTwo(Head list, Head front, Head back)
{
	if(list->next==NULL)
	{
		front->next=NULL;
		back->next=NULL;
		front->count=0;
		back->count=0;
		return;
	}	
	if(list->next->next==NULL)
	{
		Node newNode=list->next;
		list->next=NULL;
		front->next=newNode;
		front->count=1;
		back->next=NULL;
		back->count=0;
		return;	
	}

	int len=length(list);

	int k=0;
	if(len%2!=0)
		k=(len+1)/2;
	else
		k=len/2;
	int s=0;
	Node tmp=list->next;
	while(s<k-1)
	{
		s++;
		tmp=tmp->next;
	}
	Node save=tmp->next;
	tmp->next=NULL;
	save->prev=NULL;
	back->next=save;
	back->count=k;
	front->next=list->next;
	front->count=len-k;
}
void insert(Head list, Node newNode)
{
	if(list->next==NULL)
	{
		list->next=newNode;
		newNode->next=NULL;
		newNode->prev=NULL;
		list->count++;
		return;
	}
	
	Node tmp=list->next;
	while(tmp->next!=NULL)
	{
		tmp=tmp->next;
	}	
	tmp->next=newNode;
	newNode->prev=tmp;
	newNode->next=NULL;
	list->count++;
}
Node sortedMerge(Node l1, Node l2)
{
	Head list=(Head)malloc(sizeof(struct head));
	list->next=NULL;
	list->count++;

	Node tmp1=l1, tmp2=l2;
	Node save1,save2;
	while(tmp1!=NULL && tmp2!=NULL)
	{
		if(tmp1->key<=tmp2->key)
		{
			save1=tmp1->next;
			insert(list,tmp1);
			tmp1=save1;
		}
		else
		{
			save2=tmp2->next;
			insert(list,tmp2);
			tmp2=save2;
		}
	}

	while(tmp1!=NULL)
	{
		save1=tmp1->next;
		insert(list,tmp1);
		tmp1=save1;
	}
	while(tmp2!=NULL)
	{
		save2=tmp2->next;
		insert(list,tmp2);
		tmp2=save2;
	}
	//printList(list->next);
	return list->next;
}
void mergeSort(Head list)
{
	Node tmp=list->next;
	if(tmp==NULL || tmp->next==NULL)
	{
		return;
	}

	Head p=(Head)malloc(sizeof(struct head));
	p->next=NULL;
	p->count=0;
	Head r=(Head)malloc(sizeof(struct head));
	r->next=NULL;
	r->count=0;
	
	splitIntoTwo(list,p,r);

	mergeSort(p);
	mergeSort(r);
		
	list->next=sortedMerge(p->next,r->next);
}

/*void swapNode(Head list, Node i, Node j)
{
	if(i==list->next)
	{
		i->next=j->next;
		j->next->prev=i;
		j->next=i;
		i->prev=j;
		j->prev=NULL;
		list->next=j;
		return;
	}
	i->prev->next=j;
	i->next->prev=j;
	j->prev=i->prev;
	i->prev=j->prev;
	i->next=j->next;
	j->next=i->next;
		
}*/	
Node partition(Head list, Node lo, Node hi)
{
	Node i;
	i=lo->prev;
	
	Node j;
	j=lo;
	
	int piv=hi->key;
	while(j!=hi)
	{
		if(j->key<=piv)
		{
			if(i==NULL)
				i=list->next;
			else
				i=i->next;
			int tmp=i->key;
			i->key=j->key;
			j->key=tmp;			
		}
		j=j->next;
	}	
	if(i==NULL)
	{
		int tmp=list->next->key;
		list->next->key=hi->key;
		hi->key=tmp;
		return list->next; 
	}
	else
	{
		int tmp=i->next->key;
		i->next->key=hi->key;
		hi->key=tmp;
		return i->next;
	}
}

int liesPrev(Head list, Node lo, Node hi)
{
	Node tmp=list->next;
	int flag1=0, flag2=0;
	if(hi==NULL)
		return 0;
	while(tmp!=NULL)
	{
		if(lo==tmp)
		{
			flag1=1;
			if(hi==tmp)
				flag2=1;
			break;
		}
		if(hi==tmp)
		{
			flag2=1;
			break;
		}
		tmp=tmp->next;
	}
	if(flag1==1 && flag2==0)
		return 1;
	return 0;
}
void quickSort(Head list, Node lo, Node hi)
{
	if(liesPrev(list,lo,hi)==1)
	{
		Node piv=partition(list,lo,hi);
		quickSort(list,lo,piv->prev);
		quickSort(list,piv->next,hi);
	}
}
/*void quickSortIter(Head list, Node lo, Node hi)
{

}*/

void insertInOrder(Node * list, Node newNode)
{
	Node tmp=*list;
	if(tmp==NULL)
	{
		*list=newNode;
		newNode->next=NULL;
		newNode->prev=NULL;
		return;
	}
	if(newNode->key <= (*list)->key)
	{
		newNode->next=*list;
		newNode->prev=NULL;
		(*list)->prev=newNode;
		*list=newNode;
		return;
	}

	while(tmp->next!=NULL)
	{
		if(tmp->key <= newNode->key && newNode->key < tmp->next->key)
		{
			Node save=tmp->next;
			tmp->next=newNode;
			newNode->prev=tmp;
			newNode->next=save;
			save->prev=tmp;
			return;
		}
		tmp=tmp->next;
	}
	tmp->next=newNode;
	newNode->next=NULL;
	newNode->prev=tmp;
	return; 	
}

Node shortList(Node * list)
{
	if((*list)->next==NULL)
	{
		*list=NULL;
		return *list;
	}
	Node tmp=*list;
	while(tmp->next!=NULL)
	{
		tmp=tmp->next;
	}	
	Node save=tmp;
	tmp->prev->next=NULL;
	save->next=NULL;
	save->prev=NULL;
	return save;
}
void insertionSort(Node * list)
{
	if((*list)->next==NULL)
		return;
	Node tmp=shortList(list);
	insertionSort(list);
	insertInOrder(list,tmp);
}

