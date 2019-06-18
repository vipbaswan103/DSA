#include "stack.h"
#include<string.h>

typedef struct emp
{
	char name[11];
	int empid;
}emp;

void quickSort(emp * arr, int p, int r);
void quickSortIter(emp * arr, int s,int p, int r);
int partition(emp * arr, int p, int r);

void print(emp * arr, int size);
void sort(emp * arr, int s, int p, int r);
void swap(emp * e1, emp * e2);
int estimateCutoff(emp * arr,int size);
