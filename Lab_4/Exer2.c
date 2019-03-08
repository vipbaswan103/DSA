#include<stdlib.h>
#include<stdio.h>
typedef int DATA;
int totSpace=0;
void * myAlloc(int size)
{
	void * ptr=malloc(size+sizeof(int));
	if(ptr==NULL)
		return NULL;
	int * tmp=(int *)ptr;
	tmp[0]=size;
	tmp=tmp+1;
	totSpace+=size;
	return (void *)(tmp);
}

void myFree(void * ptr)
{
	int * tmp=(int *)ptr;
	tmp=tmp-1;
	totSpace-=tmp[0];
	ptr=(void *)tmp;
	free(ptr);
}
int main()
{
	for(int i=0;i<10;i++)
	{
		int x=rand();
		printf("Initial Heap Memory: %u\n",totSpace);
		x=(x%15001)+10000;
		DATA * ptr=(DATA *)myAlloc(x*sizeof(DATA));
		//printf("%d\n",ptr[0]);
		if(ptr==NULL)
		{
			printf("Failed to allocate memory: Exiting...");
			break;
		}
		printf("x: %d\n",x);
		printf("First :%p and Last :%p\n",ptr,ptr+x-1);
		printf("Diff: %ld\n",(ptr+x-1)-ptr);

		printf("Final Heap Memory: %d\n",totSpace);
		myFree(ptr);
		printf("Heap Memory after myFree(): %d\n",totSpace);
		printf("\n");
	}
	
	printf("\n***Out of Loop: *** %u\n",totSpace);
	return 0;
}
