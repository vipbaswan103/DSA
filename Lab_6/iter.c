#include "fun.h"
int min(int x,int y)
{
	return x>y?y:x;
}
void mergeSort(student * list,int lo, int hi)
{
	int size=hi-lo+1;
	student * l, *l1, *l2;
	for(int curr=1;curr<size;curr=curr*2)
	{
		for(int p=0;p<size-1;p+=(curr*2))
		{
			int q=(curr+p-1);
			int r=min(p+(2*curr)-1,size-1);

			l=(student *)malloc(sizeof(student)*(r-p+1));
			l1=(student *)malloc(sizeof(student)*(q-p+1));
			l2=(student *)malloc(sizeof(student)*(r-q));
			int k=0;
			for(int x=p;x<=q;x++)
			{
				copy(&l1[k], &list[x]);
				k++;		
			}
			k=0;
			for(int x=q+1;x<=r;x++)
			{
				copy(&l2[k], &list[x]);
				k++;		
			}
			merge(l1,q-p+1,l2,r-q,l);
			k=0;
			for(int x=p;x<=r;x++)
			{
				copy(&list[x],&l[k]);
				k++;
			}

		}
	}
}
				
