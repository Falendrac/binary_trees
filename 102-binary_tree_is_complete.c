#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Checks if a node is a leaf
 *
 * @node: pointer to the node to check
 * Return: 1 if node is a leaf, 0 otherwise and 0 if node is NULL
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node != NULL && node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}

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

	left_height = binary_tree_height(tree->left) + 1;
	right_height = binary_tree_height(tree->right) + 1;

	if (left_height >= right_height)
		return (left_height);
	return (right_height);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 *
 * @tree: The node we check if is perfect
 * Return: 0 if tree is NULL, 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (binary_tree_is_leaf(tree))
		return (1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	if (binary_tree_height(tree->left) == binary_tree_height(tree->right))
		if (binary_tree_is_perfect(tree->left) &&
			binary_tree_is_perfect(tree->right))
			return (1);
	return (0);
}

/**
 * binary_tree_is_complete - check if the binary tree is complete
 *
 * @tree: is a pointer to the root of the tree
 * Return: 0 or 1
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (binary_tree_is_leaf(tree))
		return (1);
	if (binary_tree_height(tree->left) ==
		binary_tree_height(tree->right))
	{
		if (binary_tree_is_perfect(tree->left) &&
			binary_tree_is_complete(tree->right))
			return (1);
	}
	else if (binary_tree_height(tree->left) ==
			 binary_tree_height(tree->right) + 1)
		if (binary_tree_is_complete(tree->left) &&
			binary_tree_is_perfect(tree->right))
			return (1);
	return (0);
}
