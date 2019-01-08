#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
	struct node *prev;
}dNODE;

struct node * newNode(int val)
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(dNODE));
	temp->data = val;
	temp->next = NULL;
	temp->prev = NULL;

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

void revPrintList(struct node *root)
{
	struct node *temp = root;
	printf("The reverse list is: ");
	while(temp->next != NULL)
		temp = temp->next;

	while(temp != NULL) {
		printf(" %d ", temp->data);
		temp = temp->prev;
	}
	printf("\n");
}
struct node * insertAtStart(struct node *root, int val)
{
	struct node *start;

	start = newNode(val);

	if( root == NULL) {
		root = start;
		return start;
	}
	root->prev = start;
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
	end->prev = tmp;

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
	nth->prev = prv;
	prv->next = nth;
	tmp->prev = nth;
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
	tmp->next->prev = prv;
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
		current->prev = next;
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
