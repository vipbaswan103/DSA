#include "fun.h"
//Array.i=0;
void insertIterative(Node ** root, int ele)
{
	Node * newNode=(Node *)malloc(sizeof(Node));
	newNode->ele=ele;
	newNode->left=NULL;
	newNode->right=NULL;

	if((*root)==NULL)
	{
		*root=newNode;
		newNode->parent=NULL;
		return;
	}

	Node * trav=*root;
	while(trav!=NULL)
	{
		if(ele<=trav->ele)
		{
			if(trav->left==NULL)
			{
				trav->left=newNode;
				newNode->parent=trav;
				return;
			}
			trav=trav->left;
		}
		else
		{
			if(trav->right==NULL)
			{
				trav->right=newNode;
				newNode->parent=trav;
				return;
			}
			trav=trav->right;
		}
	}
}

void insertRecursive(Node ** root, int ele)
{
	if(*root==NULL)
	{
		Node * newNode=(Node *)malloc(sizeof(Node));
		newNode->ele=ele;
		newNode->left=NULL;
		newNode->right=NULL;
		newNode->parent=NULL;
		*root=newNode;
		return;
	}

	if(ele<=(*root)->ele)
	{
		if((*root)->left==NULL)
		{
			Node * newNode=(Node *)malloc(sizeof(Node));
			newNode->ele=ele;
			newNode->left=NULL;
			newNode->right=NULL;
			newNode->parent=(*root);
			(*root)->left=newNode;
			return;
		}
		insertRecursive(&((*root)->left), ele);
	}
	else
	{
		if((*root)->right==NULL)
		{
			Node * newNode=(Node *)malloc(sizeof(Node));
			newNode->ele=ele;
			newNode->left=NULL;
			newNode->right=NULL;
			newNode->right=(*root);
			(*root)->right=newNode;
			return;
		}
		insertRecursive(&((*root)->right),ele);
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

void deleteIterative(Node ** root, int ele)
{
	if(*root==NULL)
		return;
	
	Node * trav=*root;
	Node * parent;
	int flag=0;
	while(trav!=NULL || flag==1)
	{
		if(ele==trav->ele)
		{
			parent=parentIterative(*root,trav);
			if(trav->left==NULL && trav->right==NULL)
			{
				if(parent==NULL)
				{
					(*root)=NULL;
					return;
				}
				if(parent->left!=NULL && parent->left->ele==ele)
					parent->left=NULL;
				else
					parent->right=NULL;
				free(trav);
				return;
			}
			if(trav->left==NULL || trav->right==NULL)
			{
				if(parent==NULL)
				{
					if(trav->left!=NULL)
						(*root)=trav->left;
					else
						(*root)=trav->right;
					(*root)->parent=NULL;
					free(trav);	
					return;
				}
				if(trav->left==NULL)
				{
					if(parent->left!=NULL && parent->left->ele==ele)
					{
						parent->left=trav->right;
					}
					else
					{
						parent->right=trav->right;
					}
					trav->right->parent=parent;
				}
				else
				{
					if(parent->left!=NULL && parent->left->ele==ele)
						parent->left=trav->left;
					else
						parent->right=trav->left;
					trav->left->parent=parent;
				}
				free(trav);
				return;
			}
			
			Node * succ=successor(*root,trav->ele);

			Node * parent=parentIterative(*root,succ);
			int tmp;
			tmp=trav->ele;
			trav->ele=succ->ele;
			succ->ele=tmp;
			
			if(succ->left==NULL && succ->right==NULL)
			{
				if(parent->left!=NULL && parent->left==succ)
					parent->left=NULL;
				else
					parent->right=NULL;
				free(succ);
				return;
			}
			if(succ->left==NULL)
			{
				if(parent->left!=NULL && parent->left==succ)
					parent->left=succ->right;
				else
					parent->right=succ->right;
				succ->right->parent=parent;	
			}
			else
			{
				if(parent->left!=NULL && parent->left==succ)
					parent->left=succ->left;
				else
					parent->right=succ->left;
				succ->left->parent=parent;
			}
			free(succ);
			return;	
		}
		if(ele<=trav->ele)
			trav=trav->left;	
		else
			trav=trav->right;
	}	
}

void deleteRecursive(Node ** root, int ele)
{	
	if((*root)==NULL)
		return;
	if((*root)->ele==ele)
	{
		Node * tmp=*root;

		Node * parent=tmp->parent;
		if(tmp->left==NULL && tmp->right==NULL)
		{
			if(tmp->parent==NULL)
			{
				free(tmp);
				(*root)=NULL;
				return;
			}
			if(parent->left==tmp)
				parent->left=NULL;
			else
				parent->right=NULL;
			free(tmp);
			return;
		}	
		
		if(tmp->left==NULL || tmp->right==NULL)
		{
			if(tmp->parent==NULL)
			{
				if(tmp->left!=NULL)
				{
					tmp->left->parent=NULL;
					*root=tmp->left;
				}
				else
				{
					tmp->right->parent=NULL;
					*root=tmp->right;
				}
				free(tmp);
				return;
			}
			if(tmp->left==NULL)
			{
				if(parent->left==tmp)
					parent->left==tmp->right;
				else
					parent->right=tmp->right;
				tmp->right->parent=parent;
			}				
			else
			{
				if(parent->left==tmp)
					parent->left=tmp->left;
				else
					parent->right=tmp->left;
				tmp->left->parent=parent;
			}
			free(tmp);
			return;
		}	
		
		Node * trav=tmp->right;
		while(trav->left!=NULL)
			trav=trav->left;
		Node * succ=trav;

		int key;
		key=tmp->ele;
		tmp->ele=succ->ele;
		succ->ele=ele;
		
		deleteRecursive(&(succ),ele);
		return;
	}
	if(ele < (*root)->ele)
		deleteRecursive(&((*root)->left),ele);
	else
		deleteRecursive(&((*root)->right),ele);
}

Node * min(Node * root)
{
	if(root==NULL)
		return NULL;
	if(root->left==NULL)
		return root;

	return min(root->left);
}

Node * minIterative(Node * root)
{
	Node * trav=root;
	if(trav->left!=NULL)
	{
		trav=trav->left;
	}
	return trav;
}

Node * max(Node * root)
{
	if(root==NULL)
		return NULL;
	if(root->right==NULL)
		return root;

	return max(root->right);
}

Node * maxIterative(Node * root)
{
	Node * trav=root;

	while(trav->right!=NULL)
		trav=trav->right;

	return trav;
}
Node * parentIterative(Node * root, Node * key)
{
	
	Node * parent=NULL;
	while(root!=NULL)
	{
		if(key->ele==root->ele)
		{
			return parent;
		}
		if(key->ele < root->ele)
		{
			parent=root;
			root=root->left;
		}
		else
		{
			parent=root;
			root=root->right;
		}
	}
	return parent;
}

Node * parentRecursive(Node * root, Node * key)
{
	if(root==NULL)
		return NULL;

	if(root->ele==key->ele)
		return NULL;

	if(root->left!=NULL && root->left->ele==key->ele)
		return root;
	if(root->right!=NULL && root->right->ele==key->ele)
		return root;

	if(key->ele < root->ele)
		return parentRecursive(root->left, key);	
	else
		return parentRecursive(root->right, key);
}

Node * successor(Node * root, int ele)
{
	Node * x=findIterative(root,ele);
	if(x->right!=NULL)
	{
		return min(x->right);
	}
	
	Node * z=parentIterative(root,x);
	while(z!=NULL && x==z->right)
	{
		x=z;
		z=parentIterative(root,x);
	}
	return z;
}

Node * predecessor(Node * root, int ele)
{
	Node * x=findRecursive(root,ele);

	if(x->left!=NULL)
	{
		return max(x->left);
	}

	Node * p=x->parent;
	
	while(p!=NULL && x==p->left)
	{
		x=p;
		p=x->parent;
	}	
	return p;
}

Node * findRecursive(Node * root, int ele)
{
	if(root==NULL)
		return NULL;
	if(root->ele==ele)
		return root;

	if(ele <= root->ele)
		return findRecursive(root->left,ele);
	else
		return findRecursive(root->right,ele);

}

Node * findIterative(Node * root, int ele)
{
	Node * trav=root;
	
	while(trav!=NULL)
	{
		if(ele==trav->ele)
			return trav;
		if(ele < trav->ele)
			trav=trav->left;
		else
			trav=trav->right;
	}	
}

Node * LCA(Node * root, int n1, int n2)
{
	if(root==NULL)
		return NULL;
	if(root->ele>=n1 && root->ele <n2)
		return root;
	if(root->ele < n1)
		return LCA(root->right,n1,n2);
	if(root->ele > n2)
		return LCA(root->left,n1,n2);	
}

int count(Node * root)
{
	if(root==NULL)
		return 0;

	return count(root->left)+count(root->right)+1;
}

int maxDepth(Node * root)
{
	if(root==NULL)
		return -1;
	int l=maxDepth(root->left);
	int r=maxDepth(root->right);

	if(l>=r)
		return 1+l;
	else
		return 1+r;
}

int hasPathSum(Node * root, int sum)
{
	int x;
	if(sum==0 && root==NULL)
		return 1;
	if(sum!=0 && root==NULL)
	{
		printf("%d\n",sum);
		return 0;
	}
	if(sum==0)
		return 0;
	x=sum-(root->ele);
	printf("x=%d\n",x);
	int flag=hasPathSum(root->left,x);

	if(flag==0)
	{
		flag=hasPathSum(root->right,x);
		if(flag==1)
			return 1;
		else
			return 0;
	}
	else
		return 1;
}

void mirror(Node * root)
{
	if(root==NULL)
		return;
	if(root->left==NULL && root->right==NULL)
	{
		return;
	}	
	mirror(root->left);
	mirror(root->right);
	if(root!=NULL)
	{
		Node * tmp=root->left;
		root->left=root->right;
		root->right=tmp;	
	}
}
void doubleTree(Node * root)
{
	if(root==NULL)
		return;
	doubleTree(root->left);
	doubleTree(root->right);
	
	Node * newNode=(Node *)malloc(sizeof(Node));
	if(root!=NULL)
	{
		newNode->left=root->left;
		newNode->right=NULL;
		newNode->ele=root->ele;
		root->left=newNode;
		newNode->parent=root;
	}	
}

int sameTree(Node * root1, Node * root2)
{
	if(root1==NULL && root2==NULL)
		return 1;
	if((root1==NULL && root2!=NULL) || (root1!=NULL && root2==NULL))
		return 0;	
	if(root1->ele==root2->ele)
	{
		int flag=sameTree(root1->left,root2->left);
		printf("f1 = %d\n",flag);
		if(flag==1)
		{
			flag=sameTree(root1->right,root2->right);
			printf("f2 = %d\n",flag);
			if(flag==1)
				return 1;
			else
				return 0;
		}
		else
			return 0;
	}
	else
		return 0;
}

/*int isBST(Node * root)
{
	if(root==NULL)
		return 1;
	
	//isBST(root->left);
	//isBST(root->right);
	Node * a=max(root->left);
	Node * b=min(root->right);
	
	if(a<=root->ele && root->ele > b)
	{
		return (isBST(root->left) && isBST(root->right));
	}
	else
		return 0;
}*/

int isBST(Node * root)
{
	if(root==NULL)
		return 1;
	
	Node * a=max(root->left);
	Node * b=min(root->right);

	if((a==NULL && b==NULL) || (a==NULL && b!=NULL) || (a!=NULL && b==NULL) || (a->ele <= root->ele && root->ele < b->ele))
	{
		int flag=isBST(root->left);
		if(flag==1)
		{
			flag=isBST(root->right);
			if(flag==1)
				return 1;
			else
				return 0;
		}	
		else
			return 0;
	}
	else
		return 0;
}

void makeArray(Node * root)
{
	
	if(root==NULL)
		return;

	makeArray(root->left);
	Array.arr[Array.i]=root->ele;
	Array.i++;
	makeArray(root->right);
}

int sumTree(Node * root)
{
	int sum=0;
	if(root==NULL)
		return 0;
	
	int x=sumTree(root->left);
	int y=sumTree(root->right);
	return (x+y+(root->ele));
}
