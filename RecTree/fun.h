#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int ele;
	struct node * left;
	struct node * right;
}Node;

Node * insert(Node * root, int key);
Node  * delete(Node * root, int key);
void inOrder(Node * root);
