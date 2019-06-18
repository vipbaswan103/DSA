#include "tree.h"
int findHeight(Node * root)
{
	if(root==NULL)
		return -1;
	if(root->left==NULL && root->right==NULL)
		return 0;
	if(root->left==NULL)
		return findHeight(root->right)+1;
	if(root->right==NULL)
		return findHeight(root->left)+1;
		
	if(findHeight(root->left)>=findHeight(root->right))
		return (1 + findHeight(root->left));
	else
		return (1 + findHeight(root->right));
}

void add(Node ** root, int ele)
{
	if((*root)==NULL)
	{
		Node * newNode=(Node *)malloc(sizeof(Node));
		newNode->left=NULL;
		newNode->right=NULL;
		newNode->ele=ele;
		newNode->hb=0;
		*root=newNode;

		int l=findHeight((*root)->left);
		int r=findHeight((*root)->right);
		if(l>r)
			(*root)->hb=-1;
		else if(l<r)
			(*root)->hb=1;
		else if(l==r)
			(*root)->hb=0;
		return;
	}
	if(ele<=(*root)->ele)
	{
		if((*root)->left==NULL)
		{
			Node * newNode=(Node *)malloc(sizeof(Node));
			newNode->left=NULL;
			newNode->right=NULL;
			newNode->ele=ele;
			newNode->hb=0;		
			(*root)->left=newNode;
			int l=findHeight((*root)->left);
			int r=findHeight((*root)->right);
		
			if(l>r)
				(*root)->hb=-1;
			else if(l<r)
				(*root)->hb=1;
			else if(l==r)
				(*root)->hb=0;
			return;
		}
		else
		{
			add(&((*root)->left),ele);
			int l=findHeight((*root)->left);
			int r=findHeight((*root)->right);
		
			if(l>r)
				(*root)->hb=-1;
			else if(l<r)
				(*root)->hb=1;
			else if(l==r)
				(*root)->hb=0;
		}
	}
	else
	{
		if((*root)->right==NULL)
		{	
			Node * newNode=(Node *)malloc(sizeof(Node));
			newNode->left=NULL;
			newNode->right=NULL;
			newNode->ele=ele;
			newNode->hb=0;		
			(*root)->right=newNode;
			int l=findHeight((*root)->left);
			int r=findHeight((*root)->right);
		
			if(l>r)
				(*root)->hb=-1;
			else if(l<r)
				(*root)->hb=1;
			else if(l==r)
				(*root)->hb=0;
			return;
		}
		else
		{
			add(&((*root)->right),ele);
			int l=findHeight((*root)->left);
			int r=findHeight((*root)->right);
		
			if(l>r)
				(*root)->hb=-1;
			else if(l<r)
				(*root)->hb=1;
			else if(l==r)
				(*root)->hb=0;
		}
	}
}
void addBalanced(Node ** root, int ele)
{
	if((*root)==NULL)
	{
		Node * newNode=(Node *)malloc(sizeof(Node));
		newNode->left=NULL;
		newNode->right=NULL;
		newNode->ele=ele;
		newNode->hb=0;
		*root=newNode;

		int l=findHeight((*root)->left);
		int r=findHeight((*root)->right);
		if(l>r)
			(*root)->hb=-1;
		else if(l<r)
			(*root)->hb=1;
		else if(l==r)
			(*root)->hb=0;
		return;
	}
	if(ele<=(*root)->ele)
	{
		if((*root)->left==NULL)
		{
			Node * newNode=(Node *)malloc(sizeof(Node));
			newNode->left=NULL;
			newNode->right=NULL;
			newNode->ele=ele;
			newNode->hb=0;		
			(*root)->left=newNode;
			int l=findHeight((*root)->left);
			int r=findHeight((*root)->right);
			printf("Case 1: Ret %d l=%d r=%d\n",(*root)->ele,l,r);
			Node *x, *y, *z;
			if(abs(l-r)>1)
			{
				if((*root)->left!=NULL && (*root)->left->left!=NULL && (*root)->left->left->ele==ele)
				{
					printf("HERE\n");
					x=(*root);
					y=(*root)->left;
					z=(*root)->left->left;
				}
				else if((*root)->right!=NULL && (*root)->right->right!=NULL && (*root)->right->right->ele==ele)
				{
					x=(*root);
					y=(*root)->right;
					z=(*root)->right->right;
				}
				else if((*root)->right!=NULL && (*root)->right->left!=NULL && (*root)->right->left->ele==ele)
				{
					x=(*root);
					y=(*root)->right;
					z=(*root)->right->left;
				}
				else if((*root)->left!=NULL && (*root)->left->right!=NULL && (*root)->left->right->ele==ele)
				{
					x=(*root);
					y=(*root)->left;
					z=(*root)->left->right;
				}
				rotate((*root),x,y,z);
			}
			l=findHeight((*root)->left);
			r=findHeight((*root)->right);
			if(l>r)
				(*root)->hb=-1;
			else if(l<r)
				(*root)->hb=1;
			else if(l==r)
				(*root)->hb=0;
			return;
		}
		else
		{
			addBalanced(&((*root)->left),ele);
			int l=findHeight((*root)->left);
			int r=findHeight((*root)->right);
			printf("Case 2: Ret %d l=%d r=%d\n",(*root)->ele,l,r);
			Node *x, *y, *z;
			if(abs(l-r)>1)
			{
				if((*root)->left!=NULL && (*root)->left->left!=NULL && (*root)->left->left->ele==ele)
				{
					x=(*root);
					y=(*root)->left;
					z=(*root)->left->left;
				}
				else if((*root)->right!=NULL && (*root)->right->right!=NULL && (*root)->right->right->ele==ele)
				{
					x=(*root);
					y=(*root)->right;
					z=(*root)->right->right;
				}
				else if((*root)->right!=NULL && (*root)->right->left!=NULL && (*root)->right->left->ele==ele)
				{
					x=(*root);
					y=(*root)->right;
					z=(*root)->right->left;
				}
				else if((*root)->left!=NULL && (*root)->left->right!=NULL && (*root)->left->right->ele==ele)
				{
					x=(*root);
					y=(*root)->left;
					z=(*root)->left->right;
				}
				rotate((*root),x,y,z);
			}
			l=findHeight((*root)->left);
			r=findHeight((*root)->right);
			if(l>r)
				(*root)->hb=-1;
			else if(l<r)
				(*root)->hb=1;
			else if(l==r)
				(*root)->hb=0;
			return;
		}
	}
	else
	{
		if((*root)->right==NULL)
		{	
			Node * newNode=(Node *)malloc(sizeof(Node));
			newNode->left=NULL;
			newNode->right=NULL;
			newNode->ele=ele;
			newNode->hb=0;		
			(*root)->right=newNode;
			int l=findHeight((*root)->left);
			int r=findHeight((*root)->right);
			printf("Ret %d l=%d r=%d\n",(*root)->ele,l,r);
			Node *x, *y, *z;
			if(abs(l-r)>1)
			{
				if((*root)->left!=NULL && (*root)->left->left!=NULL && (*root)->left->left->ele==ele)
				{
					x=(*root);
					y=(*root)->left;
					z=(*root)->left->left;
				}
				else if((*root)->right!=NULL && (*root)->right->right!=NULL && (*root)->right->right->ele==ele)
				{
					x=(*root);
					y=(*root)->right;
					z=(*root)->right->right;
				}
				else if((*root)->right!=NULL && (*root)->right->left!=NULL && (*root)->right->left->ele==ele)
				{
					x=(*root);
					y=(*root)->right;
					z=(*root)->right->left;
				}
				else if((*root)->left!=NULL && (*root)->left->right!=NULL && (*root)->left->right->ele==ele)
				{
					x=(*root);
					y=(*root)->left;
					z=(*root)->left->right;
				}
				rotate((*root),x,y,z);
			}
			l=findHeight((*root)->left);
			r=findHeight((*root)->right);
			if(l>r)
				(*root)->hb=-1;
			else if(l<r)
				(*root)->hb=1;
			else if(l==r)
				(*root)->hb=0;
			return;
		}
		else
		{
			addBalanced(&((*root)->right),ele);
			int l=findHeight((*root)->left);
			int r=findHeight((*root)->right);
			printf("Ret %d l=%d r=%d\n",(*root)->ele,l,r);
			Node *x, *y, *z;
			if(abs(l-r)>1)
			{
				if((*root)->left!=NULL && (*root)->left->left!=NULL && (*root)->left->left->ele==ele)
				{
					x=(*root);
					y=(*root)->left;
					z=(*root)->left->left;
				}
				else if((*root)->right!=NULL && (*root)->right->right!=NULL && (*root)->right->right->ele==ele)
				{
					x=(*root);
					y=(*root)->right;
					z=(*root)->right->right;
				}
				else if((*root)->right!=NULL && (*root)->right->left!=NULL && (*root)->right->left->ele==ele)
				{
					x=(*root);
					y=(*root)->right;
					z=(*root)->right->left;
				}
				else if((*root)->left!=NULL && (*root)->left->right!=NULL && (*root)->left->right->ele==ele)
				{
					x=(*root);
					y=(*root)->left;
					z=(*root)->left->right;
				}
				rotate((*root),x,y,z);
			}
			l=findHeight((*root)->left);
			r=findHeight((*root)->right);
			if(l>r)
				(*root)->hb=-1;
			else if(l<r)
				(*root)->hb=1;
			else if(l==r)
				(*root)->hb=0;
			return;
		}
	}
}
Node * findRecursive(Node * root, int ele)
{
	if(root->ele==ele)	//ele is found at root
	{
		return root;
	}
	if(root==NULL)		//ele is not found
		return NULL;
	
	if(ele<root->ele)	//if ele lies to the left of root
	{
		return findRecursive(root->left,ele);
	}
	if(ele>root->ele)			// if ele lies to the right of root
	{
		return findRecursive(root->right,ele);
	}
}

