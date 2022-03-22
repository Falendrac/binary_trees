#include "binary_trees.h"

void do_levelorder(const binary_tree_t *tree, void (*func)(int), int level)
{
	if (tree == NULL)
		return;

	if (level == 0)
		func(tree->n);
	else if (level > 0)
	{
		do_levelorder(tree->left, func, level - 1);
		do_levelorder(tree->right, func, level - 1);

	}
}

/**
 * binary_tree_levelorder - binary tree using level-order traversal
 *
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t loop;

	if (tree == NULL || func == NULL)
		return;

	for (loop = 0; loop <= binary_tree_height(tree); loop++)
		do_levelorder(tree, func, loop);
}

/**
 * binary_tree_height - binary that measures the height of a binary tree
 *
 * @tree: pointer to the root node of the tree to traverse
 * Return: if tree is NULL return NULL or must return 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	left_height = binary_tree_height(tree->left) + 1;
	right_height = binary_tree_height(tree->right) + 1;

	if (left_height > right_height)
		return (left_height);
	else
		return (right_height);
}
