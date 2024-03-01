#include "binary_trees.h"

/**
 * bal - Measures balance factor of a AVL
 * @tree: tree to go through
 * Return: balanced factor
 */

void bal(avl_t **tree)
{
    if (tree == NULL || *tree == NULL)
        return;

    bal(&(*tree)->left);
    bal(&(*tree)->right);

    int bval = binary_tree_balance((const binary_tree_t *)*tree);

    if (bval > 1)
    {
        if (binary_tree_balance((*tree)->left) < 0)
            (*tree)->left = binary_tree_rotate_left((*tree)->left);
        *tree = binary_tree_rotate_right((binary_tree_t *)*tree);
    }
    else if (bval < -1)
    {
        if (binary_tree_balance((*tree)->right) > 0)
            (*tree)->right = binary_tree_rotate_right((*tree)->right);
        *tree = binary_tree_rotate_left((binary_tree_t *)*tree);
    }
}

/**
 * successor - Finds the minimum value in the right subtree of a BST node.
 * @node: A pointer to the BST node.
 * Return: The minimum value in the right subtree.
 */
int successor(bst_t *node)
{
    if (node == NULL)
        return 0;

    while (node->left != NULL)
        node = node->left;

    return node->n;
}

/**
 *remove_type - function that removes a node depending of its children
 *@root: node to remove
 *Return: 0 if it has no children or other value if it has
 */
int remove_type(bst_t *root)
{
	int new_value = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		new_value = successor(root->right);
		root->n = new_value;
		return (new_value);
	}
}

/**
 * bst_remove - remove a node from a BST tree
 * @root: root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */
bst_t *bst_remove(bst_t *root, int value)
{
    int type = 0;

    if (root == NULL)
        return NULL;

    if (value < root->n)
        root->left = bst_remove(root->left, value);
    else if (value > root->n)
        root->right = bst_remove(root->right, value);
    else if (value == root->n)
    {
        type = remove_type(root);
        if (type != 0)
            root->right = bst_remove(root->right, type);
    }
    else
        return NULL;

    return root;
}

/**
 * avl_remove - remove a node from an AVL tree
 * @root: root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */
avl_t *avl_remove(avl_t *root, int value)
{
    avl_t *root_a = (avl_t *)bst_remove((bst_t *)root, value);

    if (root_a == NULL)
        return (NULL);

    // Assuming 'bal' is your AVL balancing function
    bal(&root_a);

    return root_a;
}

