#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int ele;
	struct node * left;
	struct node * right;
}node;

void insertNode(node * root, int ele);

void deleteNode(node * root);
