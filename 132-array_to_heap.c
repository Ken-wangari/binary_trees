#include "binary_trees.h"

/**
 * array_to_heap_recursive - Recursively builds a Max Binary Heap tree from an array.
 * @root: Pointer to the root node of the heap.
 * @array: Pointer to the array.
 * @index: Index of the current element in the array.
 * @size: Size of the array.
 *
 * Return: A pointer to the root node of the created Binary Heap.
 */
heap_t *array_to_heap_recursive(heap_t *root, int *array, size_t index, size_t size)
{
    if (index < size)
    {
        root = heap_insert(&root, array[index]);
        array_to_heap_recursive(root, array, 2 * index + 1, size);
        array_to_heap_recursive(root, array, 2 * index + 2, size);
    }
    return root;
}

/**
 * array_to_heap - Builds a Max Binary Heap tree from an array.
 * @array: Pointer to the first element of the array to be converted.
 * @size: The number of elements in the array.
 *
 * Return: A pointer to the root node of the created Binary Heap.
 */
heap_t *array_to_heap(int *array, size_t size)
{
    heap_t *root = NULL;

    if (array && size > 0)
        root = array_to_heap_recursive(root, array, 0, size);

    return root;
}

