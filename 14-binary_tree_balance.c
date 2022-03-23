#include "binary_trees.h"


/**
 * binary_tree_height - binary that measures the height of a binary tree
 *
 * @tree: pointer to the root node of the tree to traverse
 * Return: if tree is NULL return NULL or must return 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	left_height = binary_tree_height(tree->left) + 1;
	right_height = binary_tree_height(tree->right) + 1;

	if (left_height > right_height)
		return (left_height);
	else
		return (right_height);
}


/**
 * binary_tree_balance - measures the balance factor of a binary tree
 *
 * @tree: The node we measure the balance factor
 * Return: 0 if tree is NULL, otherwise the measure of balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int heightLeft = 0, heightRight = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		heightLeft = binary_tree_height(tree->left) + 1;
	if (tree->right != NULL)
		heightRight = binary_tree_height(tree->right) + 1;

	return (heightLeft - heightRight);
}
