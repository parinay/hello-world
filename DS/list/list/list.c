#include "list.h"

int main()
{
	lNODE *root = newNode(10);
	int n;

	root->next = newNode(20);
	root->next->next = newNode(30);

	printList(root);
	for(int i=0; i<1; i++) {
		root = insertAtStart(root, (40+i));
		printList(root);
	}

	for(int i=0; i<1; i++) {
		insertAtEnd(root, (11+i));
		printList(root);

	}

	int size = sizeoflist(root);
	printf("Size of the List is %d\n",size);

	printf("Enter at the n'th position: ");
	scanf("%d", &n);

	if(n > size)
		insertAtEnd(root, n);
	else if(n <= 1){
		printf("Less than 0\n");
		root = insertAtStart(root,n);
	}
	else
		insertAtTheNth(root, n);

	printList(root);


	size = sizeoflist(root);
	printf("Enter the position of the node to be deleted (e.g. n=3): ");
	scanf("%d", &n);

	if(n >size)
		root = deleteTheNth(root, size);
	else if(n <=1)
		root = deleteTheNth(root, 1);
	else
		root=deleteTheNth(root, n);

	printList(root);
	exit(0);
}
