#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
}lNODE;

struct node * newNode(int val)
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(lNODE));
	temp->data = val;
	temp->next = NULL;

	return temp;
}

void printList(struct node *root)
{
	struct node * temp = root;
	printf("The List is: ");
	while(temp != NULL) {
		printf(" %d ", temp->data);
		temp =temp->next;
	}
	printf("\n");
}
struct node * insertAtStart(struct node *root, int val)
{
	struct node *start;

	start = newNode(val);

	start->next = root;
	root = start;

	return(root);

}
void insertAtEnd(struct node *root, int val)
{
	struct node *end;
	struct node *tmp;

	tmp = root;
	while(tmp->next != NULL)
		tmp = tmp->next;

	end = newNode(val);
	tmp->next = end;

}
int sizeoflist(struct node *root)
{
	int count=0;

	while(root != NULL) {
		count=count+1;
		root = root->next;
	}
	return count;
}
void insertAtTheNth(struct node *root, int val)
{
	struct node *nth;
	struct node *tmp;
	struct node *prv;

	tmp = root;

	for(int i=0; i<val-1; i++) {
		prv = tmp;
		tmp=tmp->next;
	}
	nth = newNode(val);
	nth->next = tmp;
	prv->next = nth;
}

struct node* deleteTheNth(struct node *root, int pos)
{
	//struct node *nth;
	struct node *tmp;
	struct node *prv;

	tmp = root;

	if(pos==1){
		root=tmp->next;
		free(tmp);
		return (root);
	}

	for(int i=0; i<pos-1; i++) {
		prv=tmp;
		tmp=tmp->next;
	}
	prv->next = tmp->next;
	free(tmp);

	return(root);
}
//iterative
struct node *revList(struct node *root)
{
	struct node *current;
	struct node *prev;
	struct node *next;

	prev = NULL;
	current = root;

	while(current != NULL) {
		// next node to current
		next = current->next;
		// reverse the next pointer to prev
		current->next = prev;
		//move the nodes ahead
		prev = current;
		current = next;
	}
	root = prev;

	return(root);
}
//print recursive
void printRec(struct node *root)
{
	if(root == NULL) {
		return;
	}

	printRec(root->next);
	printf(" %d ", root->data);
}
// recursive reverse
void recRev(struct node **head)
{
	struct node *first;
	struct node *rest;

	/*exit if list is empty
        if (*head == NULL)
                return;
	*/
	first = *head;
	rest = first->next;

	//if list contain single node
	//and exit condition too.
	if(rest == NULL)
		return;

	recRev(&rest);

	first->next->next = first;
	first->next = NULL;

	*head = rest;
}
//recursive reverse using prev, current, next pointers.
void rev3ptrs(struct node *current, struct node *prev, struct node **head)
{
	//If last node, mark it as head.
	if(current->next == NULL) {
		*head = current;

		current->next = prev;
		return;
	}
	struct node *next = current->next;
	current->next = prev;

	rev3ptrs(next, current, head);
}

void recRev3(struct node **head)
{
	if(head == NULL)
		return;

	rev3ptrs(*head, NULL, head);
}
