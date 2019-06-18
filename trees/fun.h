#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int ele;
	struct node * left;
	struct node * right;
	struct node * parent;
}node;

void insert(node ** root, int ele);
void deleteNode(node ** root, int ele);
void inOrder(node * root);
void preOrder(node * root);
void postOrder(node * root);
int numberOfNodes(node * root);
node * findMin(node * root);
node * findMax(node * root);
node * search(node * root, int ele);
node * findSuccessor(node * root);
node * findPredecessor(node * root);
