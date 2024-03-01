#include "binary_trees.h"

/**
 * find_inorder_successor - Finds the in-order successor of a node.
 * @node: A pointer to the node.
 * Return: A pointer to the in-order successor.
 */
bst_t *find_inorder_successor(bst_t *node)
{
    while (node->left != NULL)
        node = node->left;
    return node;
}

/**
 * bst_remove_recursive - Removes a node from a binary search tree recursively.
 * @root: A pointer to the root node of the BST.
 * @node: A pointer to the current node in the BST.
 * @value: The value to remove from the BST.
 * Return: A pointer to the root node after deletion.
 */
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value)
{
    if (node == NULL)
        return root;

    if (value < node->n)
        node->left = bst_remove_recursive(root, node->left, value);
    else if (value > node->n)
        node->right = bst_remove_recursive(root, node->right, value);
    else
    {
        // Node with only one child or no child
        if (node->left == NULL)
        {
            bst_t *temp = node->right;
            free(node);
            return temp;
        }
        else if (node->right == NULL)
        {
            bst_t *temp = node->left;
            free(node);
            return temp;
        }

        // Node with two children, get the in-order successor
        bst_t *successor = find_inorder_successor(node->right);

        // Copy the in-order successor's data to this node
        node->n = successor->n;

        // Delete the in-order successor
        node->right = bst_remove_recursive(root, node->right, successor->n);
    }

    return root;
}

/**
 * bst_remove - Removes a node from a binary search tree.
 * @root: A pointer to the root node of the BST.
 * @value: The value to remove from the BST.
 * Return: A pointer to the new root node after deletion.
 */
bst_t *bst_remove(bst_t *root, int value)
{
    return bst_remove_recursive(root, root, value);
}

