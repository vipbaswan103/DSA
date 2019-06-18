#include "node.h"
#include <stdio.h>
#include <stdlib.h>

/*
Precondition: "word" points to the upper-case English word with length > 1.
Post condition: The function inserts each character of "word" in Trie appropriately. Note that global variable "root" stores the root of the Trie datastructure.
You have to strictly implement this function as non-recursive.
*/

void insert_word(char *word)
{
	NODE * tmp=root;
	int i=0;
	int signal=0;
	while(word[i]!='\0')
	{
		//printf("%c\n",word[i]);
		if(signal==1 || tmp->child==NULL)
		{
			NODE * trav=tmp->child;
			NODE * prev=tmp;
			int j=i;
			//if(trav!=NULL)
				//printf("%c %d\n",trav->c,j);
			while(word[j]!='\0')
			{
				NODE * newNode=create_node(word[j]);
				if(word[j+1]=='\0')
				{
					//printf("YES %c\n",newNode->c);
					newNode->stop_word=TRUE;
				}
				insert(&trav,newNode);
				NODE * pqr=search(word[j],trav);

				prev->child=pqr;
				trav=pqr;
				prev=trav;
				trav=trav->child;
				j++;
			}
			break;
		}
		NODE * trav=tmp->child;
		int flag=0;
		while(trav!=NULL)
		{
			if(trav->c==word[i])
			{
				flag=1;
				break;
			}
			trav=trav->sibling;
		}
		
		if(flag==1)
		{
			tmp=trav;
		}
		else
		{
			signal=1;
			NODE * trav=tmp->child;
			
			NODE * newNode=create_node(word[i]);
			insert(&trav,newNode);
			NODE * pqr=search(word[i],trav);
			if(word[i+1]=='\0')
				newNode->stop_word=TRUE;
			trav=pqr;
			tmp=trav;
		}
		i++;
	}
}
