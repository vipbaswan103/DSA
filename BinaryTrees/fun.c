#include "fun.h"

void insertInTree(Node ** root, int key)
{
	Node * leaf=(Node *)malloc(sizeof(Node));
	leaf->key=key;
	leaf->left=NULL;
	leaf->right=NULL;
	if(*root==NULL)	/*insert the new key as the root of the tree*/
	{
		*root=leaf;
		return;	
	}
	
	Node * trav=*root;
	while(trav!=NULL)
	{
		if(key<=trav->key)
		{
			if(trav->left==NULL)
			{
				trav->left=leaf;
				return;				
			}
			trav=trav->left;
		}
		else
		{
			if(trav->right==NULL)
			{
				trav->right=leaf;
				return;
			}
			trav=trav->right;
		}
	}
}

int size(Node * root)
{
	if(root==NULL)
		return 0;
	
	return size(root->left)+1+size(root->right);
}
int maxDepth(Node * root)
{
	Node * trav=root;
	int count=0;
	while(trav->left!=NULL && trav->right!=NULL)
	{
		count++;
	}	
}
void inOrder(Node * root)
{
	if(root==NULL)
		return;
	inOrder(root->left);
	printf("%d ",root->key);
	inOrder(root->right);
}
void postOrder(Node * root)
{
	if(root==NULL)
		return;
	postOrder(root->left);
	postOrder(root->right);
	printf("%d ",root->key);
}
void preOrder(Node * root)
{
	if(root==NULL)
		return;
	printf("%d ",root->key);
	preOrder(root->left);
	preOrder(root->right);
}
int minValue(Node * root)
{
	if(root->left==NULL)
		return root->key;
	minValue(root->left);
}
int maxValue(Node * root)
{
	if(root->right==NULL)
		return root->key;
	maxValue(root->right);
}
int hasPathSum(Node * root, int sum)
{
	if(root==NULL)
		return 0;
	if(root->left==NULL && root->right==NULL)
		return root->key;
	
	int x=(root->key+hasPathSum(root->left,sum));
	int y=(root->key+hasPathSum(root->right,sum));
}
void printPaths(Node * root)
{
	if(root==NULL)
		return;
	printf("%d ",root->key);
	printPaths(root->left);
	printf("\n");

}
