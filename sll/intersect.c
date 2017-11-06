#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node * createNode(int data)
{
	struct node *new = (struct node *)malloc(sizeof(struct node));
	new->data = data;
	new->next = NULL;
	return new;
}
int getintersect(struct node *head1, struct node *head2);
int getIntersection(int diff, struct node *head1, struct node *head2);
void printList(struct node *head);
int getcount(struct node *head)
{
	int count=0;
	while (head != NULL) {
		count++;
		head = head->next;
	}
	return count;
}
void printList(struct node *head)
{
	while (head != NULL){
		printf("%d\t", head->data);
		head = head->next;
	}
}
int _getIntersection(int diff, struct node *head1, struct node *head2)
{
	int i;
	struct node *one = head1;
	struct node *two = head2;
	for(i=0; i <diff; i++) {
		if(one == NULL)
			return -1;
		one = one->next;
	}

	while(one != NULL && two != NULL) {
		if (one == two) 
			return one->data;
		one = one->next;
		two = two->next;
	}
	return(-1);

}
int getintersect(struct node *head1, struct node *head2)
{
	int c1 = getcount(head1);
	int c2 =  getcount(head2);
	int intersectNode;
	if (c1 > c2) {
		int diff = c1 - c2;
		intersectNode = _getIntersection(diff, head1, head2);
	}else {
		int diff = c2 - c1;
		intersectNode = _getIntersection(diff, head2, head1);
	}
	return(intersectNode);
}
int main()
{
	struct node *head1 = createNode(10);
	struct node *head2 = createNode(3);
	
	struct node *newNode = createNode(6);
	head2->next = newNode;

	newNode = createNode(9);
	head2->next->next = newNode;

	newNode = createNode(15);
	head1->next = newNode;
	head2->next->next->next = newNode; 

	newNode = createNode(30);
	head1->next->next = newNode;

	printList(head1);
	printf("\n");
	printList(head2);
	printf("\n");
	
	printf("Intersect node is %d \n", getintersect(head1, head2));
	return 0;
}
