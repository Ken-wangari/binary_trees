#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes a binary tree.
 * @tree: A pointer to the root node of the tree to delete.
 */
void binary_tree_delete(binary_tree_t *tree)
{
    if (tree == NULL)
        return;

    binary_tree_t *current = tree;
    binary_tree_t *last_visited = NULL;
    binary_tree_t *temp = NULL;

    while (current != NULL)
    {
        if (current->left != NULL && last_visited != current->left && last_visited != current->right)
        {
            // Traverse left subtree
            current = current->left;
        }
        else if (current->right != NULL && last_visited != current->right)
        {
            // Traverse right subtree
            current = current->right;
        }
        else
        {
            // Delete current node and move to parent
            temp = current;
            current = current->parent;
            free(temp);
            last_visited = temp;
        }
    }
}

