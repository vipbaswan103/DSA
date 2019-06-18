#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef struct slot
{
	int insertionCost;
	int queryingCost;
	int elementCount;
	struct Table * Head;
} Hash;

typedef struct Table
{
	int index;
	int count;
	struct Table * next;
} Table;
extern int SIZE;
int hash(char *, int ,int);
int collisionCount(char ** arr, int ,int, int);
char ** parse(FILE * fp);
int * profile(char ** book);
Hash * create(int tableSize);
void insert(Hash *, char **, int , int ,int);
int insertAll(Hash *, char **, int, int, int);
Table * lookUp(Hash *, char **, char *, int, int);
int lookupAll(Hash *, char **, double, int ,int , int);
void printHashTable(Hash *, char **, int);
void cleanUp(Hash * , char **, char *, int, int);
