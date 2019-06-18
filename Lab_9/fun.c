#include "fun.h"
int SIZE=0;
int hash(char * str, int base, int tableSize)
{
	int i=0,x,sum=0;
	while(str[i]!='\0')
	{
		x=(int)str[i];
		sum+=x;
		i++;
	}
	sum=sum%base;
	sum=sum%tableSize;
	return sum;
}

int isThere(int * arr, int size, int val)
{
	for(int i=0;i<size;i++)
	{
		if(arr[i]==val)
			return 1;
	}
	return 0;
}
void printArr(int * arr, int size)
{
	for(int i=0;i<size;i++)
	{
		printf("%d ",arr[i]);
	}
}
int collisionCount(char ** str, int nos, int base, int tableSize)
{
	int arr[nos];
	for(int i=0;i<nos;i++)
		arr[i]=-1;
	
	int x, noc=0;
	int j=0;
	for(int i=0; i<nos;i++)
	{
		x=hash(str[i],base,tableSize);
		if(i!=0)
		{
			if(isThere(arr,j,x)==1)
			{
				noc++;
			}
			else
			{
				arr[j]=x;	
				j++;
			}
		}
		if(i==0)
		{
			arr[j]=x;
			j++;
		}
	}
	return noc;
}

int isWordThere(char ** parsed, int s, char * str)
{
	for(int i=0;i<s;i++)
	{
		if(strcmp(parsed[i],str)==0)
			return 1;
	}
	return 0;
}
char ** parse(FILE * fp)
{
	char ** parsed=(char **)malloc(sizeof(char*)*1000);
	int ini=1000;
	
	char tmp[50];
	int j=0,size=1000;
	while(fscanf(fp,"%s ",tmp)!=EOF)
	{
		int i=0;
		while(tmp[i]!='\0')
		{
			if((tmp[i]>='a' && tmp[i]<='z') || (tmp[i]>='A' && tmp[i]<='Z'))
			{

			}
			else
			{
				if((tmp[i+1]>='a' && tmp[i+1]<='z') || (tmp[i+1]>='A' && tmp[i+1]<='Z'))
				{
					tmp[0]='\0';
					break;
				}
				else
					tmp[i]='\0';
			}
			i++;
			/*if((tmp[i]>='a' && tmp[i]<='z') || (tmp[i]>='A' && tmp[i]<='Z'))
			{}
			else
			{
				flag=0;
				break;
			}
			i++;*/
		}
		if(tmp[0]!='\0')
		{	
			//if(flag!=0 && isWordThere(parsed,j,tmp)==1)
			//	continue;
			if(j>=size)
			{
				parsed=(char **)realloc(parsed,sizeof(char*)*size*2);
				size=size*2;
			}
			int i=0;
			int sum=0,y;
			while(tmp[i]!='\0')
			{
				y=(int)tmp[i];
				sum+=y;
				i++;
			}	
			int x=strlen(tmp);
			parsed[j]=(char *)malloc(sizeof(char)*x);
			strcpy(parsed[j],tmp);
			j++;
		}
	}
	SIZE=j;
	printf("Numer of unique words in the book : %d\n",SIZE);
	return parsed;
}

int isPrime(int x)
{
	for(int i=2;i<x;i++)
	{
		if(x%i==0)
			return 0;
	}
	return 1;
}

void primeNum1(int * arr, int low, int high)
{
	int k=0;
	for(int i=low;i<=high;i++)
	{
		if(k==3)
			return;
		if(isPrime(i)==1)
		{
			if(k!=0 && i-arr[k-1]<10)
				continue;
			arr[k]=i;
			k++;
		}
	}
}

void primeNum2(int * arr, int low)
{
	int k=3;
	for(int i=low;;i++)
	{
		if(k==6)
			return;
		if(isPrime(i)==1)
		{
			if(k!=3 && i-arr[k-1]<10)
				continue;
			arr[k]=i;
			k++;
		}
	}
}

void sort(int arr[][3],int size)
{
	int x,y,z;
	for(int i=0;i<size;i++)
	{
		for(int j=i+1;j<size;j++)
		{
			if(arr[i][2]>arr[j][2])
			{
				x=arr[i][0];
				y=arr[i][1];
				z=arr[i][2];
				arr[i][0]=arr[j][0];
				arr[i][1]=arr[j][1];
				arr[i][2]=arr[j][2];
				arr[j][0]=x;
				arr[j][1]=y;
				arr[j][2]=z;
			}
		}
	}
}
int* profile(char ** book)
{
	int tabSize;
	int basNum[6];
	int collCount[18],k=0;
	int arr[18][3];
	int x=0,y=0;
	for(int i=0;i<3;i++)
	{
		if(i==0)
			tabSize=50;
		else if(i==1)
			tabSize=350;
		else if(i==2)
			tabSize=850;

		primeNum1(basNum,tabSize,tabSize*2);
		primeNum2(basNum,2*tabSize);
		
		for(int j=0;j<=5;j++)
		{
			collCount[k]=collisionCount(book,SIZE,basNum[j],tabSize);
			printf("TableSize: %d\t\tBaseNumber: %d\t\tCollisions: %d\n",tabSize,basNum[j],collCount[k]);
			arr[x][0]=tabSize;
			arr[x][1]=basNum[j];
			arr[x][2]=collCount[k];
			x++;
			k++;
		}
		printf("\n");
	}		

	sort(arr,18);

	printf("\n****BEST VALUES****\t Table Size= %d and Base Size = %d",arr[0][0],arr[0][1]);
	
	int * result=(int *)malloc(sizeof(int)*2);
	result[0]=arr[0][0];
	result[1]=arr[0][1];

	return result;
}

