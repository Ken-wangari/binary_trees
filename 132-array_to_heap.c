#include "binary_trees.h"

/**
 * array_to_heap - builds a Max Binary Heap tree from an array
 * @array: a pointer to the first element of the array to be converted
 * @size: the number of element in the array
 *
 * Return: a pointer to the root node of the created Binary Heap
 *         NULL on failure
 */

heap_t *array_to_heap(int *array, size_t size)
{
    heap_t *root = NULL;

    if (!array || size == 0)
        return NULL;

    for (size_t i = 0; i < size; i++)
    {
        heap_t *new_node = binary_tree_node(NULL, array[i]);
        if (!new_node)
        {
            /* Handle memory allocation failure */
            while (root)
            {
                heap_extract(&root);
            }
            return NULL;
        }

        root = heap_insert(&root, array[i]);

        if (!root)
        {
            free(new_node);
            /* Handle heap insertion failure */
            while (root)
            {
                heap_extract(&root);
            }
            return NULL;
        }
    }

    return root;
}
