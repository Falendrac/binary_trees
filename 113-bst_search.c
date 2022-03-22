#include "binary_trees.h"

/**
 * bst_search - bulids BST from array
 *
 * @array: the array to convert
 * @size: the size of the array
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
