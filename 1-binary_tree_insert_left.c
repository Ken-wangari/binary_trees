#include "binary_trees.h"

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
    // Check if the parent is NULL
    if (!parent)
        return NULL;

    // Create a new node
    binary_tree_t *new_node = binary_tree_node(parent, value);
    if (!new_node)
        return NULL;

    // If the parent already has a left child, set it as the left child of the new node
    if (parent->left)
    {
        new_node->left = parent->left;
        parent->left->parent = new_node;
    }

    // Set the new node as the left child of the parent
    parent->left = new_node;

    return new_node;
}

