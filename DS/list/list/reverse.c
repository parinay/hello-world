#include "list.h"

int main()
{
	lNODE * root = newNode(10);

	root->next = newNode(20);
	root->next->next = newNode(30);

	root = insertAtStart(root, 1);

	printList(root);

	root = revList(root);
	printList(root);

	printf("The List is: ");
	printRec(root);
	printf("\n");

	exit(0);
}
