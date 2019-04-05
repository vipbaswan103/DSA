#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/time.h>
typedef long long unsigned llu;
typedef unsigned u;
typedef struct records
{
	unsigned long long int cardNumber;
	char Bank_Code[6];
	unsigned int year;
	unsigned int month;
	char fname[20];
	char lname[20];
}records;

int * tmp1;
int * tmp2;
void print(records * array, int size);
void insertionSort(records * array, int size);
