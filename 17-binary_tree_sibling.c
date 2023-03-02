#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: pointer to the node
 *
 * Return: pointer to sibling node or NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);
	if (binary_tree_is_perfect(node->parent))
		return (node == node->parent->left ? node->parent->right :
			node->parent->left);
	return (NULL);
}
