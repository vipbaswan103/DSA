#include"fun.h"

Node * createTree()
{
	Node * tree=(Node *)malloc(sizeof(Node));
	tree->key=NULL;
	tree->child=NULL;
	tree->next=NULL;
	return tree;
}

void insert(Node * root, char * name, char * ip)
{
	int x=0,k=0,m=0;
	char * delimit[50];
	while(name[x]!='\0')
	{
		m=0;
		char * tmp=(char *)malloc(sizeof(char)*50);
		while(name[x]!='.' && name[x]!='\0')
		{
			tmp[m]=name[x];
			m++;
			x++;	
		}
		tmp[m]='\0';
		int size=strlen(tmp);
		delimit[k]=(char*) malloc(sizeof(char)*size + sizeof(char));
		strcpy(delimit[k],tmp);
		k++;
		if(name[x]=='\0')
			break;
		x++;
	}
	Node * trav=root;
	int flag=0,signal=0;
	for(int i=k-1;i>=0;i--)
	{
		flag=0;
		if(signal==1 || trav->child==NULL)
		{
			for(int j=i;j>=0;j--)
			{
				Node * newNode=(Node *)malloc(sizeof(Node));
				newNode->next=NULL;
				newNode->child=NULL;
				newNode->key=(char *) malloc(sizeof(char)*strlen(delimit[j])+1);
				strcpy(newNode->key,delimit[j]);
				trav->child=newNode;
				trav=trav->child;
			}
			break;
		}
		Node * tmp=trav->child;
		Node * prev=NULL;
	
		while(tmp!=NULL)
		{
			if(strcmp(tmp->key,delimit[i])==0)
			{
				flag=1;
				break;
			}
			prev=tmp;
			tmp=tmp->next;
		}
		if(flag==1)
		{
			if(trav->child->child==NULL)
				break;
			trav=tmp;
		}
		else
		{
			tmp=trav->child;
			while(tmp->next!=NULL)
			{
				tmp=tmp->next;
			}
			Node * newNode=(Node *)malloc(sizeof(Node));
			tmp->next=newNode;
			newNode->next=NULL;
			newNode->child=NULL;
			newNode->key=(char *) malloc(sizeof(char)*strlen(delimit[i])+1);
			strcpy(newNode->key,delimit[i]);
			trav=newNode;
			signal=1;
		}
	}
	
	Node * tmp=trav->child;
	if(tmp==NULL)
	{
		Node * leaf=(Node *)malloc(sizeof(Node));
		trav->child=leaf;
		leaf->child=NULL;
		leaf->next=NULL;
		leaf->key=(char *) malloc(sizeof(char)*strlen(ip)+1);
		strcpy(leaf->key,ip);
	}
	else
	{
		while(tmp->next!=NULL)
			tmp=tmp->next;
		Node * leaf=(Node *)malloc(sizeof(Node));
		tmp->next=leaf;
		leaf->child=NULL;
		leaf->next=NULL;
		leaf->key=(char *) malloc(sizeof(char)*strlen(ip)+1);
		strcpy(leaf->key,ip);
	}
}

void readData(FILE * fp, Node * root)
{
	char name[200];
	char ip[20];
	int rec;
	fscanf(fp,"%d",&rec);
	printf("No of records: %d\n",rec);
	while(fscanf(fp,"%s %s\n",name,ip)!=EOF)
	{
		//printf("%s\t%s\n",name,ip);
		insert(root,name,ip);
	}
}

void lookUp(Node * root, char * name)
{
	char * delimit[50];
	int i=0,k=0,m=0;
	while(name[i]!='\0')
	{
		m=0;
		char * tmp=(char *)malloc(sizeof(char)*51);
		while(name[i]!='.' && name[i]!='\0')
		{
			tmp[m]=name[i];
			i++;
			m++;		
		}
		tmp[m]='\0';
		delimit[k]=(char *)malloc(sizeof(char)*strlen(tmp)+sizeof(char));
		strcpy(delimit[k],tmp);
		k++;
		if(name[i]=='\0')
			break;
		i++;
	}	
	Node * trav=root;
	int x=0,c=0;
	int arr[1000];
	int flag=0,signal=0;
	for(int i=k-1;i>=0;i--)
	{
		if(root->child==NULL)
			return;
		Node * tmp=trav->child;
		c=0;
		flag=0;
		while(tmp!=NULL)
		{
			if(strcmp(tmp->key,delimit[i])==0)
			{
				arr[x]=c;
				x++;
				flag=1;
				break;
			}
			tmp=tmp->next;
			c++;
		}		
		if(flag==0)
		{
			break;
		}
		else
		{
			trav=tmp;
			if(trav->child->child==NULL)
			{
				signal=1;
				break;
			}
		}
	}
	if(signal==0)
	{
		for(int i=0;i<x;i++)
			printf("%d\t",arr[i]);
	}
	else
	{
		Node * tmp=trav->child;
		printf("\n");
		while(tmp!=NULL)
		{
			printf("%s\n",tmp->key);
			tmp=tmp->next;
		}
	}
}
void printDFS(Node * root)
{
	if(root==NULL)
		return;
	
	printDFS(root->child);
	printDFS(root->next);
	printf("%s ",root->key);
}

/*void printLevel(Node * root)
{
	Node queue[10000];
	if(root==NULL)
			return;

	printf("%s ",root->key);
	Node * tmp=root->child;
	while(tmp!=NULL)
	{
		enqueue(tmp->key);
		printLevel(tmp->child);
		tmp=tmp->next;	
	}
	printLevel(root->next);
	while(empty(queue)!=0)
	{
		printf("%s ",dequeue()->key);
	}
}*/
