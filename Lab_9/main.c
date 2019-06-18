#include "fun.h"
int main(int argc, char * argv[])
{
	if(argc!=2)
		exit(0);
	FILE * fp=fopen(argv[1],"r");
	char ** book;
	book=parse(fp);

	int * result=(int *)malloc(sizeof(int)*2);
	result=profile(book);
	
	int tableSize, baseSize;
	tableSize=result[0];
	baseSize=result[1];

	Hash * hashTable;
	hashTable=create(tableSize);

	
	int insertionCost=insertAll(hashTable,book,SIZE,tableSize,baseSize);

	printf("\n%d\n",insertionCost);	
	//printHashTable(hashTable, book, tableSize);

	/*fp=fopen("stopwords.txt","r");
	char str[50];
	printf("No of elements before deletion: %d\n",hashTable->elementCount);
	while(fscanf(fp,"%s\n",str)!=EOF)
	{
		cleanUp(hashTable, book, str, baseSize, tableSize);
	}
	printf("No of elements after deletion: %d\n",hashTable->elementCount);
	printHashTable(hashTable, book, tableSize);*/
	return 0;
}
