#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect.
 * @tree: pointer to the root node of the tree to check.
 *
 * Return: 1 if @tree is perfect, 0 if not or ir @tree is NULL.
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int l_perfect = 0, r_perfect = 0;

	if (tree == NULL)
		return (0);

	/* is perfect if all nodes (not leaves) are full sub-trees */
	/* and if height of left and right are the same*/

	if (tree->parent == NULL)
	{
		l_perfect = binary_tree_is_perfect(tree->left);
		r_perfect = binary_tree_is_perfect(tree->right);
		if (l_perfect != r_perfect)
			return (0);
		return (1);
	}
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	else if (tree->left == NULL || tree->right == NULL)
		return (0);

	l_perfect = binary_tree_is_perfect(tree->left);
	l_perfect = (1 + l_perfect) * l_perfect;
	r_perfect = binary_tree_is_perfect(tree->right);
	r_perfect = (1 + r_perfect) * r_perfect;
	if (l_perfect != r_perfect)
		return (0);
	return (l_perfect);
}
