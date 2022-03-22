#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 *
 * @first: pointer to the node
 * @second: pointer to the node
 * Return: NULL or the ancestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	const binary_tree_t *first_node = first;
	const binary_tree_t *second_node = second;

	if (first == NULL || second == NULL)
		return (NULL);

	for (first_node = first; first_node; first_node = first_node->parent)
		for (second_node = second; second_node; second_node = second_node->parent)
			if (first_node == second_node)
				return ((binary_tree_t *)first_node);
	return (NULL);
}
