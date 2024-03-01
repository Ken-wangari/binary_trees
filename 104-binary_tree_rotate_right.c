#include "binary_trees.h"

/**
 * binary_tree_rotate_right - this function rotates in a right manner the binary tree.
 * @tree: pointer to the root node of the tree to rotate.
 *
 * Return: pointer to the new root node.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	if (tree == NULL || tree->left == NULL)
		return (NULL);

	{
		binary_tree_t *pivot = tree->left;
		tree->left = pivot->right;

		if (pivot->right != NULL)
			pivot->right->parent = tree;

		pivot->right = tree;
		pivot->parent = tree->parent;
		tree->parent = pivot;

		if (pivot->parent != NULL)
		{
			if (pivot->parent->left == tree)
				pivot->parent->left = pivot;
			else
				pivot->parent->right = pivot;
		}

		return (pivot);
	}
}

