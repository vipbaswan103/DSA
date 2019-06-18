#include<stdio.h>
#include<stdlib.h>
#include <string.h>
int main(int argc, char * argv[])
{
	if(argc!=3)
	{
		printf("ERROR: Wrong number of arguments\n");
		exit(0);
	}
	FILE * fp1=fopen(argv[1],"r");
	FILE * fp2=fopen(argv[2],"r");

	float cgpa1,cgpa2;
	char name1[11], name2[11];

	while(fscanf(fp1,"\"%[^,],%f\"\n",name1,&cgpa1)!=EOF && fscanf(fp2,"\"%[^,],%f\"\n",name2,&cgpa2)!=EOF)
	{
		if(cgpa1!=cgpa2 || strcmp(name1,name2)!=0)
		{
			printf("Files don't have same data\n");
			printf("Name1: %s\t CGPA1: %f\n",name1,cgpa1);
			printf("Name2: %s\t CGPA2: %f\n",name2,cgpa2);
			fclose(fp1);
			fclose(fp2);
			exit(0);
		}
	}
	printf("Files have same data\n");
	fclose(fp1);
	fclose(fp2);
	return 0;
}
