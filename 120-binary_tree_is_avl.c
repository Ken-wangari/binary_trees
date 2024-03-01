#include "binary_trees.h"
#include "limits.h"

/**
 * tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 * Return: If tree is NULL, return 0, else return height.
 */
size_t tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t left_height = tree_height(tree->left);
		size_t right_height = tree_height(tree->right);
		return (1 + (left_height > right_height ? left_height : right_height));
	}
	return (0);
}

/**
 * is_avl_tree - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 * @min: The minimum allowed value for the current subtree.
 * @max: The maximum allowed value for the current subtree.
 * Return: If the tree is a valid AVL tree, 1, otherwise, 0.
 */
int is_avl_tree(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	size_t left_height = tree_height(tree->left);
	size_t right_height = tree_height(tree->right);
	size_t height_diff = (left_height > right_height) ? left_height - right_height : right_height - left_height;

	if (height_diff > 1)
		return (0);

	return (is_avl_tree(tree->left, min, tree->n) && is_avl_tree(tree->right, tree->n, max));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 * Return: 1 if tree is a valid AVL tree, and 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return is_avl_tree(tree, INT_MIN, INT_MAX);
}

