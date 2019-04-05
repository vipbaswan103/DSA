#include "def.h"

void copy(records * ob1, records * ob2)
{
	ob1->cardNumber=ob2->cardNumber;
	strcpy(ob1->Bank_Code, ob2->Bank_Code);
	ob1->year=ob2->year;
	ob1->month=ob2->month;
	strcpy(ob1->fname,ob2->fname);
	strcpy(ob1->lname,ob2->lname);	
}
void insertInOrder(records * arr, records key, int size)
{
	int i=size-2;
	//for(int j=2; j<size; j++)
		while(i>=0 && arr[i].cardNumber>key.cardNumber)
		{
			copy(&arr[i+1],&arr[i]);
			i--;
		}
		copy(&arr[i+1],&key);	
	//}	
}

void insertionSort(records * arr, int size)
{
	if(size<=1)
	{
		int x;
		tmp2=&x;
		return;
	}
	insertionSort(arr, size-1);
	insertInOrder(arr, arr[size-1],size);
}


void print(records * array, int size)
{
	for(int j=0;j<size;j++)
	{
		printf("\n\n***%d***",j+1);
		printf("\nCard Number :%llu",array[j].cardNumber);
		printf("\nBank Number :%s",array[j].Bank_Code);
		printf("\nYear :%u",array[j].year);
		printf("\nMonth :%u",array[j].month);
		printf("\nFname :%s ",array[j].fname);
		printf("\nLname :%s",array[j].lname);
	}

}
