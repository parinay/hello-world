#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node *left, *right;
	int key;
};
struct node * insert(struct node *root, int key);
void inOrder(struct node *root);
void preOrder(struct node *root);
void postOrder(struct node *root);
int height (struct node *root);
int isBalanced (struct node *root);
int search(struct node *root, int key);
struct node *newNode(int key)
{
	struct node *new = (struct node *)malloc(sizeof(struct node));
	new->left = NULL;
	new->right = NULL;
	new->key = key;

	return(new);

}
struct node * insert(struct node *root, int key)
{
	if (root == NULL)
		return(newNode(key));
	if (key > root->key)
		root->right = insert(root->right, key);
	else if (key < root->key)
		root->left = insert(root->left, key);

	return(root);
}
void inOrder(struct node *root)
{
	if (root != NULL){
		inOrder(root->left);
		printf("%d ", root->key);
		inOrder(root->right);
	}
}
void preOrder(struct node *root)
{
	if(root != NULL) {
		printf("%d ", root->key);
		preOrder(root->left);
		preOrder(root->right);
	}
}
void postOrder(struct node *root)
{
	if(root != NULL) {
		postOrder(root->left);
		postOrder(root->right);
		printf("%d ", root->key);
	}
}
int height(struct node *root)
{
	if (root == NULL)
		return 0;

	int l = height(root->left);
	int r = height(root->right);

	if (l > r)
		return(l+1);
	else
		return(r+1);
}

int isBalanced(struct node *root)
{
	if (root == NULL)
		return 1;

	int l = height(root->left);
	int r = height(root->right);

	if ( abs(l-r) <=1 &&
	    isBalanced(root->left) &&
	    isBalanced(root->right))
		return 1;

	return 0;
}

int search(struct node *root, int key)
{
	if (root == NULL )
		return 0;
	if (root->key == key)
		return 1;
	if (key < root->key)
		search(root->left, key);
	else if (key > root->key)
		search(root->right, key);
	else
		return 0;
}
int getleafCount(struct node *root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	else
		return(getleafCount(root->left) +
		       getleafCount(root->right));


}
struct node * sorted_to_bst(int *array, int start, int end)
{
	if (start > end)
		return NULL;
	int mid = (start +end)/2;

	struct node *root = newNode(array[mid]);

	root->left = sorted_to_bst(array, start, mid-1);
	root->right = sorted_to_bst(array,mid+1, end);

	return root;
}
int main()
{
	//Create a bst
	struct node * root = NULL;
	root = insert(root,10);
	root = insert(root, 20);
	root = insert(root, 30);
	root = insert(root, 40);
	root = insert(root, 50);
	root = insert(root, 25);
	// print a bst
	printf("Inorder...\n");
	inOrder(root);
	printf("\nPreorder...\n");
	preOrder(root);
	printf("\nPostOrder...\n");
	postOrder(root);
	//height of bst
	int h = height(root);
	printf("\nHeight of the tree is : %d\n", h);
	// is the tree balanced
	int flag = isBalanced(root);
	if(flag)
		printf("Tree is balanced...\n");
	else
		printf("Tree is not balanced..\n");
	int s = search(root,50);
	if(s)
		printf("Search key found.\n");
	else
		printf("search key not found\n");

	//getleafnode count
	printf("No. of leaf nodes = %d\n",getleafCount(root));
	// sorted array  to bst
	int array[] = {10, 20, 25, 30, 40, 50};
	int size = sizeof(array) / sizeof(array[0]);
	struct node *temp = NULL;
	temp = sorted_to_bst(array, 0, size-1);
	inOrder(temp);
	printf("\n");
	flag = isBalanced(temp);
	if(flag)
		printf("Tree is balanced...\n");
	else
		printf("Tree is not balanced...\n");
	 printf("No. of leaf nodes = %d\n",getleafCount(temp));
}
