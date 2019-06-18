#include <stdio.h>
typedef enum {FALSE, TRUE} boolean;

typedef struct node NODE;
struct node
{
 char c;
 NODE *child; //Left Child
 NODE *sibling; //Right Sibling
 boolean stop_word; //TRUE if word is in the Dictionary; FALSE otherwise
};

NODE * root; // It is a global variable holding the address of root node

void insert(NODE** head, NODE* new_node);
void insert_word(char *word);
NODE* create_node(char temp);
void printlist(NODE *head);
NODE* search(char ch, NODE* head);
boolean search_word(char *word);
void traverse_tree(NODE *roo);
