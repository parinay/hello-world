#include "tree.h"

int maxDepth(NODE *node)
{
	if(node == NULL)
		return 0;
	else {
		int lDepth = maxDepth(node->left);
		int rDepth = maxDepth(node->right);

		if(lDepth > rDepth)
			return(lDepth+1);
		else
			return(rDepth+1);
	}

}
int main()
{
	NODE *root =newNode(1);

	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	printf("Height of the tree is %d\n", maxDepth(root));

	printf("PreorderTraversal - ");
	printPreorder(root);
	printf("\n");
	printf("InorderTraversal -");
	printInorder(root);
	printf("\n");
	printf("PostorderTraversal -");
	printPostorder(root);
	printf("\n");

	return 0;
}
