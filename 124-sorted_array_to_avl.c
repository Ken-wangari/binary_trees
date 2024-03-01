#include "binary_trees.h"

/**
 * create_tree - creates an AVL tree with recursion
 *
 * @node: pointer node
 * @array: input array of integers
 * @start: start index of the current array segment
 * @end: end index of the current array segment
 * Return: no return
 */
void create_tree(avl_t **node, int *array, size_t start, size_t end)
{
    if (start > end)
        return;

    size_t middle = (start + end) / 2;

    (*node) = binary_tree_node(NULL, array[middle]);

    if (*node == NULL)
        return;

    create_tree(&((*node)->left), array, start, middle - 1);
    create_tree(&((*node)->right), array, middle + 1, end);
}

/**
 * sorted_array_to_avl - creates root node and calls to create_tree
 *
 * @array: input array of integers
 * @size: size of array
 * Return: pointer to the root
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (array == NULL || size == 0)
        return (NULL);

    avl_t *root = NULL;

    create_tree(&root, array, 0, size - 1);

    return root;
}