Hash * create(int tableSize)
{
	Table * tab =(Table *)malloc(sizeof(Table)*tableSize);
	
	Hash * hashTable=(Hash *)malloc(sizeof(Hash));

	hashTable->Head=tab;
	hashTable->insertionCost=0;
	hashTable->queryingCost=0;
	hashTable->elementCount=0;

	for(int i=0;i<tableSize;i++)
	{
		tab[i].index=-1;
		tab[i].count=0;
		tab[i].next=NULL;
	}
	return hashTable;
}

void insert(Hash * hashTable, char ** book, int in, int baseSize,int tableSize)
{
	if(hashTable->Head==NULL)
	{
		printf("Error: No memory allocated\n");
		return;
	}
	Table * start=hashTable->Head;
	int index=hash(book[in],baseSize,tableSize);
	if(start[index].next==NULL)
	{
		start[index].count++;
		//insert the element
		Table * newNode=(Table *)malloc(sizeof(Table));
		newNode->index=in;
		newNode->count=1;
		newNode->next=NULL;
		start[index].next=newNode;	//update the head
		hashTable->elementCount++;	//update no of ele
		hashTable->insertionCost++;	//update insertion cost
		return;
	}

	Table * tmp=(start[index].next);

	int c=0;
	Table * prev;
	while(tmp!=NULL)
	{
		if(tmp->index!=-1 && strcmp(book[tmp->index],book[in])==0)
		{
			//we have to update only the count
			//since book[in] is already present
			//in the hash table
			hashTable->elementCount++;	
			hashTable->insertionCost+=c;
			tmp->count++;
			start[index].count++;
			return;
		}
		c++;
		prev=tmp;
		tmp=tmp->next;
	}
	Table * newNode=(Table *)malloc(sizeof(Table));

	newNode->index=in;	//new string added
	newNode->count=1;	//count made 1
	prev->next=newNode;	//insertion at the end
	newNode->next=NULL;
	hashTable->insertionCost++;
	hashTable->elementCount++;
	start[index].count++;
}

int insertAll(Hash * hashTable, char ** book, int size,int tableSize, int baseSize)
{
	for(int  i=0;i<size;i++)
	{
		insert(hashTable, book, i, baseSize, tableSize);	
	}
	return hashTable->insertionCost;
}

Table * lookUp(Hash * hashTable, char ** book, char * key,int tableSize,int baseSize)
{
	int index=hash(key,baseSize, tableSize);

	Table * start=(hashTable->Head);
	if(start[index].next==NULL)
		return NULL;
	
	int count=0;

	Table * trav=(start[index].next);
	while(trav!=NULL)
	{
		count++;
		if(trav->index!=-1 && strcmp(book[trav->index],key)==0)
		{
			//printf("%d\t",count);
			(hashTable->queryingCost)+=count;
			return trav;
		}
		trav=trav->next;
	}
	(hashTable->queryingCost)+=count;
	return NULL;
}	

int lookupAll(Hash * hashTable, char ** book,double  m, int size, int tableSize, int baseSize)
{
	hashTable->queryingCost=0;	//Reset the cost
	int count=floor((m*size));
	Table * result;
	for(int i=0;i<count;i++)
	{
		result=lookUp(hashTable, book, book[i], baseSize, tableSize);
	}
	return hashTable->queryingCost;
}

void printHashTable(Hash * hashTable, char ** book, int tableSize)
{
	Table * start=hashTable->Head;

	int count=0;
	for(int i=0;i<tableSize;i++)
	{
		printf("%d\t\t",i+1);
		Table * trav=start[i].next;

		while(trav!=NULL)
		{
			printf("%s(%d)  ",book[trav->index],trav->count);
			count+=(trav->count);
			trav=trav->next;
		}
		printf("\n");
	}
	printf("Cross Checked: %d\n",count);
}

void cleanUp(Hash * hashTable, char ** book, char * key, int baseSize, int tableSize)
{
	int index=hash(key, baseSize, tableSize);

	Table * start=hashTable->Head;
	Table * trav=start[index].next;

	if(trav==NULL)
		return;

	if(strcmp(book[trav->index],key)==0)		//node to be deleted is the first node
	{
		//printf("Start: %d\t%d\n",hashTable->elementCount,trav->index);
		start[index].next=trav->next;
		(hashTable->elementCount)-=trav->count;
		(hashTable->insertionCost)-=1;
		(start[index].count)-=trav->count;
		//printf("End: %d\t%d\n",hashTable->elementCount,trav->index);
		free(trav);
		return;
	}

	/*key lies in the middle or end of the list*/
	Table * prev=&start[index];
	while(trav!=NULL)
	{
		if(strcmp(book[trav->index],key)==0)
		{
			//printf("Start: %d\t%d\n",hashTable->elementCount,trav->index);
			prev->next=trav->next;
			(hashTable->elementCount)-=trav->count;
			(hashTable->insertionCost)-=1;
			(start[index].count)-=trav->count;
			//printf("End: %d\t%d\n",hashTable->elementCount,trav->index);
			free(trav);
			return;
		}
		prev=trav;
		trav=trav->next;
	}
	return;
}
void profiling(Hash * hashTable, char ** book, int tableSize, int baseSize)
{
	int insertionCost=insertAll(hashTable,book,SIZE,tableSize,baseSize);	
	int queryingCost;
	double m=0.1;
	for(int i=0;i<20;i++)
	{
		queryingCost=lookupAll(hashTable,book,m,SIZE,tableSize,baseSize);
		printf("%d\t%d\n",insertionCost,queryingCost);	
		if(queryingCost>insertionCost)
		{
			break;
		}
		m=m+0.1;
	}
	printf("Overtaken at %lf percent\n",m*100);
}
