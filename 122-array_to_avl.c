#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from an array of integers.
 * @array: Pointer to the first element of the array.
 * @size: Number of elements in the array.
 *
 * Return: A pointer to the root of the constructed AVL tree,
 *         or NULL on failure.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;

	if (array == NULL || size == 0)
		return NULL;

	for (size_t i = 0; i < size; ++i)
	{
		/* Check for duplicates in the array */
		size_t j;
		for (j = 0; j < i; ++j)
		{
			if (array[j] == array[i])
				break;
		}

		/* If no duplicate found, insert into AVL tree */
		if (j == i)
		{
			if (avl_insert(&tree, array[i]) == NULL)
				return NULL;
		}
	}

	return tree;
}

