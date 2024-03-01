#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"

/**
 * check_max_heap - Checks if a binary tree is a max heap.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: 1 if the tree is a max heap, 0 otherwise.
 */
int check_max_heap(const binary_tree_t *tree)
{
	int left_result = 1, right_result = 1;

	if (!tree)
		return (1);

	if (tree->left)
	{
		if (tree->left->n > tree->n)
			return (0);
		left_result = check_max_heap(tree->left);
	}

	if (tree->right)
	{
		if (tree->right->n > tree->n)
			return (0);
		right_result = check_max_heap(tree->right);
	}

	return (left_result && right_result);
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a max heap.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: 1 if the tree is a max heap, 0 otherwise.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int is_complete = binary_tree_is_complete(tree);

	if (!is_complete)
		return (0);

	return check_max_heap(tree);
}

