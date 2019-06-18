#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<sys/time.h>

typedef struct student
{
	char name[11];
	float cgpa;
}student;

void merge(student * ls1, int s1, student * ls2, int s2, student * list);
void printArr(student * list, int num);
void mergeSort(student * list, int p, int q);
void copy(student * s1, student * s2);
