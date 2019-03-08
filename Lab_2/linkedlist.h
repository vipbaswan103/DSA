struct node
{
	int ele;
	struct node *next;
};

struct linkedlist
{
	int count;	/*no of nodes in the list*/
	struct node *first;
};

void insertFirst(struct linkedlist * head, int ele);
void insertLast(struct linkedlist * head, int ele);
void insertMid(struct linkedlist *head, int ele, int pos);

struct node * deleteFirst(struct linkedlist *head);
struct node * deleteLast(struct linkedlist *head);
struct node * deleteEle(struct linkedlist* head,int ele);

void printList(struct linkedlist *head);
int search(struct linkedlist  * head, int ele);
void printSort(struct linkedlist*head);
