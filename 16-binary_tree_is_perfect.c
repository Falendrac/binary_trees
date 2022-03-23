#include "binary_trees.h"

/**
 * binary_tree_depth - Measure the depth of a node in a binary tree
 *
 * @tree: The node we measure the depth
 * Return: 0 if tree is NULL, otherwise the depth of the node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree != NULL && tree->parent != NULL)
		return (1 + binary_tree_depth(tree->parent));

	return (0);
}

/**
 * perfect_tree - Checks if a binary tree is perfect with compare depth
 * and level
 *
 * @tree: The node we check if is perfect
 * @depth: The depth of the current tree
 * @level: The level of the current tree
 * Return: 0 is not perfect, 1 if is perfect
 */
int perfect_tree(const binary_tree_t *tree, int depth, int level)
{
	int left, right;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
	{
		if (depth == level + 1)
			return (1);
		else
			return (0);
	}

	left = perfect_tree(tree->left, depth, level + 1);
	right = perfect_tree(tree->right, depth, level + 1);

	if (left == right)
		return (1);

	return (0);
}


/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 *
 * @tree: The node we check if is perfect
 * Return: 0 if tree is NULL, 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int depth = binary_tree_depth(tree);

	return (perfect_tree(tree, depth, 0));
}
