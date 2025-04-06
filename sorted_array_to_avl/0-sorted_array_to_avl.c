#include "binary_trees.h"
#include <stddef.h>

/**
 * insert_recursively - Recursive helper to insert nodes in AVL fashion
 * @array: sorted input array
 * @start: start index
 * @end: end index
 * @parent: parent node
 * Return: pointer to created node or NULL
 */
avl_t *insert_recursively(int *array, int start, int end, avl_t *parent)
{
    avl_t *root;
    int mid;

    if (start > end)
        return (NULL);

    mid = (start + end) / 2;
    root = binary_tree_node(parent, array[mid]);
    if (!root)
        return (NULL);

    root->left = insert_recursively(array, start, mid - 1, root);
    root->right = insert_recursively(array, mid + 1, end, root);

    return (root);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: pointer to first element of sorted array
 * @size: size of the array
 * Return: pointer to root node or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (!array || size == 0)
        return (NULL);
    return (insert_recursively(array, 0, size - 1, NULL));
}
