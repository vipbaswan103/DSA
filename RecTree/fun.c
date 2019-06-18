#include "fun.h"

Node * insert(Node * root, int ele)
{
	if(root==NULL)
	{
		Node * newNode=(Node *)malloc(sizeof(Node));
		newNode->ele=ele;
		newNode->left=NULL;
		newNode->right=NULL;
		return newNode;
	}

	if(ele <= root->ele)
	{
		root->left=insert(root->left,ele);
		return root;
	}
	else
	{
		root->right=insert(root->right,ele);
		return root;
	}
}

Node * min(Node * root)
{
	if(root->left==NULL)
		return root;
	return min(root->left);
}
Node * delete(Node * root, int ele)
{
	if(root->ele==ele)
	{
		if(root->left==NULL && root->right==NULL)
		{
			free(root);
			return NULL;
		}	
		if(root->left==NULL || root->right==NULL)
		{
			if(root->left==NULL)
				return root->right;
			else
				return root->left;
		}

		Node * succ=root->right;
		Node * p=root;
		while(succ->left!=NULL)
		{
			p=succ;
			succ=succ->left;
		}
		int tmp;
		tmp=root->ele;
		root->ele=succ->ele;
		succ->ele=tmp;
		
		if(p->left==succ)
			p->left=delete(succ,succ->ele);
		else
			p->right=delete(succ,succ->ele);
		return p;
	}
	if(ele <=root->ele)
	{
		root->left=delete(root->left, ele);
		return root;
	}
	else
	{
		root->right=delete(root->right, ele);
		return root;
	}
}
void inOrder(Node * root)
{
	if(root==NULL)
		return;

	inOrder(root->left);
	printf("%d ",root->ele);
	inOrder(root->right);
}
