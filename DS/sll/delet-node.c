#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};
void printTree(struct node *root);
struct node* deleteNode(struct node *root, int data);

struct node *newNode(int data)
{
	struct node *new = (struct node *)malloc(sizeof(struct node));
	new->data = data;
	new->next = NULL;
	return(new);
}

void printList(struct node *root)
{
	struct node *temp;
	temp = root;
	while (temp != NULL) {
		printf("%d ",temp->data);
		temp =temp->next;
	}
	printf("\n");
}

struct node *deleteNode(struct node *root, int data)
{
	struct node *prev = NULL;
	struct node *temp = root;


	if (root != NULL && root->data == data) {
		temp = root;
		root = root->next;
		free(temp);
	}
	while (temp != NULL && temp->data != data) {
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL ) {
		printf("The data not found...\n");
		return;
	}

	prev->next = temp->next;
	free(temp);

}
int main()
{
	struct node *root;
	struct node *temp;


	root = newNode(10);
	root->next = newNode(8);
	root->next->next = newNode(7);
	root->next->next->next  = newNode(12);
	printList(root);
	deleteNode(root, 18);
	printList(root);
}
