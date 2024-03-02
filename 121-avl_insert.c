#include "binary_trees.h"

/**
 * height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, return 0, else return height.
 */
size_t height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	size_t l_height = height(tree->left);
	size_t r_height = height(tree->right);

	return (1 + (l_height > r_height ? l_height : r_height));
}

/**
 * balance - Measures the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the balance factor.
 *
 * Return: If tree is NULL, return 0, else return balance factor.
 */
int balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return height(tree->left) - height(tree->right);
}

/**
 * avl_insert_recursive - Inserts a value into an AVL tree recursively.
 * @tree: A double pointer to the root node of the AVL tree to insert into.
 * @parent: The parent node of the current working node.
 * @new: A double pointer to store the new node.
 * @value: The value to insert into the AVL tree.
 *
 * Return: A pointer to the new root after insertion, or NULL on failure.
 */
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent, avl_t **new, int value)
{
	if (*tree == NULL)
		return (*new = binary_tree_node(parent, value));

	if (value < (*tree)->n)
		(*tree)->left = avl_insert_recursive(&(*tree)->left, *tree, new, value);
	else if (value > (*tree)->n)
		(*tree)->right = avl_insert_recursive(&(*tree)->right, *tree, new, value);
	else
		return (*tree);

	int bfactor = balance(*tree);

	if (bfactor > 1 && value < (*tree)->left->n)
		*tree = binary_tree_rotate_right(*tree);
	else if (bfactor < -1 && value > (*tree)->right->n)
		*tree = binary_tree_rotate_left(*tree);
	else if (bfactor > 1 && value > (*tree)->left->n)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bfactor < -1 && value < (*tree)->right->n)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return *tree;
}

/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tree: A double pointer to the root node of the AVL tree to insert into.
 * @value: The value to insert into the AVL tree.
 *
 * Return: A pointer to the inserted node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (tree == NULL)
		return NULL;

	avl_insert_recursive(tree, *tree, &new, value);
	return new;
}

