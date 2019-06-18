#include "tree.h"

void insertNode(node * root, int ele)
{
	node * nptr=(node *) malloc(sizeof(node));
	if(root->left==NULL and root->right==NULL)
	{
		root->left=nptr;
		nptr->left=NULL;
		nptr->right=NULL;
		nptr->ele=ele;
		root->ele++;
		return ;
	}

	node * ptr=root->left;

}
