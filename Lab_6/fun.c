#include "fun.h"

void merge(student * ls1, int s1, student * ls2, int s2, student * ls3)
{
	int size=s1+s2;
	int i=0,j=0,k=0;
	while(i<s1 && j<s2)
	{
		if(ls1[i].cgpa <= ls2[j].cgpa)
		{
			copy(&ls3[k],&ls1[i]);
			i++;
		}
		else
		{
			copy(&ls3[k],&ls2[j]);
			j++;
		}
		k++;
	}
	int m=i;
	int n=j;
	
	for(m=i;m<s1;m++)
	{
		copy(&ls3[k],&ls1[m]);
		k++;
	}
	for(n=j;n<s2;n++)
	{
		copy(&ls3[k],&ls2[n]);
		k++;
	}
}

void copy(student * s1, student * s2)
{
	s1->cgpa=s2->cgpa;
	strcpy(s1->name,s2->name);
}
void printArr(student * list, int num)
{
	for(int i=0;i<num;i++)
	{
		printf("\n\n**** Record %d ****\n",i+1);
		
		printf("Name: %s\n",list[i].name);
		printf("CGPA: %f\n",list[i].cgpa);
	}

}
