#include "qsort.h"


int main(int argc, char* argv[])
{
	size = 0;
	
	char * fileName = argv[1];
	printf("%s\n",fileName);

	int* studentArray = readData(fileName);

	printArray(studentArray, size);

	quickSortKnownKeyRange(studentArray,size, 10, 30);

	printf("\nSorted output is:\n");

	printArray(studentArray, size);
	
}
