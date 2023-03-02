#include "binary_trees.h"

/**
 * n_height - calculates the height of a node in a tree.
 * @tree: pointer to the node in the tree.
 *
 * Return: the height of the node. If @tree is NULL returns 0.
 */

int n_height(const binary_tree_t *tree)
{
	int height = 0, l_height = 0, r_height = 0;

	if (tree == NULL)
		return (0);
	l_height = n_height(tree->left);
	r_height = n_height(tree->right);
	if (l_height > r_height)
		height = l_height;
	else
		height = r_height;

	return (height + 1);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree.
 * @tree: pointer to the root node of the tree to measure the balance factor.
 *
 * Return: Balance factor. If tree is NULL, return 0.
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	/* BalanceFactor = height(left-sutree) - height(right-sutree) */
	int b_factor = 0;

	if (tree == NULL)
		return (0);

	b_factor = n_height(tree->left) - n_height(tree->right);
	return (b_factor);
}
