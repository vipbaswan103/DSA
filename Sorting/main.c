#include "sorts.h"
int main(int argc, char * argv[])
{
	if(argc!=2)
		exit(1);

	FILE * fp=fopen(argv[1],"r");
	int size;
	fscanf(fp,"%d",&size);

	int arr[size];

	int tmp;
	int i=0;
	while(fscanf(fp,"%d",&tmp)!=EOF)
	{
		arr[i]=tmp;
		i++;
	}
	
	printf("Initial array: \n");
	for(int i=0;i<size;i++)
		printf("%d\t",arr[i]);
	printf("\n");

	sort(arr,0,size-1);

	printf("Final array: \n");
	for(int i=0;i<size;i++)
		printf("%d\t",arr[i]);
	printf("\n");

	fclose(fp);
	return 0;
}
