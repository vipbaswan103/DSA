#include <stdio.h>
#include<stdlib.h>

typedef struct node
{
	int ele;
	struct node * left;
	struct node * right;
	int hb:2;
} Node;

typedef struct range
{
	int arr[100];
	int index;
}range;

range Range;
Node * add(Node * root, int ele);
Node * addBalanced(Node * root, int ele);
Node * findRecursive(Node * root, int ele);
Node * findIterative(Node * root, int ele);
void inOrder(Node * root);
void preOrder(Node * root);
Node * parent(Node * root, int ele);
Node * findSuccessor(Node * root, Node * key);
Node * min(Node * root);
Node * delete(Node * root, int ele);
void deleteBalanced(Node * root, Node * TreeRoot, int ele);
Node * rotate(Node *root, Node * x, Node * y, Node *z);
void rankQuery(Node * root, int * k);
void rangeQuery(Node * root, int k1, int k2);
