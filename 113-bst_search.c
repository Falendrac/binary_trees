#include "binary_trees.h"

/**
 * bst_search - search a value in a tree
 *
 * @tree: the tree to search to
 * @value: the value tu find
 * Return: the tree
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (tree->n == value)
		return ((bst_t *)tree);
	if (tree->n > value)
	{
		if (tree->left)
			return (bst_search(tree->left, value));
		else
			return (NULL);
	}
	else if (tree->n < value)
	{
		if (tree->right)
			return (bst_search(tree->right, value));
		else
			return (NULL);
	}

	return (NULL);
}
