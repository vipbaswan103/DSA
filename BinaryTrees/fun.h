#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int key;
	struct node * left;
	struct node * right;
} Node;

void insertInTree(Node ** root, int key);
void deleteInTree(Node ** root, int key);
int size(Node * root);
void inOrder(Node * root);
void preOrder(Node * root);
void postOrder(Node * root);
int minValue(Node * root);
int maxValue(Node * root);
int hasPathSum(Node * root, int sum);
