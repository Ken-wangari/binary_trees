#include "binary_trees.h"

unsigned char is_leaf(const binary_tree_t *node);
const binary_tree_t *get_leaf(const binary_tree_t *tree);
size_t depth(const binary_tree_t *tree);
int is_perfect_recursive(const binary_tree_t *tree, size_t leaf_depth, size_t level);
int binary_tree_is_perfect(const binary_tree_t *tree);

/**
 * isleaf_ - function checks if a node is a leaf of a binary tree.
 * @node:  pointer to the node to check.
 */

unsigned char is_leaf(const binary_tree_t *node)
{
    if (node == NULL)
        return 0;

    return (node->left == NULL && node->right == NULL) ? 1 : 0;
}

/**
 * depth - function returns the depth of a given node.
 * @tree: pointer that points to the node to measure the depth of node.
 */

#include <stddef.h>

size_t depth(const binary_tree_t *tree)
{
    size_t depth_count = 0;

    while (tree != NULL && tree->parent != NULL)
    {
        depth_count++;
        tree = tree->parent;
    }

    return depth_count;
}
/**
 * get_leaf - function returns a leaf of a binary tree.
 * @tree: pointer that points to the root node to find a leaf in.
 *
 * Return:  pointer to the first encountered leaf.
 */

const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree) == 1)
		return (tree);
	return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}

#include "binary_trees.h"

/**
 * is_perfect_recursive - Checks if a binary tree is perfect recursively.
 * @tree: A pointer to the root node of the tree to check.
 * @leaf_depth: The depth of one leaf in the binary tree.
 * @level: Level of the current node.
 *
 * Return: If the tree is perfect, 1, otherwise 0.
 */
int is_perfect_recursive(const binary_tree_t *tree,
                         size_t leaf_depth, size_t level)
{
    if (tree == NULL)
        return (level == leaf_depth);

    if (tree->left == NULL && tree->right == NULL)
        return (level == leaf_depth);

    if (tree->left == NULL || tree->right == NULL)
        return 0;

    return (is_perfect_recursive(tree->left, leaf_depth, level + 1) &&
            is_perfect_recursive(tree->right, leaf_depth, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If the tree is NULL or not perfect, 0.
 *         Otherwise, 1.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    size_t leaf_depth = 0;
    const binary_tree_t *leaf = tree;

    while (leaf->left != NULL)
    {
        leaf = leaf->left;
        leaf_depth++;
    }

    return is_perfect_recursive(tree, leaf_depth, 0);
}

