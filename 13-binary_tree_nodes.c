#include "binary_trees.h"

/**
 * binary_tree_nodes - function counts the nodes with at least one child in a tree.
 * @tree: pointer to the root node to count the num of nodes.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    size_t nodes = 0;

    if (tree->left != NULL || tree->right != NULL)
        nodes++;

    nodes += binary_tree_nodes(tree->left);
    nodes += binary_tree_nodes(tree->right);

    return nodes;
}

