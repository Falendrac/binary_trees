#include "binary_trees.h"


/**
 * binary_tree_rotate_left - performs a right-rotation on a binary tree
 *
 * @tree: a pointer to the root node of the tree to rotate
 * Return: pointer with the new root node
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	if (tree == NULL)
		return (NULL);

	tree->parent = tree->right;
	if (tree->right)
	{
		tree->right = tree->right->left;
		tree->parent->left = tree;
		tree->parent->parent = NULL;
		if (tree->right)
			tree->right->parent = tree;
		return (tree->parent);
	}

	return (tree);
}
