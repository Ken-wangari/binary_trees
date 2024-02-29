#include "binary_trees.h"

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
    if (parent == NULL)
        return (NULL);

    // Create a new node
    binary_tree_t *new = binary_tree_node(parent, value);
    if (new == NULL)
        return (NULL);

    // If parent already has a left child, update pointers
    if (parent->left != NULL)
    {
        new->left = parent->left;
        parent->left->parent = new;
    }

    // Set the new node as the left child of the parent
    parent->left = new;

    return (new);
}

