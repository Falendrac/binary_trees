#include "binary_trees.h"

/**
 * node_less - checks if the node is less
 *
 * @tree: pointer to the root node of the tree to check
 * @node_tested: the node to test with
 * Return: 1 if tree is a valid BST, 0 otherwise or tree is NULL
 */
int node_less(const binary_tree_t *tree, int node_tested)
{
	if (tree == NULL)
		return (1);
	if (tree->n < node_tested)
		if (node_less(tree->left, node_tested) &&
			node_less(tree->right, node_tested))
			return (1);
	return (0);
}

/**
 * node_great - checks if the node is greater
 *
 * @tree: pointer to the root node of the tree to check
 * @node_tested: the node to test with
 * Return: 1 if tree is a valid BST, 0 otherwise or tree is NULL
 */
int node_great(const binary_tree_t *tree, int node_tested)
{
	if (tree == NULL)
		return (1);
	if (tree->n > node_tested)
		if (node_great(tree->left, node_tested) &&
			node_great(tree->right, node_tested))
			return (1);
	return (0);
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 *
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, 0 otherwise or tree is NULL
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (0);

	left = node_less(tree->left, tree->n);
	right = node_great(tree->right, tree->n);

	return (left && right);
}
