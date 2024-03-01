#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node
 *                     in a binary tree.
 * @node: pointer to the node which we're finding the uncle of.
 *
 * Return: If node is NULL or has no uncle, return NULL, Otherwise, return a pointer to the uncle node.
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
    if (node == NULL ||
        node->parent == NULL ||
        node->parent->parent == NULL)
        return NULL;

    return (node->parent == node->parent->parent->left)
               ? node->parent->parent->right
               : node->parent->parent->left;
}

