#include "def.h"
typedef long long unsigned llu;
int main(int argc, char * argv[])
{
	if(argc!=2)
		exit(1);

	FILE * fp=fopen(argv[1],"r");
	//printf("1");
	int i=1;
	records * array=(records *)malloc(sizeof(records)*10);
	unsigned long long int cnum;
	char bcode[6];
	unsigned int y,m;
	char  fname[20], lname[20];
	while(fscanf(fp,"\"%llu,%[^,],%u/%u,%[^,],%[^\"]\"\n",&cnum,bcode,&m,&y,fname,lname)!=EOF)
	{
		//printf("h");
		if(i>10)
		{
			array=(records *)realloc(array, sizeof(records)*i);
		}
		array[i-1].cardNumber=cnum;
		strcpy(array[i-1].Bank_Code,bcode);
		array[i-1].year=y;
		array[i-1].month=m;
		strcpy(array[i-1].fname,fname);
		strcpy(array[i-1].lname,lname);
		i++;
	}

	struct timeval t1,t2;
	double elapsedTime;

	gettimeofday(&t1,NULL);
	int b;
	tmp1=&b;
	insertionSort(array, i-1);
	gettimeofday(&t2,NULL);

	elapsedTime=(t2.tv_sec-t1.tv_sec)*1000.0;
	elapsedTime+=(t2.tv_usec-t1.tv_usec)/1000.0;

	print(array,i-1);
	printf("\n\n****Total time taken: %f ms****\n",elapsedTime);

	printf("\n\n****Total stack space used : %ld ****\n",tmp1-tmp2);	
}
