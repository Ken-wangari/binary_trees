#include "binary_trees.h"

/**
 * binary_tree_postorder - Uses the post-order traversal to traverse through a binary tree.
 * @tree: the pointer to the root node of the tree.
 * @func: the pointer to a function that calls for each node made.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*function)(int))
{
	if (tree && function)
	{
		binary_tree_postorder(tree->left, function);
		binary_tree_postorder(tree->right, function);
		function(tree->n);
	}
}
