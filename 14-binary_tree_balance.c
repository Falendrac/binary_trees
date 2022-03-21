#include "binary_trees.h"

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 *
 * @tree: The node we measure the balance factor
 * Return: 0 if tree is NULL, otherwise the measure of balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		left = 1 + binary_tree_balance(tree->left);
	else
		left = 0;

	if (tree->right != NULL)
		right = 1 + binary_tree_balance(tree->right);
	else
		right = 0;

	return (left - right);
}
