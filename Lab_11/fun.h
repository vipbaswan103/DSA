#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
	char * key;
	struct node * next;
	struct node * child;
} Node;

void insert(Node * root, char * name, char * ip);
Node * createTree();
void readData(FILE * fp, Node * root);
void printDFS(Node * root);
void printLevel(Node * root);
void lookUp(Node * root, char * name);
