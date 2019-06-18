#include "quick.h"
#include <sys/time.h>
#define max 1000


int main(int argc, char * argv[])
{
	if(argc!=2)
		exit(0);

	FILE * fp=fopen(argv[1],"r");
	if(fp==NULL)
		exit(0);
	
	emp * arr=(emp *)malloc(sizeof(emp)*max);
	
	int size=0;
	
	char * name;
	int id;
	int cut=max;
	while(fscanf(fp,"%s %d\n",name,&id)!=EOF)
	{
		if(size>=cut)
		{
			arr=(emp *)realloc(arr,sizeof(emp)*cut*2);
			cut=cut*2;
		}
		arr[size].empid=id;
		strcpy(arr[size].name,name);
		size++;
	}
	//printf("%d\n",size);
	//print(arr,size);
	//printf("\n\n");
	//partition(arr,0,size-1);
	//sort(arr,100,size);
	//printf("%d\n",x);
	//print(arr,size);
	
	/*gettimeofday(&t1,NULL);	
	quickSortIter(arr,1,0,size-1);
	gettimeofday(&t2,NULL);

	emp xyz[size];
	for(int i=0;i<size;i++)
	{
		xyz[i]=arr[i];
	}

	gettimeofday(&t3,NULL);
	sort(arr,10,0,size-1);
	gettimeofday(&t4,NULL);

	et1=(t2.tv_sec-t1.tv_sec)*1000.0;
	et1+=(t2.tv_usec-t1.tv_usec)/1000.0;

		
	et2=(t4.tv_sec-t3.tv_sec)*1000.0;
	et2+=(t4.tv_usec-t3.tv_usec)/1000.0;*/

	//printf("%f\n%f",et1,et2);

	int x=estimateCutoff(arr,size);
	//print(arr,size);
	printf("********Cutoff value**********\n\t%d\n",x);
	fclose(fp);
}
