#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree.
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: a size_t value of the hegiht, if tree is NULL return 0.
 */


size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height = 0, r_height = 0, l_height = 0;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);

	l_height = binary_tree_height(tree->left);
	r_height = binary_tree_height(tree->right);

	if (l_height > r_height)
		height = l_height;
	else
		height = r_height;

	return (height + 1);
}
