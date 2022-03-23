#include "binary_trees.h"

/**
 * binary_tree_sibling - binary that find the siblings of a node
 *
 * @node: pointer to the node to find the siblings
 * Return: NULL or the siblings
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL)
		return (NULL);
	if (node->parent == NULL)
		return (NULL);

	if (node == node->parent->right)
		return (node->parent->left);
	return (node->parent->right);
}
