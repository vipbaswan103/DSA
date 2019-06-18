#include "node.h"
#include <stdio.h>
#include <stdlib.h>
extern NODE * root;
/*
Precondition: "word" points to the upper-case English word with length > 1.
Post condition: the function returns TRUE if "word" is present in the Trie; FALSE otherwise. Note that global variable "root" stores the root of the Trie data structure.
You have to strictly implement this fun as non-recursive.

*/

boolean search_word(char *word)
{
	NODE * trav=root->child;
	int i=0;
	
	if(trav==NULL)
		return FALSE;
	NODE * prev;
	while(word[i]!='\0')
	{		
		if(trav==NULL)
			return FALSE;
		NODE * mini=search(word[i],trav);
		if(mini==NULL)
			return FALSE;
			
		if(mini->stop_word==TRUE && word[i+1]=='\0')
			return TRUE;
		prev=trav;
		trav=mini->child;
		i++;
	}
	if(prev->stop_word==FALSE)
		return FALSE;
	return TRUE;
}
