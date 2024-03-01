/**
 * swap - swaps nodes when child is greater than parent
 *
 * @parent_node: parent node
 * @new_node: child node
 * Return: no return
 */
void swap(heap_t **parent_node, heap_t **new_node)
{
    heap_t *parent = *parent_node, *child = *new_node;
    heap_t *node_child, *node_left, *node_right;

    if (child->n > parent->n)
    {
        // ... (unchanged code)
    }
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 *
 * @tree: tree root
 * Return: 1 if tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    if (tree && height(tree->left) == height(tree->right))
    {
        if (height(tree->left) == -1)
            return (1);

        if (!tree->left->left && !tree->left->right &&
            !tree->right->left && !tree->right->right)
            return (1);

        if (tree && tree->left && tree->right)
            return (binary_tree_is_perfect(tree->left) &&
                    binary_tree_is_perfect(tree->right));
    }

    return (0);
}

/**
 * heap_insert - function that inserts a value in Max Binary Heap
 * @value: value to be inserted
 * @root: tree root
 * Return: pointer to the created node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node;

    if (*root == NULL)
    {
        *root = binary_tree_node(NULL, value);
        return (*root);
    }

    if (binary_tree_is_perfect(*root) || !binary_tree_is_perfect((*root)->left))
    {
        if ((*root)->left)
        {
            new_node = heap_insert(&((*root)->left), value);
            swap(root, &((*root)->left));
            return (new_node);
        }
        else
        {
            new_node = (*root)->left = binary_tree_node(*root, value);
            swap(root, &((*root)->left));
            return (new_node);
        }
    }

    if ((*root)->right)
    {
        new_node = heap_insert(&((*root)->right), value);
        swap(root, (&(*root)->right));
        return (new_node);
    }
    else
    {
        new_node = (*root)->right = binary_tree_node(*root, value);
        swap(root, &((*root)->right));
        return (new_node);
    }
}

