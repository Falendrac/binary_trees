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