Node * findIterative(Node * root, int ele)
{
	Node * tmp=root;
	
	while(tmp!=NULL)
	{
		if(tmp->ele==ele)	//ele found
			return tmp;
		if(ele<=tmp->ele)	
			tmp=tmp->left;
		else
			tmp=tmp->right;
	}
	return NULL;		//ele not found
}

void delete(Node * root, int ele)
{
	if(root==NULL)
		return;
	Node * parent;
	Node * save;
	int flag=0;
	if(root->left!=NULL && root->left->ele==ele)
	{
		parent=root;
		flag=1;
	}
	if(root->right!=NULL && root->right->ele==ele)
	{
		parent=root;
		flag=-1;
	}
	if(flag==1)
	{
		save=root;
		root=root->left;
	}
	if(flag==-1)
	{
		save=root;
		root=root->right;
	}
	
	if(root->ele==ele)	//element is found at *root
	{
		//case 1
		if(root->left==NULL && root->right==NULL)		//its a leaf node
		{
			if(parent->left!=NULL && ((parent->left)->ele)==ele)	//its left child of its parent
				parent->left=NULL;
			else
				parent->right=NULL;
			
			int l=findHeight(parent->left);
			int r=findHeight(parent->right);

			//printf("%d\n",parent->ele);
			if(l>r)
				parent->hb=-1;
			else if(l<r)
				parent->hb=1;
			else if(l==r)
				parent->hb=0;
			
			return;		//recusrively proceed upwards
		}

		//case 2
		if(root->left==NULL || root->right==NULL)
		{
			if(root->left==NULL)
			{
				if(parent->left->ele==ele)
					parent->left=root->right;
				else
					parent->right=root->right;
			}
			else
			{
				if(parent->left->ele==ele)
					parent->left=root->left;
				else
					parent->right=root->left;
			}

			int l=findHeight(parent->left);
			int r=findHeight(parent->right);

			if(l>r)
				parent->hb=-1;
			else if(l<r)
				parent->hb=1;
			else if(l==r)
				parent->hb=0;
			
			return;
		}
		Node * succ, *p, *sp;
		succ=root->right;
		p=root;
		sp=save;
		//printf("\n%d\n",succ->ele);
		while(succ->left!=NULL)
		{
			sp=p;
			p=succ;
			succ=succ->right;
		}
		printf("\n%d\t%d\n",succ->ele,p->ele);
		int tmp;
		tmp=root->ele;
		root->ele=succ->ele;
		succ->ele=tmp;
		
		delete(p,ele);
		int l=findHeight(sp->left);
		int r=findHeight(sp->right);

		if(l>r)
			sp->hb=-1;
		else if(l<r)
			sp->hb=1;
		else if(l==r)
			sp->hb=0;
		return;
	}
	if(ele < root->ele)
	{
		delete(root->left, ele);

		Node * tmp=root;
		int l=findHeight(tmp->left);
		int r=findHeight(tmp->right);

		if(l>r)
			tmp->hb=-1;
		else if(l<r)
			tmp->hb=1;
		else if(l==r)
			tmp->hb=0;
		return;
	}
	else
	{
		delete(root->right, ele);
			
		Node * tmp=root; 
		int l=findHeight(tmp->left);
		int r=findHeight(tmp->right);

		if(l>r)
			tmp->hb=-1;
		else if(l<r)
			tmp->hb=1;
		else if(l==r)
			tmp->hb=0;
		return;
	}
}

