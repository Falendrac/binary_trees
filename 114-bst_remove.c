#include "binary_trees.h"

/**
 * lowest_value - calcul the lowest value
 *
 * @root: the tree
 * Return: the tree lowest value
 */
bst_t *lowest_value(bst_t *root)
{
	while (root->left)
		root = root->left;

	return (root);
}

/**
 * delete - remove an node from an tree
 *
 * @node: the node
 * @root: the tree
 * Return: the tree
 */
bst_t *delete(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent;
	bst_t *new = NULL;
	bst_t *right = node->right;
	bst_t *left = node->left;

	if (left == NULL)
	{
		if (parent && parent->left == node)
			parent->left = right;
		else if (parent)
			parent->right = right;
		if (right)
			right->parent = parent;
		free(node);
		if (parent == NULL)
			return (right);
		else
			return (root);
	}
	if (right == NULL)
	{
		if (!parent && parent->left == node)
			parent->left = left;
		else if (parent)
			parent->right = left;
		if (left)
			left->parent = parent;
		free(node);
		if (parent == NULL)
			return (left);
		else
			return (root);
	}
	new = lowest_value(right);
	node->n = new->n;

	return (delete(root, new));
}

/**
 * remove_recurtion - remove an node from an tree by recurtion
 *
 * @node: the node
 * @root: the tree
 * @value: the value
 * Return: the tree
 */
bst_t *remove_recurtion(bst_t *root, bst_t *node, int value)
{
	if (node)
	{
		if (node->n == value)
			return (delete(root, node));
		if (node->n > value)
			return (remove_recurtion(root, node->left, value));
		return (remove_recurtion(root, node->right, value));
	}

	return (NULL);
}

/**
 * bst_remove - remove an node from an tree
 *
 * @root: the tree
 * @value: value we remove
 * Return: the tree
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (remove_recurtion(root, root, value));
}
