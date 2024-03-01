#include "binary_trees.h"

/**
 * bst_insert - function inserts a value in a binary Search Tree.
 * @tree: double pointer to the root node of the BST that is used to insert the value.
 * @value: value to store in the node.
 *
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *curr, *new;

	if (tree == NULL)
		return (NULL);

	curr = *tree;
	new = binary_tree_node(curr, value);

	if (new == NULL)
		return (NULL);

	if (curr == NULL)
	{
		*tree = new;
		return (new);
	}

	while (curr)
	{
		if (value == curr->n)
		{
			free(new);
			return (NULL); /* Value already exists in the BST */
		}
		else if (value < curr->n)
		{
			if (curr->left == NULL)
			{
				curr->left = new;
				new->parent = curr;
				return (new);
			}
			curr = curr->left;
		}
		else
		{
			if (curr->right == NULL)
			{
				curr->right = new;
				new->parent = curr;
				return (new);
			}
			curr = curr->right;
		}
	}

	return (NULL);
}

