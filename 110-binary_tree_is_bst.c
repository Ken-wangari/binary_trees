#include "binary_trees.h"
#include "limits.h"

/**
 * isbst_help - function checks if a binary tree is a valid binary search tree.
 * @tree:  pointer to the root node of the tree to check.
 * @low: The value of the smallest node visited thus far.
 * @high: The value of the largest node visited this far.
 *
 * Return: If the tree is a valid BST, 1, otherwise, 0.
 */
int isbst_help(const binary_tree_t *tree, int low, int high)
{
	if (tree != NULL)
	{
		if (tree->n < low || tree->n > high)
			return (0);
		return (isbst_help(tree->left, low, tree->n - 1) &&
			isbst_help(tree->right, tree->n + 1, high));
	}
	return (1);
}

/**
 * binary_tree_is_bst - function checks if a binary tree is a valid binary search tree.
 * @tree:  pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (isbst_help(tree, INT_MIN, INT_MAX));
}
