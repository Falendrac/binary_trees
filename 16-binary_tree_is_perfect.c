#include "binary_trees.h"

/**
 * binary_tree_size - binary that measures the size of a binary tree
 *
 * @tree: pointer to the root node of the tree to traverse
 * Return: if tree is NULL return NULL or must return 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_size = 0;
	size_t right_size = 0;

	if (tree == NULL)
		return (0);

	left_size = binary_tree_size(tree->left);
	right_size = binary_tree_size(tree->right) + 1;

	return (left_size + right_size);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 *
 * @tree: The node we check if is perfect
 * Return: 0 if tree is NULL, 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int sizeLeft, sizeRight, perfectLeft, perfectRight;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	perfectLeft = binary_tree_is_perfect(tree->left);
	perfectRight = binary_tree_is_perfect(tree->left);

	sizeLeft = binary_tree_size(tree->left);
	sizeRight = binary_tree_size(tree->right);

	return (sizeLeft - sizeRight == 0 && perfectLeft && perfectRight);
}
