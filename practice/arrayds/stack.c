#include "stack.h"

int top=-1;
int max=5;
void push(int stack[], int ele)
{
	//printf("here");
	if(top==max-1)
	{
		int n[2*(top+1)];
		max=2*(top+1);
		for(int i=0;i<=top;i++)
			n[i]=stack[i];
		stack=n;
	}
	stack[top+1]=ele;
	top+=1;
}

int pop(int stack[])
{
	//printf("here");
	if(top==-1)
	{
		printf("Stack is empty!!");
		return -1;
	}
	int x=stack[top];
	top-=1;
	return x;
}

int search(int stack[], int ele)
{
	for(int i=0;i<=top;i++)
	{
		if(stack[i]==ele)
			return 1;
	}
	return -1;
}

void print(int stack[])
{
	for(int i=top;i>=0;i--)
	{
		//printf("%d  ",i);
		printf("%d\n",stack[i]);
	}
}
