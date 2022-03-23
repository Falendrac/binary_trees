#include "binary_trees.h"

/**
 * bst_insertion - function to insert the node
 *
 * @tree: pointer to the root node of the tree to check
 * @new: the value to store
 * Return: 0 or 1
 */
int bst_insertion(bst_t *tree, bst_t *new)
{
	if (tree->n == new->n)
		return (0);
	if (tree->n > new->n)
	{
		if (tree->left)
			return (bst_insertion(tree->left, new));
		new->parent = tree;
		tree->left = new;
	}
	else if (tree->n < new->n)
	{
		if (tree->right)
			return (bst_insertion(tree->right, new));
		new->parent = tree;
		tree->right = new;
	}

	return (1);
}

/**
 * bst_insert - insert a value in a BST
 *
 * @tree: pointer to the root node of the tree to check
 * @value: the value to store
 * Return: the new tree
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new;

	new = binary_tree_node(*tree, value);
	if (new == NULL)
		return (NULL);

	if (*tree == NULL)
		*tree = new;
	else if (bst_insertion(*tree, new) == 0)
	{
		free(new);
		return (NULL);
	}

	return (new);
}
