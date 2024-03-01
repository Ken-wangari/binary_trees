#include "binary_trees.h"

/**
 * binary_trees_ancestor - function finds the lowest common ancestor of two nodes.
 * @first: Pointer to the 1st
 * @second: Pointer to the 2nd.
 *
 * Return: If there's no common ancestors return NULL, if not return common ancestor.
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
                                     const binary_tree_t *second)
{
    const binary_tree_t *mom = first, *pop = second;

    if (!first || !second)
        return NULL;

    if (first == second)
        return (binary_tree_t *)first;

    while (mom != pop)
    {
        mom = (mom ? mom->parent : second);
        pop = (pop ? pop->parent : first);
    }

    return (binary_tree_t *)mom;
}
