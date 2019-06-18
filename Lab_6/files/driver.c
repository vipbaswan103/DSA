#include "fun.h"
#include <unistd.h>
#include <sys/time.h>
#define max 10240
#define k 1024
#define m 10240

char * names[m/k];
void readFiles(FILE * fp, student * list, FILE * out[m/k])
{
	float cgpa;
	char name[11];
	int i=0,j=0;
	for(int q=0;q<m/k;q++)
	{
		char filename[]="FileXXXXXX";
		while(i<k)
		{
			fscanf(fp,"\"%[^,],%f\"\n",name,&cgpa);
			list[i].cgpa=cgpa;
			strcpy(list[i].name,name);
			i++;
		}
		mergeSortIter(list,i);
		int fd=mkstemp(filename);
		close(fd);
		names[j]=(char *)malloc(sizeof(char)*11);
		strcpy(names[j],filename);
		out[j]=fopen(names[j],"w");
		for(int w=0;w<i;w++)
		{
			fprintf(out[j],"\"%s,%f\"\n",list[w].name,list[w].cgpa);
		}
		fclose(out[j]);
		j++;
		i=0;
	}
}
struct timeval t1, t2;
double et=0;
int main(int argc, char * argv[])
{
	if(argc!=2)
	{
		printf("Error: Wrong number of arguments\n");
		exit(0);
	}
	
	FILE * fp=fopen(argv[1],"r");
	FILE * out[m/k];
	student * list=(student *)malloc(sizeof(student)*max);
	readFiles(fp,list,out);

	for(int i=0;i<m/k;i++)
	{
		out[i]=fopen(names[i],"r");
	}
	
	gettimeofday(&t1,NULL);
	mergeSortFiles(out,m/k);
	gettimeofday(&t2,NULL);

	fclose(fp);

	for(int i=0;i<m/k;i++)
	{
		remove(names[i]);	
	}
	remove("out");	
	et=(t2.tv_sec-t1.tv_sec)*1000.0;
	et+=(t2.tv_usec-t1.tv_usec)/1000.0;

	printf("*** Size of file : %d\nValue of k: %d\nTime takes (in ms): %f ***\n\n",max,k,et);
	/*float cgpa;
	char name[11];
	student * list=(student *)malloc(sizeof(student)*max);
	int i=0;
	long long int size=sizeof(student)*max;
	int tmp=max;
	
	while(fscanf(fp,"\"%[^,],%f\"\n",name,&cgpa)!=EOF)
	{
		if(i>tmp-1)
		{
			printf("%d\t",i);
			list=(student *)realloc(list,size*2);
			size*=2;
			tmp*=2;
		}
		list[i].cgpa=cgpa;
		strcpy(list[i].name,name);
		i++;
	}*/
	
	
	/*printf("\n%d\n",i);
	//printArr(list,i);
	printf("Sorted array ---------------------->\n");
	//mergeSortRecur(list,0,i-1);
	gettimeofday(&t1,NULL);
	mergeSortIter(list, i);
	gettimeofday(&t2,NULL);

	et=(t2.tv_sec-t1.tv_sec)*1000;
	et+=(t2.tv_usec-t1.tv_usec)/1000;

	printArr(list,i);

	printf("\n****** Total time taken is %f ms ******\n",et);	
	fclose(fp);*/
}
