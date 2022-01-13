#include "utils.h"

int main()
{
    struct node *root = NULL;
    root = insert_node(root, 50);
    root = insert_node(root, 30);
    root = insert_node(root, 20);
    root = insert_node(root, 40);
    root = insert_node(root, 70);
    root = insert_node(root, 60);
    root = insert_node(root, 80);

    // Display tree
    inorder_traverse(root);

    // delete node
    printf("delete node - 20\n");
    if (root != NULL)
    {
        delete_node(root, 20);
    }

    printf("display the tree after deletion\n");
    inorder_traverse(root);

    struct node *max = max_value_node(root);
    printf("Max node: %d\n", max->value);

    struct node *min = min_value_node(root);
    printf("Max node: %d\n", min->value);
    return 0;
}
