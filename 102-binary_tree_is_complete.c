#include "binary_trees.h"

/**
 * create_node - Creates a new levelorder_queue_t node.
 * @node: The binary tree node for the new node to contain.
 *
 * Return: If an error occurs, NULL.
 *         Otherwise, a pointer to the new node.
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
    levelorder_queue_t *new;

    new = malloc(sizeof(levelorder_queue_t));
    if (new == NULL)
        return (NULL);

    new->node = node;
    new->next = NULL;

    return (new);
}

/**
 * free_queue - Frees a levelorder_queue_t queue.
 * @head: A pointer to the head of the queue.
 */
void free_queue(levelorder_queue_t *head)
{
    levelorder_queue_t *tmp;

    while (head != NULL)
    {
        tmp = head->next;
        free(head);
        head = tmp;
    }
}

/**
 * push - Pushes a node to the back of a levelorder_queue_t queue.
 * @node: The binary tree node to print and push.
 * @head: A double pointer to the head of the queue.
 * @tail: A double pointer to the tail of the queue.
 *
 * Description: Upon malloc failure, exits with a status code of 1.
 */
void push(binary_tree_t *node, levelorder_queue_t *head,
          levelorder_queue_t **tail)
{
    levelorder_queue_t *new;

    new = create_node(node);
    if (new == NULL)
    {
        free_queue(head);
        exit(1);
    }
    (*tail)->next = new;
    *tail = new;
}

/**
 * pop - Pops the head of a levelorder_queue_t queue.
 * @head: A double pointer to the head of the queue.
 */
void pop(levelorder_queue_t **head)
{
    levelorder_queue_t *tmp;

    tmp = (*head)->next;
    free(*head);
    *head = tmp;
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: If the tree is NULL or not complete, 0.
 *         Otherwise, 1.
 *
 * Description: This function checks if the binary tree is complete
 *              without using an explicit queue.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    if (tree->left == NULL && tree->right == NULL)
        return (1);

    if (tree->left == NULL || tree->right == NULL)
        return (0);

    return (binary_tree_is_complete(tree->left) && binary_tree_is_complete(tree->right));
}

