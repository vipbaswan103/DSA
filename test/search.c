#include "node.h"
#include <stdio.h>
#include <stdlib.h>


NODE* search(char ch, NODE* head)
{
 /* Precodition: head stores the pointer of a node and its definition is as explained in Q1 above. Character ch is to be searched within head and all its siblings.
Postcondition: It returns the address of the node in which ch is present. Otherwise, if head is NULL or ch is not present, it returns NULL.
search function will have binary marking.

 */
	NODE * trav=head;
	if(trav==NULL)
		return NULL;
		
	while(trav!=NULL)
	{
		if(trav->c==ch)
		{
				return trav;
		}
		trav=trav->sibling;
	}
	return NULL;
}
