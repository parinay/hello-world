#include "dll.h"

int main()
{
	dNODE * head = newNode(1);

	head = insertAtStart(head, 2);
	head = insertAtStart(head, 3);
	head = insertAtStart(head, 4);
	printList(head);
	revPrintList(head);
	insertAtEnd(head, 5);
	printList(head);
	exit(0);
}

