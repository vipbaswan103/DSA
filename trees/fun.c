#include "fun.h"

void insert(node ** root, int ele)
{
	node * tmp=*root;
	node * newNode=(node *)malloc(sizeof(node));
	if(tmp==NULL)
	{
		newNode->ele=ele;
		newNode->left=NULL;
		newNode->right=NULL;
		newNode->parent=NULL;
		*root=newNode;
		return;
	}
	newNode->left=NULL;
	newNode->right=NULL;
	while(tmp!=NULL)
	{
		if(ele<=tmp->ele)
		{
			if(tmp->left==NULL)
			{
				tmp->left=newNode;
				newNode->parent=tmp;
				newNode->ele=ele;
				return;	
			}
			tmp=tmp->left;
		}
		else
		{
			if(tmp->right==NULL)
			{
				tmp->right=newNode;
				newNode->parent=tmp;
				newNode->ele=ele;
				return;
			}
			tmp=tmp->right;
		}
	}
}

void inOrder(node * root)
{
	if(root==NULL)
		return;
	inOrder(root->left);
	printf("%d ",root->ele);
	inOrder(root->right);
}

node * findMin(node * root)
{
	if(root->left==NULL)
		return root;
	findMin(root->left);
}

node * findMax(node * root)
{
	if(root->right==NULL)
		return root;
	findMax(root->right);
}

node * search(node * root, int ele)
{
	if(root==NULL || ele==root->ele)
	{
		if(root==NULL)
			return NULL;
		else
			return root;
	}
	if(ele<=root->ele)
	{
		return search(root->left,ele);
	}
	else
	{
		return search(root->right,ele);
	}
}
void preOrder(node * root)
{
	if(root!=NULL)
	{
		printf("%d ",root->ele);
		preOrder(root->left);
		preOrder(root->right);
	}
}
void postOrder(node * root)
{
	if(root!=NULL)
	{
		postOrder(root->left);
		postOrder(root->right);
		printf("%d ",root->ele);
	}
}

node * findSuccessor(node * tree)
{
	if(tree->right!=NULL)
	{
		node * x=findMin(tree->right);
		return x;
	}
	node * p=tree->parent;
	int flag=0;
	while(p!=NULL && tree==p->right)
	{
		flag=1;
		tree=p;
		p=p->parent;
	}
	if(flag==1 && p==NULL)
	{
		printf("It is itself the max element\n");
		return NULL;
	}
	return p;
}

node* findPredecessor(node * tree)
{
	if(tree->left!=NULL)
	{
		node * x=findMax(tree->left);
		return x;
	}
	node * p=tree->parent;
	int flag=0;
	while(p!=NULL && tree==p->left)
	{
		flag=1;
		tree=p;
		p=p->parent;
	}
	if(flag==1 && p==NULL)
	{
		printf("It is itself the min element of the tree\n");
		return NULL;
	}
	return p;
}

void deleteNode(node ** head, int key)
{
	node * tmp=search(*head, key);
	if(tmp!=NULL)
	{
			if(tmp->left==NULL && tmp->right==NULL)
			{
				if(tmp==*head)
				{
					free(tmp);
					*head=NULL;
					return;
				}
				if(tmp->parent->left==tmp)
					tmp->parent->left=NULL;
				else
					tmp->parent->right=NULL;
				free(tmp);
				return;
			}
			if((tmp->left==NULL && tmp->right!=NULL))
			{
				if(tmp==*head)
				{
					tmp->right->parent=NULL;
					*head=tmp->right;
					free(tmp);
					return;
				}
				if(tmp->parent->left==tmp)
				{
					tmp->parent->left=tmp->right;
					tmp->right->parent=tmp->parent;
				}
				else
				{
					tmp->parent->right=tmp->right;
					tmp->right->parent=tmp->parent;
				}
				tmp->right=NULL;
				free(tmp);
				return;
			}
			if((tmp->left!=NULL && tmp->right==NULL))
			{
				if(tmp==*head)
				{
					tmp->left->parent=NULL;
					*head=tmp->left;
					free(tmp);
					return;
				}
				if(tmp->parent->left==tmp)
				{
					tmp->parent->left=tmp->left;
					tmp->left->parent=tmp->parent;
				}
				else
				{
					tmp->parent->right=tmp->left;
					tmp->left->parent=tmp->parent;
				}
				tmp->left=NULL;
				free(tmp);
				return;
			}
			if(tmp->left!=NULL && tmp->right!=NULL)
			{
				node * succ=findSuccessor(tmp);
				if(succ->left==NULL && succ->right==NULL)
				{
					if(succ->parent->right==succ)
						succ->parent->right=NULL;
					else
						succ->parent->left=NULL;
				}
				if((succ->left==NULL && succ->right!=NULL))
				{
					if(succ->parent->left==succ)
						succ->parent->left=succ->right;
					else
						succ->parent->right=succ->right;
					succ->right->parent=succ->parent;
					succ->right=NULL;
				}
				if((succ->left!=NULL && succ->right==NULL))
				{
					if(succ->parent->left==succ)
						succ->parent->left=succ->left;
					else
						succ->parent->right=succ->left;
					succ->left->parent=succ->parent;
					succ->left=NULL;
				}
			
				if(tmp!=*head && tmp->parent->right==tmp)
				{
					succ->left=tmp->left;
					succ->right=tmp->right;
					succ->parent=tmp->parent;
					tmp->parent->right=succ;
				}
				if(tmp!=*head && tmp->parent->left==tmp)
				{
					succ->left=tmp->left;
					succ->right=tmp->right;
					succ->parent=tmp->parent;
					tmp->parent->left=succ;
				}
				if(tmp==*head)
				{
					succ->left=tmp->left;
					succ->right=tmp->right;
					succ->parent=tmp->parent;
					*head=succ;
				}
				free(tmp);
				return;	
			}
	}
	printf("Error: Element not found!");
}

int numberOfNodes(node * root)
{
	static int count=0;
	if(root==NULL)
		return count;
	count++;
	printf("Before 1st %d\n",count);
	numberOfNodes(root->left);
	printf("After 1st %d\n",count);
	count++;
	printf("Before 2nd %d\n",count);
	numberOfNodes(root->right);
	printf("After 2nd %d\n",count);
}
