#include "fun.h"
int min(int x, int y)
{
	return x>y? y : x;
}
void mergeSortIter(student * list,int size)
{
	student *l,*l1, *l2;
	int q,r;
	for(int curr=1;curr<size;curr=(curr*2))
	{
		for(int p=0; p<size-1; p+=(curr*2))
		{
			q=(curr+p-1);
			r=min(p+(2*curr)-1,size-1);

			l=(student *)malloc(sizeof(student)*(r-p+1));
			l1=(student *)malloc(sizeof(student)*(q-p+1));
			l2=(student *)malloc(sizeof(student)*(r-q));
			int k=0;
			for(int x=p;x<=q;x++)
			{
				//printf("1");
				copy(&l1[k], &list[x]);
				k++;		
			}
			k=0;
			for(int x=q+1;x<=r;x++)
			{
				//printf("2");
				copy(&l2[k], &list[x]);
				k++;		
			}
			merge(l1,q-p+1,l2,r-q,l);
			k=0;
			for(int x=p;x<=r;x++)
			{
				//printf("\t3\t");
				//printf("\tp=%d,q=%d,r=%d",p,q,r);
				copy(&list[x],&l[k]);
				k++;
			}
		}
	}
	/*for(int i=(size+1)/2;flag==1 && i>=1;i=(i+1)/2)
	{
		//printf("ah");
		int add=pow(2,k)-1;
		int tmp=0;
		for(int j=0;j<i;j++)
		{
			if(tmp+add>(size-1))
			{
				//printf("\n1\t tmp=%d, add=%d\n",tmp,add);
				p=tmp;
				r=size-1;
				q=(p+r)/2;
			}
			else
			{
				//printf("\n2\t tmp=%d, add=%d\n",tmp,add);
				p=tmp;
				r=tmp+add;
				q=(p+r)/2;
			}
			l=(student *)malloc(sizeof(student)*(r-p+1));
			l1=(student *)malloc(sizeof(student)*(q-p+1));
			l2=(student *)malloc(sizeof(student)*(r-q));
			int k=0;
			for(int x=p;x<=q;x++)
			{
				//printf("1");
				copy(&l1[k], &list[x]);
				k++;		
			}
			k=0;
			for(int x=q+1;x<=r;x++)
			{
				//printf("2");
				copy(&l2[k], &list[x]);
				k++;		
			}
			merge(l1,q-p+1,l2,r-q,l);
			k=0;
			for(int x=p;x<=r;x++)
			{
				//printf("\t3\t");
				//printf("\tp=%d,q=%d,r=%d",p,q,r);
				copy(&list[x],&l[k]);
				k++;
			}
			tmp+=add+1;	
		}
		if(i==1)
		{
			flag=0;
		}
		k++;
	}*/
}
				
