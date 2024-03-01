#include "binary_trees.h"

/**
 * tree_size_alternative - measures the size of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the size
 * Return: size of the tree or 0 if tree is NULL
 */
size_t tree_size_alternative(const binary_tree_t *tree)
{
    size_t size_left = 0, size_right = 0;

    if (tree)
    {
        size_left = tree_size_alternative(tree->left);
        size_right = tree_size_alternative(tree->right);
        return (size_left + size_right + 1);
    }

    return 0;
}

/**
 * heap_to_sorted_array - converts a Binary Max Heap
 * to a sorted array of integers
 *
 * @heap: pointer to the root node of the heap to convert
 */

int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int i, *a = NULL;

	if (!heap || !size)
		return (NULL);

	*size = tree_size(heap) + 1;

	a = malloc(sizeof(int) * (*size));

	if (!a)
		return (NULL);

	for (i = 0; heap; i++)
		a[i] = heap_extract(&heap);

	return (a);
}
