#include "binary_trees.h"

binary_tree_t *do_rotate_left(binary_tree_t *tree)
{
		tree->right->left = tree;
		tree->right->parent = NULL;
		tree->parent = tree->right;
		tree->right = NULL;

		return (tree->parent);
}

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 *
 * @tree: a pointer to the root node of the tree to rotate
 * Return: pointer with the new root node
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	if (!tree || ((!tree->left || tree->left) && !tree->right))
		return (tree);

	if (tree->left == NULL && tree->right->n > tree->n)
		return (binary_tree_rotate_left(do_rotate_left(tree)));
	else if (tree->right->left && tree->right->right)
	{
		tree->right->left->right = tree->right->left->parent;
		tree->right->left->parent = tree;
		tree->right = tree->right->left;
		tree->right->right->left = tree;
		tree->parent = tree->right->right;
		tree->right->right = NULL;
		tree->parent->parent = NULL;
		return (tree->parent);
	}

	return (tree);
}
