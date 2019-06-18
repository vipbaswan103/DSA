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

void bFactor(Node * root)
{
	int l=findHeight(root->left);
	int r=findHeight(root->right);
	if(l>r)
		root->hb=-1;
	else if(l<r)
		root->hb=1;
	else if(l==r)
		root->hb=0;
}
Node * add(Node * root, int ele)
{
	if(root==NULL)
	{
		Node * newNode=(Node *)malloc(sizeof(Node));
		newNode->left=NULL;
		newNode->right=NULL;
		newNode->ele=ele;
		newNode->hb=0;
		root=newNode;
		int l=findHeight(root->left);
		int r=findHeight(root->right);
		bFactor(root);
		return root;
	}
	if(ele<=root->ele)
	{
		root->left=add(root->left,ele);
		bFactor(root);
		return root;	
	}
	else
	{
		root->right=add(root->right,ele);
		bFactor(root);
		return root;
	}
}
int assignXYZ(Node * root, Node ** a, Node ** b, Node ** c, int ele, int sig)
{
	
	int l=findHeight(root->left);
	int r=findHeight(root->right);
	Node *x, *y, *z;
	if(abs(l-r)>1)
	{
		if(root->left!=NULL && root->left->left!=NULL )//&& root->left->left->ele==ele)
		{
			x=root;
			y=root->left;
			z=root->left->left;
		}
		else if(root->right!=NULL && root->right->right!=NULL )//&& root->right->right->ele==ele)
		{
			x=root;
			y=root->right;
			z=root->right->right;
		}
		else if(root->right!=NULL && root->right->left!=NULL )//&& root->right->left->ele==ele)
		{
			x=root;
			y=root->right;
			z=root->right->left;
		}
		else if(root->left!=NULL && root->left->right!=NULL )//&& root->left->right->ele==ele)
		{
			x=root;
			y=root->left;
			z=root->left->right;
		}
		printf("%d %d %d\n",x->ele,y->ele,z->ele);
		*a=x;
		*b=y;
		*c=z;
		return 1;
	}
	else
		return 0;
	
}
Node * addBalanced(Node * root, int ele)
{
	if(root==NULL)
	{
		Node * newNode=(Node *)malloc(sizeof(Node));
		newNode->left=NULL;
		newNode->right=NULL;
		newNode->ele=ele;
		newNode->hb=0;
		bFactor(newNode);
		return newNode;
	}
	if(ele<=root->ele)
	{
			root->left=addBalanced(root->left,ele);		//root is the parent of the newly inserted node
			Node *x, *y, *z;
			int k=assignXYZ(root,&x,&y,&z,ele,0);
			if(k==1)
			{
				Node *p= rotate(root,x,y,z);
				bFactor(p);
				return p;
			}
			bFactor(root);
			return root;
	}
	else
	{
			root->right=addBalanced(root->right,ele);
			Node *x, *y, *z;
			int k=assignXYZ(root,&x,&y,&z,ele,1);
			if(k==1)
			{
				//printf("RIGTH %d %d %d",x->ele,y->ele,z->ele);
				Node *p= rotate(root,x,y,z);
				bFactor(p);
				return p;
			}
			bFactor(root);
			return root;
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

/*void deleteBalanced(Node * root, Node * TreeRoot,  int ele)
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
			if(abs(l-r)>1)
			{
				Node *x, *y, *z;
				if(parent->left!=NULL && parent->left->left!=NULL)
				{
					x=parent;
					y=parent->left;
					z=parent->left->left;
				}
				else if(parent->right!=NULL && parent->right->right!=NULL)
				{
					x=parent;
					y=parent->right;
					z=parent->right->right;
				}
				else if(parent->right!=NULL && parent->right->left!=NULL)
				{
					x=parent;
					y=parent->right;
					z=parent->right->left;
				}
				else if(parent->left!=NULL && parent->left->right!=NULL)
				{
					x=parent;
					y=parent->left;
					z=parent->left->right;
				}
				TreeRoot=rotate(TreeRoot,x,y,z);
			}
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
			if(abs(l-r)>1)
			{
				Node *x, *y, *z;
				if(parent->left!=NULL && parent->left->left!=NULL)
				{
					x=parent;
					y=parent->left;
					z=parent->left->left;
				}
				else if(parent->right!=NULL && parent->right->right!=NULL)
				{
					x=parent;
					y=parent->right;
					z=parent->right->right;
				}
				else if(parent->right!=NULL && parent->right->left!=NULL)
				{
					x=parent;
					y=parent->right;
					z=parent->right->left;
				}
				else if(parent->left!=NULL && parent->left->right!=NULL)
				{
					x=parent;
					y=parent->left;
					z=parent->left->right;
				}
				TreeRoot=rotate(TreeRoot,x,y,z);
			}

			l=findHeight(parent->left);
			r=findHeight(parent->right);
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
		//printf("\n%d\t%d\n",succ->ele,p->ele);
		int tmp;
		tmp=root->ele;
		root->ele=succ->ele;
		succ->ele=tmp;
		
		deleteBalanced(p,TreeRoot,ele);
		int l=findHeight(sp->left);
		int r=findHeight(sp->right);

		if(abs(l-r)>1)
		{
				Node *x, *y, *z;
				if(sp->left!=NULL && sp->left->left!=NULL)
				{
					x=sp;
					y=sp->left;
					z=sp->left->left;
				}
				else if(sp->right!=NULL && sp->right->right!=NULL)
				{
					x=sp;
					y=sp->right;
					z=sp->right->right;
				}
				else if(sp->right!=NULL && sp->right->left!=NULL)
				{
					x=sp;
					y=sp->right;
					z=sp->right->left;
				}
				else if(sp->left!=NULL && sp->left->right!=NULL)
				{
					x=sp;
					y=sp->left;
					z=sp->left->right;
				}
				TreeRoot=rotate(TreeRoot,x,y,z);
		}
		l=findHeight(sp->left);
		r=findHeight(sp->right);
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
		deleteBalanced(root->left,TreeRoot, ele);

		Node * tmp=root;
		int l=findHeight(tmp->left);
		int r=findHeight(tmp->right);
			if(abs(l-r)>1)
			{
				Node *x, *y, *z;
				if(root->left!=NULL && root->left->left!=NULL)
				{
					x=root;
					y=root->left;
					z=root->left->left;
				}
				else if(root->right!=NULL && root->right->right!=NULL)
				{
					x=root;
					y=root->right;
					z=root->right->right;
				}
				else if(root->right!=NULL && root->right->left!=NULL)
				{
					x=root;
					y=root->right;
					z=root->right->left;
				}
				else if(root->left!=NULL && root->left->right!=NULL)
				{
					x=root;
					y=root->left;
					z=root->left->right;
				}
				TreeRoot=rotate(TreeRoot,x,y,z);
			}
		l=findHeight(tmp->left);
		r=findHeight(tmp->right);
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
		deleteBalanced(root->right,TreeRoot, ele);
			
		Node * tmp=root; 
		int l=findHeight(tmp->left);
		int r=findHeight(tmp->right);
			if(abs(l-r)>1)
			{
				Node *x, *y, *z;
				if(root->left!=NULL && root->left->left!=NULL)
				{
					x=root;
					y=root->left;
					z=root->left->left;
				}
				else if(root->right!=NULL && root->right->right!=NULL)
				{
					x=root;
					y=root->right;
					z=root->right->right;
				}
				else if(root->right!=NULL && root->right->left!=NULL)
				{
					x=root;
					y=root->right;
					z=root->right->left;
				}
				else if(root->left!=NULL && root->left->right!=NULL)
				{
					x=root;
					y=root->left;
					z=root->left->right;
				}
				TreeRoot=rotate(TreeRoot,x,y,z);
			}
		l=findHeight(tmp->left);
		r=findHeight(tmp->right);
		if(l>r)
			tmp->hb=-1;
		else if(l<r)
			tmp->hb=1;
		else if(l==r)
			tmp->hb=0;
		return;
	}
}*/

Node * rotate(Node * root, Node * x, Node * y,  Node * z)
{
	Node * t0, *t1, *t2, *t3;

	//printf("\nROT %d %d %d \n",x->ele,y->ele,z->ele);
	int flag=0;
	if(x->left==y && y->left==z)
		flag=1;
	if(x->left==y && y->right==z)
		flag=2;
	if(x->right==y && y->right==z)
		flag=4;
	if(x->right==y && y->left==z)
		flag=3;
		
	//Node * p=parent(root,x->ele);
	
	if(flag==1)
	{
		t0=x->right;
		t1=y->right;
		t2=z->right;
		t3=z->left;
		/*if(p==NULL)
		{
			y->right=x;
			x->left=t1;
			bFactor(z);	
			bFactor(x);
			bFactor(y);	
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
		}*/
		int tmp;
		tmp=x->ele;
		x->ele=y->ele;
		y->ele=tmp;
		x->left=y->left;
		x->right=y;
		y->left=t0;

		bFactor(z);
		bFactor(y);
		bFactor(x);	
	}
	if(flag==4)
	{
		t0=x->left;
		t1=y->left;
		t2=z->left;
		t3=z->right;

		/*if(p==NULL)
		{
			y->left=x;
			x->right=t1;
			bFactor(z);
			bFactor(x);
			bFactor(y);
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
		}*/

		int tmp=x->ele;
		x->ele=y->ele;
		y->ele=tmp;

		x->right=y->right;
		x->left=y;
		y->left=t0;
		y->right=t1;

		bFactor(y);
		bFactor(z);
		bFactor(x);
	}
	if(flag==3)
	{
		t0=y->right;
		t1=z->right;
		t2=z->left;
		x->right=z;
		z->right=y;
		y->left=t1;
		t3=x->left;
		
		/*if(p==NULL)
		{
			z->left=x;
			x->right=t2;
			bFactor(x);
			bFactor(y);
			bFactor(z);	
			return z;
		}
		if(p->right==x)
		{
			p->right=z;
			x->right=t2;
			z->left=x;
		}
		else
		{
			p->left=z;
			x->right=t2;
			z->left=x;
		}*/

		int tmp=z->ele;
		z->ele=x->ele;
		x->ele=tmp;

		x->right=z->right;
		x->left=z;
		z->left=t3;
		z->right=t2;

		bFactor(z);
		bFactor(y);
		bFactor(x);	
	}
	if(flag==2)
	{
		t0=y->left;
		t1=z->left;
		t2=z->right;
		x->left=z;
		z->left=y;
		y->right=t1;
		t3=x->right;

		/*if(p==NULL)
		{
			z->right=x;
			x->left=t2;
			bFactor(x);
			bFactor(y);
			bFactor(z);	
			return z;
		}
		if(p->left==x)
		{
			p->left=z;
			z->right=x;
			x->left=t3;
		}
		else
		{
			p->right=z;
			z->right=x;
			x->left=t3;
		}*/

		int tmp=x->ele;
		x->ele=z->ele;
		z->ele=tmp;

		x->left=z->left;
		x->right=z;
		z->left=t2;
		z->right=t3;
		bFactor(z);
		bFactor(y);
		bFactor(x);	
	}
	return root;
}

Node * delete(Node * root, int ele)
{
	if(root->ele==ele)	//element is found at *root
	{
		//case 1
		if(root->left==NULL && root->right==NULL)		//its a leaf node
		{
			free(root);
			return NULL; //recusrively proceed upwards
		}

		//case 2
		if(root->left==NULL || root->right==NULL)
		{
			if(root->left==NULL)
			{
				free(root);
				return root->right;
			}
			else
			{
				free(root);
				return root->left;
			}
		}
		Node * succ, *p;
		succ=root->right;
		p=root;
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
		bFactor(p);
		return root;
	}
	if(ele < root->ele)
	{
		root->left=delete(root->left, ele);
		Node *x, *y, *z;
		int sig=assignXYZ(root,&x,&y,&z,ele,0);
		if(sig==1)
		{
			Node *p=rotate(root,x,y,z);
			bFactor(p);
			return p;
		}		
		bFactor(root);
		return root;
	}
	else
	{
		root->right=delete(root->right, ele);
		Node *x, *y, *z;
		int sig=assignXYZ(root,&x,&y,&z,ele,1);
		if(sig==1)
		{
			Node *p=rotate(root,x,y,z);
			bFactor(p);
			return p;
		}		
		bFactor(root);
		return root;
	}
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

void rankQuery(Node * root, int * k)
{
	if(root==NULL || *k<0)
		return;
	rankQuery(root->left,k);
	(*k)--;
	//printf("%d\n",*k);
	if(*k==0)
	{
		printf("%d\n",root->ele);
		return;
	}
	//printf("%d\n",*k);
	rankQuery(root->right,k);
}

void rangeQuery(Node * root, int k1, int k2)
{
	if(root==NULL)
		return;
	if(root->ele > k2)
		rangeQuery(root->left,k1,k2);	
	if(root->ele <k1)
		rangeQuery(root->right,k1,k2);
	
	if(root->ele>=k1 && root->ele<=k2)
	{
		rangeQuery(root->left,k1,root->ele);
		Range.arr[Range.index]=root->ele;
		Range.index++;
		rangeQuery(root->right,root->ele,k2);
	}
}
