#include "queue.h"

int main()
{
	Q *q = createQ();
	qNode *qn;

	push(q, 10);
	push(q, 20);
	push(q, 30);
	printf("size of the queue is %d\n", size(q));
	displayQ(q);
	qn=pop(q);
	printf("popped item is %d\n",qn->data);
	printf("size of the queue is %d\n", size(q));
	qn=pop(q);
	printf("popped item is %d\n",qn->data);
	printf("size of the queue is %d\n", size(q));
	qn=pop(q);
	printf("popped item is %d\n",qn->data);
	printf("size of the queue is %d\n", size(q));
}
