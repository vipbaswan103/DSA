#include "Exer3.h"
int testCycle(node * list)
{
	if(list==NULL)
		return 0;
	node * hare=list;
	node * tort=list;
	int x=0;
	int tmp=0;
	while(hare->next!=NULL )
	{
		if(hare==tort /*|| isBehind(hare,tort,list)==1) && x!=0*/)
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
		return 1;
	return 0;
}
