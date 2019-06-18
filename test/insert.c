#include "node.h"
#include <stdio.h>
#include <stdlib.h>

/*
Precondition: head stores the address of pointer to a node and new_node stores the address of new_node.
“head” refers to any node whose address is stored in the child pointer of some other node.
For example, in the figure given, at level-1, the only head is the node with value “B”. Nodes with respective values “A”, “O”, “A”, “U”, “A” are heads at level-2, and so on.
The new_node's fields are set, i.e. its character field is set to appropriate value, all pointer fields are set to NULL, and stop_word field is set to FALSE.

Post condition: Stores new_node as one of the siblings of head such that all resulting siblings of head are sorted in increasing order as per character stored.
insert function will have binary marking.


*/


void insert(NODE** head, NODE* new_node)
{
	NODE * trav=*head;
	if(trav==NULL)
	{
		//printf("HI\n");
		*head=new_node;
		return;
	}
	while(trav->sibling!=NULL)
	{
		if((trav->c)<=(new_node->c) && (new_node->c)<(trav->sibling->c))
		{
			//printf("yo\n");
			NODE * tmp=trav->sibling;
			trav->sibling=new_node;
			new_node->sibling=tmp;
			//if(trav==*head)
			//	*head=trav;
			return;
		}
		trav=trav->sibling;
	}
	trav->sibling=new_node;
	new_node->sibling=NULL;
	//*head=trav;
}
