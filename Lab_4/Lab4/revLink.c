#include "Exer3.h"
int canReach(node * tmp1, node * tmp3)
{
	node * tmp=tmp1;
	while(tmp!=NULL)
	{
		if(tmp==tmp3)
			return 1;
		tmp=tmp->next;
	}
	return 0;
}
int testCycle(node * list)
{
	node * tmp1;
	node * tmp2;
	node * tmp3;
	if(list==NULL)
		return 0;
	if(list->next==list)
	{
		return 1;
	}	
	tmp1=NULL;
	tmp2=list;
	tmp3=list->next;
	while(tmp3!=NULL)
	{
		if(canReach(tmp1,tmp3)==1)
		{
			printf("In\n");
			while(tmp3!=NULL)
			{
				tmp1->next=tmp2;
				tmp2=tmp1;
				tmp1=tmp3;
				tmp3=tmp3->next;
			}
			tmp1->next=tmp2;
			return 1;
		}
		tmp2->next=tmp1;
		tmp1=tmp2;
		tmp2=tmp3;
		tmp3=tmp3->next;
	}	
	return 0;
}
