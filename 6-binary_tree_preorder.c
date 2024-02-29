#include "binary_trees.h"

/**
 * binary_tree_preorder - This function uses pre-order traversal and goes through a binary tree.
 * @tree: pointer to the root node..
 * @function: pointer to a function to call for the nodes
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*function)(int))
{
	if (tree && function)
	{
		function(tree->n);
		binary_tree_preorder(tree->left, function);
		binary_tree_preorder(tree->right, function);
	}
}
