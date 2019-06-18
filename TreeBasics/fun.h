#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int ele;
	struct node * left;
	struct node * right;
	struct node * parent;
} Node;

typedef struct array
{
	int arr[100];
	int i;
}array;

array Array;
void insertIterative(Node ** root, int ele);
void insertRecursive(Node ** root, int ele);

void deleteIterative(Node ** root, int ele);
void deleteRecursive(Node ** root, int ele);

void inOrder(Node * root);
Node * parentIterative(Node * root, Node * key);
Node * parentRecursive(Node * root, Node * key);
Node * findIterative(Node * root, int ele);
Node * findRecursive(Node * root, int ele);
Node * successor(Node * root, int ele);
Node * predecessor(Node * root, int ele);
void deleteIterative(Node ** root, int ele);
Node * LCA(Node * root, int n1, int n2);
int count(Node * root);
int maxDepth(Node * root);
int hasPathSum(Node * root, int ele);
int sameTree(Node * , Node *);
void makeArray(Node * root);
