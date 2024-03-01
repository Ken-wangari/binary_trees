#include "binary_trees.h"

/**
 * array_to_heap - This function builds a maximum binary Heap tree from an array
 * @array: a pointer to the first element of the array for convertion.
 * @size: This is the number of element in the array
 */
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int i;
	heap_t *root = NULL;

	for (i = 0; i < size; i++)
		heap_insert(&root, array[i]);

	return (root);
}
