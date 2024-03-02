#include "binary_trees.h"
#include "limits.h"

/**
 * height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	size_t l_height = height(tree->left);
	size_t r_height = height(tree->right);

	return (1 + (l_height > r_height ? l_height : r_height));
}

/**
 * is_avl_helper - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 * @min: The value of the smallest node visited thus far.
 * @max: The value of the largest node visited this far.
 *
 * Return: If the tree is a valid AVL tree, 1, otherwise, 0.
 */
int is_avl_helper(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	int l_height = height(tree->left);
	int r_height = height(tree->right);
	int balance_factor = l_height - r_height;

	if (balance_factor > 1 || balance_factor < -1)
		return (0);

	return (is_avl_helper(tree->left, min, tree->n) &&
	        is_avl_helper(tree->right, tree->n, max));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL tree, and 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return is_avl_helper(tree, INT_MIN, INT_MAX);
}

