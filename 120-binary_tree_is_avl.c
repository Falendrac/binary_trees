#include "binary_trees.h"

/**
 * binary_tree_height - binary that measures the height of left binary tree
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

	if (tree)
	{
		left_height = tree->left ? binary_tree_height(tree->left) + 1 : 1;
		right_height = tree->right ? binary_tree_height(tree->right) + 1 : 1;
		if (left_height > right_height)
			return (left_height);
		else
			return (right_height);
	}
	return (0);
}

/**
 * @brief
 *
 * @param tree
 * @param int_min
 * @param int_max
 * @return int
 */
int check_avl(const binary_tree_t *tree, int int_min, int int_max)
{
	size_t difference;

	if (tree != NULL)
	{
		if (tree->n < int_min || tree->n > int_max)
			return (0);
		if (binary_tree_height(tree->left) > binary_tree_height(tree->right))
			difference = binary_tree_height(tree->left) - binary_tree_height(tree->right);
		else
			difference = binary_tree_height(tree->right) - binary_tree_height(tree->left);
		if (difference > 1)
			return (0);
		return (check_avl(tree->left, int_min, tree->n - 1) &&
				check_avl(tree->right, tree->n + 1, int_max));
	}
	return (1);
}

/**
 * binary_tree_is_avl :
 *
 * @tree:
 * Return: NULL or 1
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (check_avl(tree, -2147483647, 2147483647));
}
