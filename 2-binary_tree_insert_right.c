#include "binary_trees.h"

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
    if (parent == NULL)
        return (NULL);

    // Create a new node
    binary_tree_t *new = binary_tree_node(parent, value);
    if (new == NULL)
        return (NULL);

    // If parent already has a right child, update pointers
    if (parent->right != NULL)
    {
        new->right = parent->right;
        parent->right->parent = new;
    }

    // Set the new node as the right child of the parent
    parent->right = new;

    return (new);
}

