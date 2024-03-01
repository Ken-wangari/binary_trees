#include "binary_trees.h"

/**
 * find_min - Find the node with the minimum value in the BST.
 * @node: A pointer to the root node of the BST.
 * Return: A pointer to the node with the minimum value.
 */
bst_t *find_min(bst_t *node)
{
	while (node->left != NULL)
		node = node->left;
	return node;
}

/**
 * bst_remove - Removes a node from a binary search tree.
 * @root: A pointer to the root node of the BST to remove a node from.
 * @value: The value to remove in the BST.
 * Return: A pointer to the new root node after deletion.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
		return NULL;

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else {
		if (root->left == NULL) {
			bst_t *temp = root->right;
			free(root);
			return temp;
		} else if (root->right == NULL) {
			bst_t *temp = root->left;
			free(root);
			return temp;
		}

		bst_t *min_right = find_min(root->right);
		root->n = min_right->n;
		root->right = bst_remove(root->right, min_right->n);
	}
	return root;
}

