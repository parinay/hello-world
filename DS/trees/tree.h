#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}NODE;

NODE *newNode(int data)
{
	NODE *node = (NODE *)malloc(sizeof(NODE));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return(node);
}
typedef struct Queue {
	struct node *front;
	struct node *rear;
}Q;

int maxDepth(NODE *node);
int treeHeight(NODE *node);

void printPreorder(NODE *node)
{
	if(node == NULL)
		return;

	printf("%d ", node->data);

	printPreorder(node->left);
	printPreorder(node->right);
}
void printInorder(NODE *node)
{
	if(node == NULL)
		return;

	printInorder(node->left);
	printf("%d ", node->data);
	printInorder(node->right);
}
void printPostorder(NODE *node)
{
	if(node==NULL)
		return;

	printPostorder(node->left);
	printPostorder(node->right);
	printf("%d ", node->data);
}
