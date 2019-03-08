typedef struct node
{
	int ele;
	struct node * next;
}node;
extern int totSpace;
node * createList(int n);
node * createCycle(int n);
void print(node * list);
void * myAlloc(int size);
void * myFree(void * ptr);
