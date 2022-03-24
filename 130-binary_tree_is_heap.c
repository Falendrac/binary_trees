#include "binary_trees.h"

#include "binary_trees.h"

/**
 * binary_tree_size - binary that measures the size of a binary tree
 *
 * @tree: pointer to the root node of the tree to traverse
 * Return: if tree is NULL return NULL or must return 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_size = 0;
	size_t right_size = 0;

	if (tree == NULL)
		return (0);

	left_size = binary_tree_size(tree->left);
	right_size = binary_tree_size(tree->right) + 1;

	return (left_size + right_size);
}

/**
 * b_tree_is_complete - checks if a binary tree is perfect
 *
 * @tree: The node we check if is perfect
 * @i: int
 * @node: int node
 * Return: 0 if tree is NULL, 1 if the tree is perfect, 0 otherwise
 */
int b_tree_is_complete(const binary_tree_t *tree, int i, int node)
{
	if (tree == NULL)
		return (1);

	if (i >= node)
		return (0);

	return (b_tree_is_complete(tree->left, (2 * i) + 1, node) &&
			b_tree_is_complete(tree->right, (2 * i) + 2, node));
}

/**
 * binary_tree_is_complete - check if the binary tree is complete
 *
 * @tree: is a pointer to the root of the tree
 * Return: 0 or 1
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t nodes;

	if (tree == NULL)
		return (0);
	nodes = binary_tree_size(tree);

	return (b_tree_is_complete(tree, 0, nodes));
}

/**
 * check_parent - function that test the parent
 *
 * @tree: is a pointer to the root of the tree
 * Return: 0 or 1
 */
int check_parent(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->n > tree->parent->n)
		return (0);

	return (check_parent(tree->left) && check_parent(tree->right));
}

/**
 * binary_tree_is_heap - function that test if it's a heap
 *
 * @tree: is a pointer to the root of the tree
 * Return: 0 or 1
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!binary_tree_is_complete(tree))
		return (0);

	return (check_parent(tree->left) && check_parent(tree->right));
}
