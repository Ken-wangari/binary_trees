#include "binary_trees.h"

/**
 * inorder_successor - Returns the minimum value of a binary search tree.
 * @root: A pointer to the root node of the BST to search.
 *
 * Return: The minimum value in the tree.
 */
bst_t *inorder_successor(bst_t *root)
{
    while (root->left)
        root = root->left;
    return root;
}

/**
 * bst_delete - Deletes a node from a binary search tree.
 * @root: A pointer to the root node of the BST.
 * @node: A pointer to the node to delete from the BST.
 *
 * Return: A pointer to the new root node after deletion.
 */
bst_t *bst_delete(bst_t *root, bst_t *node)
{
    bst_t *parent = node->parent, *successor = NULL;

    if (!node->left)
    {
        if (parent)
            (parent->left == node) ? (parent->left = node->right) : (parent->right = node->right);
        if (node->right)
            node->right->parent = parent;
        free(node);
        return (parent ? root : node->right);
    }
    else if (!node->right)
    {
        if (parent)
            (parent->left == node) ? (parent->left = node->left) : (parent->right = node->left);
        if (node->left)
            node->left->parent = parent;
        free(node);
        return (parent ? root : node->left);
    }
    else
    {
        successor = inorder_successor(node->right);
        node->n = successor->n;
        return bst_delete(root, successor);
    }
}

/**
 * bst_remove_recursive - Removes a node from a binary search tree recursively.
 * @root: A pointer to the root node of the BST to remove a node from.
 * @node: A pointer to the current node in the BST.
 * @value: The value to remove from the BST.
 *
 * Return: A pointer to the root node after deletion.
 */
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value)
{
    if (node)
    {
        if (value < node->n)
            return bst_remove_recursive(root, node->left, value);
        else if (value > node->n)
            return bst_remove_recursive(root, node->right, value);
        else
            return bst_delete(root, node);
    }
    return NULL;
}

/**
 * bst_remove - Removes a node from a binary search tree.
 * @root: A pointer to the root node of the BST to remove a node from.
 * @value: The value to remove in the BST.
 *
 * Return: A pointer to the new root node after deletion.
 */
bst_t *bst_remove(bst_t *root, int value)
{
    return bst_remove_recursive(root, root, value);
}

