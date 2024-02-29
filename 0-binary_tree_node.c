#include "binary_trees.h"

/**
 * binary_tree_node - This function creates binary tree node.
 * @parent:  pointer to the parent of the node.
 * @value: value that gets put out.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);

	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;

	return (new);
}

