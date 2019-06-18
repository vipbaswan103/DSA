//Vipin Baswan
//2017A7PS0429P
#include "node.h"
#include <stdio.h>
#include <stdlib.h>
extern NODE * root;
//create_node function crates a new node.
NODE* create_node(char temp)
{
    NODE *new = (NODE*)malloc(sizeof(NODE));
    new->c = temp;
    new->child = NULL;
    new->sibling = NULL;
    new->stop_word = FALSE;
    return new;
}
//Function printList takes the pointer to NODE and prints all its siblings.
void printlist(NODE *head)
{
    NODE *temp = head;
    while(temp != NULL)
    {
        printf("%c  ", temp->c);
        temp = temp->sibling;
    }
}

int main()
{
    char *words[] = {"BAD","BADGE","BED","BEDROCK","COMFORT","CONFIRM","CONFORM","CORN","CORNER","DAM","DAMAGE","DAMN","DEN","FULL","MAN","MEN","MENTOR"};
    
    root = (NODE*) malloc (sizeof (NODE));
    root -> c = '\0';
    root -> child = NULL;
    root ->sibling = NULL;
    root -> stop_word = FALSE;

	for(int i=0;i<17;i++)
	{
		insert_word(words[i]);
	}
	

	traverse_tree(root);
	boolean x=search_word("FULL");
	if(x==TRUE)
		printf("FOUND\n");
	else
		printf("NOT FOUND\n");
		
	
   /* CODE BELOW CREATES TRIE WITH FIRST 9 WORDS OF array "words" ARRAY. YOU CAN USE IT AS PER YOUR CONVENIENCE TO TEST YOUR FUNCTIONS*/
    /*NODE *nb = create_node('B');
    root->child = nb;
    NODE *nba = create_node('A');
    nb->child = nba;
    NODE *nbad = create_node('D');
    nba->child = nbad;
    nbad->stop_word = TRUE;
    NODE *nbadg = create_node('G');
    nbad->child = nbadg;
    NODE *nbadge = create_node('E');
    nbadg->child = nbadge;
    nbadge->stop_word = TRUE;

    NODE *nbe = create_node('E');
    nba->sibling = nbe;
    NODE *nbed = create_node('D');
    nbe->child = nbed;
    nbed->stop_word = TRUE;
    NODE *nbedr = create_node('R');
    nbed->child = nbedr;
    NODE *nbedro = create_node('O');
    nbedr->child = nbedro;
    NODE *nbedroc = create_node('C');
    nbedro->child = nbedroc;
    NODE *nbedrock = create_node('K');
    nbedroc->child = nbedrock;
    nbedrock->stop_word = TRUE;

    NODE *nc = create_node('C');
    nb->sibling = nc;
    NODE *nco = create_node('O');
    nc->child = nco;
    NODE *ncom = create_node('M');
    nco->child = ncom;
    NODE *ncomf = create_node('F');
    ncom->child = ncomf;
    NODE *ncomfo = create_node('O');
    ncomf->child = ncomfo;
    NODE *ncomfor = create_node('R');
    ncomfo->child = ncomfor;
    NODE *ncomfort = create_node('T');
    ncomfor->child = ncomfort;
    ncomfort->stop_word = TRUE;

    NODE *ncon = create_node('N');
    ncom->sibling = ncon;
    NODE *nconf = create_node('F');
    ncon->child = nconf;
    NODE *nconfi = create_node('I');
    nconf->child = nconfi;
    NODE *nconfir = create_node('R');
    nconfi->child = nconfir;
    NODE *nconfirm = create_node('M');
    nconfir->child = nconfirm;
    nconfirm->stop_word = TRUE;

    NODE *nconfo = create_node('O');
    nconfi->sibling = nconfo;
    NODE *nconfor = create_node('R');
    nconfo->child = nconfor;
    NODE *nconform = create_node('M');
    nconfor->child = nconform;
    nconform->stop_word = TRUE;

    NODE *ncor = create_node('R');
    ncon->sibling = ncor;
    NODE *ncorn = create_node('N');
    ncor->child = ncorn;
    ncorn->stop_word = TRUE;
    NODE *ncorne = create_node('E');
    ncorn->child = ncorne;
    NODE *ncorner = create_node('R');
    ncorne->child = ncorner;
    ncorner->stop_word = TRUE;*/
}
