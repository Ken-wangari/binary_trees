#include "binary_trees.h"
#include <stdlib.h>


#include "binary_trees.h"

/**
 * swap_nodes - swaps values between two nodes
 * @node1: first node
 * @node2: second node
 */
void swap_nodes(heap_t *node1, heap_t *node2)
{
    int temp = node1->n;
    node1->n = node2->n;
    node2->n = temp;
}

/**
 * find_last_node - finds the last node in the binary heap
 * @root: pointer to the root of the binary heap
 * @height: height of the tree
 * Return: pointer to the last node
 */
heap_t *find_last_node(heap_t *root, size_t height)
{
    if (!root)
        return NULL;

    if (height == 0)
        return root;

    height--;

    heap_t *left_last = find_last_node(root->left, height);
    heap_t *right_last = find_last_node(root->right, height);

    return right_last ? right_last : left_last;
}

/**
 * heapify_down - restores the Max Heap property by moving a node down
 * @root: pointer to the root of the binary heap
 */
void heapify_down(heap_t *root)
{
    heap_t *tmp = root;

    while (tmp->left || tmp->right)
    {
        heap_t *max_child = (tmp->right && tmp->right->n > tmp->left->n) ? tmp->right : tmp->left;

        if (max_child->n <= tmp->n)
            break;

        swap_nodes(tmp, max_child);
        tmp = max_child;
    }
}

/**
 * heap_extract - extracts the root node from a Max Binary Heap
 * @root: pointer to the heap root
 * Return: value of extracted node
 */
int heap_extract(heap_t **root)
{
    if (!root || !*root)
        return 0;

    heap_t *heap_root = *root;
    int value = heap_root->n;

    heap_t *last_node = find_last_node(heap_root, tree_height(heap_root));

    if (last_node)
    {
        swap_nodes(heap_root, last_node);

        if (last_node->parent)
        {
            if (last_node->parent->left == last_node)
                last_node->parent->left = NULL;
            else
                last_node->parent->right = NULL;
        }

        free(last_node);
        heapify_down(heap_root);
        *root = heap_root;
    }
    else
    {
        free(*root);
        *root = NULL;
    }

    return value;
}

