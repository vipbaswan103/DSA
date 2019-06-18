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

void mergeFiles(FILE * fp1, FILE * fp2, FILE * out)
{
	float cgpa1,cgpa2;
	char name1[11],name2[11];
	fscanf(fp1,"\"%[^,],%f\"\n",name1,&cgpa1); 
	fscanf(fp2,"\"%[^,],%f\"\n",name2,&cgpa2);
	int flag1,flag2;
	while(1)
	{
		if(cgpa1<=cgpa2)
		{
			fprintf(out,"\"%s,%f\"\n",name1,cgpa1);
			flag1=fscanf(fp1,"\"%[^,],%f\"\n",name1,&cgpa1); 
		}
		else
		{
			fprintf(out,"\"%s,%f\"\n",name2,cgpa2);
			flag2=fscanf(fp2,"\"%[^,],%f\"\n",name2,&cgpa2);
		}
		if(flag1==EOF || flag2==EOF)
		{
			break;
		}
	}
	
	if(flag2==EOF)
	{
		fprintf(out,"\"%s,%f\"\n",name1,cgpa1);	
		while(fscanf(fp1,"\"%[^,],%f\"\n",name1,&cgpa1)!=EOF)
		{
			fprintf(out,"\"%s,%f\"\n",name1,cgpa1);	
		}
	}
	if(flag1==EOF)
	{
		fprintf(out,"\"%s,%f\"\n",name2,cgpa2);	
		while(fscanf(fp2,"\"%[^,],%f\"\n",name2,&cgpa2)!=EOF)
		{
			fprintf(out,"\"%s,%f\"\n",name2,cgpa2);	
		}
	}
	fclose(fp1);
	fclose(fp2);
	fclose(out);
}

void mergeSortFiles(FILE * in[],int size)
{
	FILE *out, *tmp;
	out=fopen("out","w");	
	mergeFiles(in[0],in[1],out);
		
	for(int i=2;i<size;i++)
	{
		tmp=fopen("final","w");
		out=fopen("out","r");
		mergeFiles(out,in[i],tmp);	
		tmp=fopen("final","r");
		out=fopen("out","w");
		char name[11];
		float cgpa;
		while(fscanf(tmp,"\"%[^,],%f\"\n",name,&cgpa)!=EOF)
		{
			fprintf(out,"\"%s,%f\"\n",name,cgpa);
		}
		fclose(tmp);
		fclose(out);
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
