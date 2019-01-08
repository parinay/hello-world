#include <stdio.h>
#include <stdlib.h>

typedef struct qnode {
	int data;
	struct qnode *next;
}qNode;

typedef struct Queue {
	struct qnode *front;
	struct qnode *rear;
}Q;

Q* createQ(void)
{
	Q *q = (Q *)malloc(sizeof(Q));
	q->front = NULL;
	q->rear = NULL;
	return q;
}
qNode* createQNode(int data)
{
	qNode* temp = (qNode*)malloc(sizeof(qNode));
	temp->data = data;
	temp->next = NULL;
	return temp;
}
void push(Q *q, int data)
{
	qNode *tmp = createQNode(data);
#ifdef DEBUG
	printf("Entering %s\n",__func__);
#endif
	if(q->rear == NULL) {
		q->front = q->rear = tmp;
#ifdef DEBUG
		printf("Front updated!\n");
#endif
		return;
	}
	q->rear->next = tmp;
	q->rear = tmp;
#ifdef DEBUG
	printf("Exiting %s\n",__func__);
#endif
}
qNode* pop(Q *q)
{
	qNode *tmp;
#ifdef DEBUG
	printf("Entering %s\n",__func__);
#endif
	if(q->front == NULL) {
		printf("Q front is NULL\n");
		return NULL;
	}
	tmp = q->front;
	q->front = q->front->next;

	if(q->front == NULL)
		q->rear = NULL;
#ifdef DEBUG
	printf("Exiting %s\n",__func__);
#endif
	return tmp;
}

int size(Q *q)
{
	int qsize = 0;
	qNode *tmp = q->front;
#ifdef DEBUG
	printf("Entering %s\n",__func__);
#endif
	while (tmp != NULL) {
		qsize++;
		tmp = tmp->next;
	}
#ifdef DEBUG
	printf("Exiting %s\n", __func__);
#endif
	return qsize;
}

void displayQ(Q *q)
{
#ifdef DEBUG
	printf("Entering %s\n",__func__);
#endif
	qNode *tmp = q->front;
	while(tmp != NULL) {
		printf("%d \t", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
#ifdef DEBUG
	printf("Exiting %s\n", __func__);
#endif
}
