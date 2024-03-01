#include "binary_trees.h"

/**
 * is_full_recursive - this function checks if a binary-tree is full recursively.
 * @tree: pointer to the root node to check.
 *
 */
int is_full_recursive(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		if ((tree->left != NULL && tree->right == NULL) ||
		    (tree->left == NULL && tree->right != NULL) ||
		    is_full_recursive(tree->left) == 0 ||
		    is_full_recursive(tree->right) == 0)
			return (0);
	}
	return (1);
}

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If tree is NULL or is not full - 0.
 *         Otherwise - 1.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    if (tree->left == NULL && tree->right == NULL)
        return 1;

    if (tree->left && tree->right)
        return binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right);

    return 0;
}