Node * rotate(Node * root, Node * x, Node * y,  Node * z)
{
	Node * t0, *t1, *t2, *t3;

	int flag=0;
	if(x->left==y && y->left==z)
		flag=1;
	if(x->left==y && y->right==z)
	{
		flag=1;
		t0=y->left;
		t1=z->left;
		t2=z->right;
		x->left=z;
		z->left=y;
		y->right=t1;
	}
	if(x->right==y && y->right==z)
		flag=2;
	if(x->right==y && y->left==z)
	{
		flag=2;
		t0=y->right;
		t1=z->right;
		t2=z->left;
		x->right=z;
		z->right=y;
		y->left=t1;
	}
	
	Node * p=parent(root,x->ele);
	if(flag==1)
	{
		t0=x->right;
		t1=y->right;
		t2=z->right;
		t2=z->left;
		if(p==NULL)
		{
			y->right=x;
			x->left=t1;
			return y;
		}
		if(p->left==x)
		{
			p->left=y;
			y->right=x;
			x->left=t1;
		}
		else
		{
			p->right=y;
			y->right=x;
			x->left=t1;
		}
	}
	else
	{
		t0=x->left;
		t1=y->left;
		t2=z->left;
		t3=z->right;

		if(p==NULL)
		{
			y->left=x;
			x->right=t1;
			return y;
		}
		if(p->left==x)
		{
			p->left=y;
			y->left=x;
			x->right=t1;
		}
		else
		{
			p->right=y;
			y->left=x;
			x->right=t1;
		}
	}
	return root;
}
Node * findSuccessor(Node * root, Node * key)
{
	if(key==NULL)
		return NULL;
	if(key->right!=NULL)
	{
		Node * m=min(key->right);
		return m;
	}	

	Node *x=key;
	Node * z=parent(root, x->ele);

	while(z!=NULL && x==z->right)	//until you reach root or x isn't the  right child of its parent
	{
		x=z;
		z=parent(root,x->ele);
	}
	return z;
}	

Node * parent(Node * root, int ele)
{
	if(root==NULL)
		return NULL;
	if(root->ele==ele)
		return NULL;
	if(root->left!=NULL && root->left->ele==ele)
		return root;
	if(root->right!=NULL && root->right->ele==ele)
		return root;

	if(ele < root->ele)
		return parent(root->left,ele);
	else
		return parent(root->right,ele);
}
Node * min(Node * root)
{
	if(root==NULL)
		return NULL;

	if(root->left==NULL)
		return root;

	return min(root->left);
}
void inOrder(Node * root)
{
	if(root==NULL)
		return;
	
	inOrder(root->left);
	printf("%d %d\n",root->ele,root->hb);
	inOrder(root->right);
}
void preOrder(Node * root)
{
	if(root==NULL)
		return;

	printf("%d %d\n",root->ele,root->hb);
	preOrder(root->left);
	preOrder(root->right);
}
