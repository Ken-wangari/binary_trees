#include "binary_trees.h"

/**
 * balance_tree - Balances an AVL tree.
 * @tree: A double pointer to the root node of the AVL tree.
 */
void balance_tree(avl_t **tree)
{
	int balance_factor;

	if (tree == NULL || *tree == NULL)
		return;

	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;

	balance_tree(&(*tree)->left);
	balance_tree(&(*tree)->right);

	balance_factor = binary_tree_balance((const binary_tree_t *)*tree);

	if (balance_factor > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (balance_factor < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * get_successor - Finds the successor of a given node in the BST.
 * @node: The node to find the successor for.
 * Return: The value of the successor.
 */
int get_successor(bst_t *node)
{
	int left = 0;

	if (node == NULL)
		return (0);

	left = get_successor(node->left);

	if (left == 0)
		return (node->n);

	return (left);
}

/**
 * remove_node - Removes a node from the BST depending on its children.
 * @node: The node to remove.
 * Return: The value of the node to remove.
 */
int remove_node(bst_t *node)
{
	int new_value = 0;

	if (!node->left && !node->right)
	{
		if (node->parent->right == node)
			node->parent->right = NULL;
		else
			node->parent->left = NULL;

		free(node);
		return (0);
	}
	else if ((!node->left && node->right) || (!node->right && node->left))
	{
		if (!node->left)
		{
			node->parent->right = node->right;
			node->right->parent = node->parent;
		}
		if (!node->right)
		{
			node->parent->left = node->left;
			node->left->parent = node->parent;
		}

		free(node);
		return (0);
	}
	else
	{
		new_value = get_successor(node->right);
		node->n = new_value;
		return (new_value);
	}
}

/**
 * bst_remove - Removes a node from a BST tree.
 * @root: The root of the tree.
 * @value: The value of the node to remove.
 * Return: The tree after removal.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		type = remove_node(root);

		if (type != 0)
			bst_remove(root->right, type);
	}

	return (root);
}

/**
 * avl_remove - Removes a node from an AVL tree.
 * @root: The root of the tree.
 * @value: The value of the node to remove.
 * Return: The tree after removal.
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_a = (avl_t *)bst_remove((bst_t *)root, value);

	if (root_a == NULL)
		return (NULL);

	balance_tree(&root_a);
	return (root_a);
}

