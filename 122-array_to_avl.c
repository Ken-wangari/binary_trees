#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from an array of integers.
 * @array: A pointer to the first element of the array.
 * @size: The number of elements in the array.
 *
 * Return: A pointer to the root of the created AVL tree, or NULL on failure.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t i;

	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		if (avl_insert(&tree, array[i]) == NULL)
		{
			/* Handle insertion failure, e.g., by freeing the existing tree */
			avl_delete_tree(tree);
			return (NULL);
		}
	}

	return (tree);
}

/**
 * avl_delete_tree - Deletes an AVL tree.
 * @tree: A pointer to the root of the AVL tree to delete.
 */
void avl_delete_tree(avl_t *tree)
{
	if (tree != NULL)
	{
		avl_delete_tree(tree->left);
		avl_delete_tree(tree->right);
		free(tree);
	}
}

