#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	struct node *n;
	int d;
}NODE;
struct node *newNode(int n)
{
	NODE *new = (struct node *)malloc(sizeof(struct node));
	new->n = NULL;
	new->d = n;

	return(new);

}
void printList(struct node *h)
{
	while ( h != NULL) {
		printf("%d ", h->d);
		h = h->n;
	}
	printf("\n");
}
int isLoop(NODE *h)
{
	NODE *s, *f;
	s=h;
	f=h;

	while(f && f->n != NULL) {
		s = s->n;
		f = f->n->n;
		if(s == f) {
			return(1);
			break;
		}
	}
	return (0);
}
int main()
{
	NODE *h = NULL;

	h = newNode(10);
	h->n = newNode(20);
	h->n->n  = newNode(30);
	h->n->n->n = newNode(40);
	h->n->n->n->n = newNode(50);
	h->n->n->n->n->n = h->n->n;
	if(isLoop(h))
		printf("List contains Cycle.\n");
	else
		printf("List doesn't contain a cycle.\n");
}
