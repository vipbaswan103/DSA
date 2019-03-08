#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
	int n=argc;
	FILE *fp1, *fp2;
	fp1=fopen(argv[1],"r");
	fp2=fopen(argv[2],"w");
	
	if(fp1==NULL)
	{
		printf("Error in opening file. Exiting...");
		exit(1);
	}
	if(fp2==NULL)
	{
		printf("Error in opening file. Exiting...");
		exit(1);
	}
	//printf("Here\n");
	int tmp;
	while(fscanf(fp1,"%d",&tmp)!=EOF)
	{
		//printf("Inside");
		//fscanf(fp1,"%d",&tmp);
		fprintf(fp2,"%d\n",tmp);
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}
