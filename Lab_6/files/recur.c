#include "fun.h"
void mergeSortRecur(student * list, int p, int r)
{
	student *l,*l1, *l2;
	int q;
	if(p<r)
	{
		q=(p+r)/2;
		mergeSortRecur(list,p,q);
		mergeSortRecur(list,q+1,r);
		l=(student *)malloc(sizeof(student)*(r-p+1));
		l1=(student *)malloc(sizeof(student)*(q-p+1));
		l2=(student *)malloc(sizeof(student)*(r-q));
		int k=0;
		for(int i=p;i<=q;i++)
		{
			copy(&l1[k], &list[i]);
			k++;		
		}
		k=0;
		for(int i=q+1;i<=r;i++)
		{
			copy(&l2[k], &list[i]);
			k++;		
		}
		merge(l1,q-p+1,l2,r-q,l);
		k=0;
		for(int i=p;i<=r;i++)
		{
			copy(&list[i],&l[k]);
			k++;
		}
	}
}
