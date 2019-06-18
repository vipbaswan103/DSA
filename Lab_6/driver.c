#include "fun.h"
#define max 5
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
	float cgpa;
	char name[11];
	student * list=(student *)malloc(sizeof(student)*max);
	int i=0;
	long long int size=sizeof(student)*max;
	int tmp=max;
	
	while(fscanf(fp,"\"%[^,],%f\"\n",name,&cgpa)!=EOF)
	{
		if(i>tmp-1)
		{
		//	printf("%d\t",i);
			list=(student *)realloc(list,size*2);
			size*=2;
			tmp*=2;
		}
		list[i].cgpa=cgpa;
		strcpy(list[i].name,name);
		i++;
	}
	
	
	//printf("Sorted array ---------------------->\n");
	gettimeofday(&t1,NULL);
	mergeSort(list, 0,i-1);
	gettimeofday(&t2,NULL);


	et=(t2.tv_sec-t1.tv_sec)*1000;
	et+=(t2.tv_usec-t1.tv_usec)/1000;

	printArr(list,i);
	FILE * tmpFile=fopen("orig","w");
	for(int j=0;j<i;j++)
	{
		fprintf(tmpFile,"\"%s,%f\"\n",list[j].name,list[j].cgpa);
	}
	fclose(tmpFile);

	printf("\n****** Total time taken is %f ms ******\n",et);	
	fclose(fp);
}
