#include "binary_trees.h"

/**
 * binary_tree_insert_left - Insert node at the left of the binary tree
 *
 * @parent: The previous binary tree node
 * @value: Value set in the new left node
 * Return: new Binary tree node or NULL if malloc failed
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);

	new->n = value;
	new->parent = parent;
	new->right = NULL;

	if (parent->left == NULL)
	{
		parent->left = new;
		new->left = NULL;
	}
	else
	{
		new->left = parent->left;
		new->left->parent = new;
		parent->left = new;
		new->parent = parent;
	}

	return (new);
}
