#include "binary_trees.h"

size_t height(const binary_tree_t *tree);
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent, avl_t **new, int value);
int balance(const binary_tree_t *tree);
avl_t *avl_insert(avl_t **tree, int value);

size_t height(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		r = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}

int balance(const binary_tree_t *tree)
{
    size_t left_height = tree && tree->left ? height(tree->left) : 0;
    size_t right_height = tree && tree->right ? height(tree->right) : 0;

    return (int)(left_height - right_height);
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
    {
        *new = binary_tree_node(parent, value);
        return *new;
    }

    if (value < (*tree)->n)
    {
        (*tree)->left = avl_insert_recursive(&(*tree)->left, *tree, new, value);
    }
    else if (value > (*tree)->n)
    {
        (*tree)->right = avl_insert_recursive(&(*tree)->right, *tree, new, value);
    }
    else
    {
        return *tree;  // Duplicate values are not allowed
    }

    int bfactor = balance(*tree);

    if (bfactor > 1)
    {
        if (value < (*tree)->left->n)
            *tree = binary_tree_rotate_right(*tree);
        else
        {
            (*tree)->left = binary_tree_rotate_left((*tree)->left);
            *tree = binary_tree_rotate_right(*tree);
        }
    }
    else if (bfactor < -1)
    {
        if (value > (*tree)->right->n)
            *tree = binary_tree_rotate_left(*tree);
        else
        {
            (*tree)->right = binary_tree_rotate_right((*tree)->right);
            *tree = binary_tree_rotate_left(*tree);
        }
    }

    return *tree;
}

avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avl_insert_recursive(tree, *tree, &new, value);
	return (new);
}
