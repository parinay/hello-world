#include <stdio.h>
#include <stdlib.h>

/** 
 * Improvements:
 * create a generic structure instead of type specific
 * use structure alignment for faster memory access
 * 
 */
struct node
{
    int value;
    struct node *left;
    struct node *right;
};
struct node *new_node(int value)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->value = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
struct node *insert_node(struct node *node, int value)
{
    if (node == NULL)
    {
        return (new_node(value));
    }
    //traverse to find the right place
    if (value < node->value)
    {
        node->left = insert_node(node->left, value);
    }
    else if (value > node->value)
    {
        node->right = insert_node(node->right, value);
    }
    return node;
}
void inorder_traverse(struct node *node)
{
    if (node != NULL)
    {
        inorder_traverse(node->left);
        printf(" %d ", node->value);
        inorder_traverse(node->right);
    }
    printf("\n");
}
struct node *min_value_node(struct node *node)
{
    struct node *current = node;

    while (current != NULL && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}
struct node *max_value_node(struct node *node)
{
    struct node *current = node;

    while (current != NULL && current->right != NULL)
    {
        current = current->right;
    }
    return current;
}
struct node *delete_node(struct node *root, int value)
{
    if (value < root->value)
    {
        root->left = delete_node(root->left, value);
    }
    else if (value > root->value)
    {
        root->right = delete_node(root->right, value);
    }
    // found the node
    else
    {
        // if left child is NULL OR no child
        // then copy the right child
        // free the root, return the right child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = min_value_node(root->right);
        root->value = temp->value;
        root->right = delete_node(root->right, temp->value);
    }
    return root;
}