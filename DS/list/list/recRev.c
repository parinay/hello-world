#include "list.h"

int main()
{
	lNODE *head = newNode(10);

	head->next = newNode(20);
	head->next->next = newNode(30);

	head = insertAtStart(head, 1);

	printList(head);

	recRev(&head);
	printList(head);
	recRev3(&head);
	printList(head);
	exit(0);
}


