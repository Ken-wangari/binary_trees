#include "binary_trees.h"

/**
 * count_leaves - Helper function to count leaves in a binary tree.
 * @node: A pointer to the current node.
 *
 * Return: The number of leaves in the binary tree.
 */
size_t count_leaves(const binary_tree_t *node)
{
    if (node == NULL)
        return 0;

    if (node->left == NULL && node->right == NULL)
        return 1; // Current node is a leaf

    return count_leaves(node->left) + count_leaves(node->right);
}

/**
 * binary_tree_leaves - Counts the leaves in a binary tree.
 * @tree: A pointer to the root node of the tree to count leaves.
 *
 * Return: The number of leaves in the binary tree.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
    return count_leaves(tree);
}

