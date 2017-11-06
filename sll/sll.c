#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node *n;
	int d;
};
struct node *newNode(int n)
{
	struct node *new = (struct node *)malloc(sizeof(struct node));
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
struct node* deleteMiddle(struct node *h)
{
	struct node *s, *f, *p;
	s = h;
	f = h;

	while(f != NULL && f->n != NULL) {
		p = s;
		f = f->n->n;
		s = s->n;
	}

	p->n = s->n;
	free(s);
	return(h);
}
struct node * reverseList(struct node *h)
{
	struct node *p, *c, *nx;
	p = NULL;
	nx = NULL;
	c = h ;

	while ( c != NULL) {
		nx = c->n;
		c->n = p;
		p = c;
		c = nx;
	}
	h = p;
	return(h);
}
struct node *reverseIngrp(struct node *h, int k)
{
	struct node *p, *nx, *c;
	int count = 0;
	p = NULL;
	nx = NULL;
	c = h;

	while (c != NULL && count < k) {
		nx = c->n;
		c->n = p;
		p = c;
		c = nx;
		count++;
	}

	if (nx != NULL)
		h->n = reverseIngrp(nx, k);

	h = p;
	return(p);

}
int main()
{
	struct node *h = NULL;

	h = newNode(10);
	h->n = newNode(20);
	h->n->n  = newNode(30);
	h->n->n->n = newNode(40);
	h->n->n->n->n = newNode(50);
	h->n->n->n->n->n = newNode(60);
	h->n->n->n->n->n->n = newNode(70);

	printList(h);
	h = reverseIngrp(h, 2);
	printList(h);
	h = reverseList(h);
	printList(h);
	h = deleteMiddle(h);
	printList(h);

}
