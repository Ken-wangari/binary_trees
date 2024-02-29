#include "binary_trees.h"

/**
 * binary_tree_inorder - This function uses in-order traversal to go through a binary tree.
 * @tree:  pointer to the root node of the tree.
 * @function: pointer to a function that calls for each and every node made.
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*function)(int))
{
	if (tree && function)
	{
		binary_tree_inorder(tree->left, function);
		function(tree->n);
		binary_tree_inorder(tree->right, function);
	}
}
