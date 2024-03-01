#include "binary_trees.h"

levelorder_queue_t *create_node(binary_tree_t *node);
void pop(levelorder_queue_t **head);
int binary_tree_is_complete(const binary_tree_t *tree);
void free_queue(levelorder_queue_t *head);
void push(binary_tree_t *node, levelorder_queue_t *head, levelorder_queue_t **tail);

/**
 * create_node - Creates a new node for a level-order traversal queue.
 * @node: The binary tree node to assign to the new node.
 *
 * Return: A pointer to the newly created node, or NULL on failure.
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
    levelorder_queue_t *new_node = malloc(sizeof(levelorder_queue_t));
    if (!new_node)
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    new_node->node = node;
    new_node->next = NULL;

    return new_node;
}

/**
 * free_queue - Frees a levelorder_queue_t queue.
 * @head: A pointer to the head of the queue.
 */
void free_queue(levelorder_queue_t *head)
{
    while (head)
    {
        levelorder_queue_t *tmp = head;
        head = head->next;
        free(tmp);
    }
}
/**
 * push - Enqueues a node to the back of the queue.
 * @node: The binary tree node to enqueue.
 * @rear: A pointer to the rear of the queue.
 */
void push(const binary_tree_t *node, queue_node_t **rear)
{
    queue_node_t *new = malloc(sizeof(queue_node_t));
    if (new == NULL)
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    new->node = node;
    new->next = NULL;

    (*rear)->next = new;
    *rear = new;
}

/**
 * pop - Dequeues the front of the queue.
 * @front: A double pointer to the front of the queue.
 */
void pop(queue_node_t **front)
{
    queue_node_t *tmp = (*front)->next;
    free(*front);
    *front = tmp;
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If the tree is NULL or not complete, 0.
 *         Otherwise, 1.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    queue_node_t *front = malloc(sizeof(queue_node_t));
    queue_node_t *rear = front;

    front->node = tree;
    front->next = NULL;

    int flag = 0;

    while (front != NULL)
    {
        const binary_tree_t *current = front->node;

        if (current->left != NULL)
        {
            if (flag == 1)
            {
                free(front);
                return 0;
            }
            push(current->left, &rear);
        }
        else
        {
            flag = 1;
        }

        if (current->right != NULL)
        {
            if (flag == 1)
            {
                free(front);
                return 0;
            }
            push(current->right, &rear);
        }
        else
        {
            flag = 1;
        }

        pop(&front);
    }

    free(front);
    return 1;
}
