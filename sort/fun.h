#include<stdio.h>
#include<stdlib.h>
#include <math.h>

struct Node
{
	double ele;
	struct Node * next;
};

typedef struct Node * node;

void bubbleSort(int arr[],int size);
void selectionSort(int arr[],int size);

void insertInOrder(int arr[],int key, int size);
void insertionSortIter(int arr[],int size);
void insertionSortRecur(int arr[],int size);

void sortedMerge(int arr3[],int arr1[],int arr2[],int s1, int s2);
void mergeSortRecur(int arr[],int p, int r);
void mergeSortIter(int arr[], int p, int r);
void mergeSort(int arr[],int p, int r);
int partition(int arr[], int p, int r);
void quickSortRecur(int arr[], int p, int r);
void quickSortIter(int arr[], int p, int r);
void heapSort(int arr[], int size);

void countingSort(int arr[], int l, int h, int size);
void radixSort(int arr[], int n, int d);
void bucketSort(double arr[], int n);
void ListSort(node head);
void printBucket(struct Node head);
void print(int arr[], int size);
