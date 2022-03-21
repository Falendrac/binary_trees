#include "binary_trees.h"

/**
 * binary_tree_nodes - binary that counts the nodes with minimum 1 child
 *
 * @tree: pointer to the root node of the tree to traverse
 * Return: if tree is NULL return NULL or must return 0
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t left_child = 0;
	size_t right_child = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL || tree->right != NULL)
	{
		left_child = binary_tree_nodes(tree->left);
		right_child = binary_tree_nodes(tree->right) + 1;
		return (left_child + right_child);
	}
	return (0);
}
