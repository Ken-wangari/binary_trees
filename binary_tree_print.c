#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

void print_tree(const binary_tree_t *tree, int space);

void binary_tree_print(const binary_tree_t *tree)
{
    if (tree == NULL)
        return;

    // Print the tree with initial space
    print_tree(tree, 0);
}

void print_tree(const binary_tree_t *tree, int space)
{
    // Base case
    if (tree == NULL)
        return;

    // Increase distance between levels
    space += 5;

    // Process right child first
    print_tree(tree->right, space);

    // Print current node after space
    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("%d\n", tree->n);

    // Process left child
    print_tree(tree->left, space);
}

