#include "binary_trees.h"

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    // Allocate memory for the new node
    binary_tree_t *new = malloc(sizeof(binary_tree_t));
    
    // Check if memory allocation was successful
    if (!new)
        return (NULL);

    // Initialize the node's fields
    new->n = value;
    new->parent = parent;
    new->left = NULL;
    new->right = NULL;

    // Return a pointer to the newly created node
    return (new);
}

