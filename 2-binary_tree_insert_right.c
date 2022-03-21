#include "binary_trees.h"

/**
 * binary_tree_insert_right - Insert a node as the right-child of another node
 *
 * @parent: The previous binary tree node
 * @value: Value set in the new right node
 * Return: new Binary tree node or NULL if malloc failed
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);

	new->n = value;
	new->parent = parent;
	new->left = NULL;

	if (parent->right == NULL)
	{
		parent->right = new;
		new->right = NULL;
	}
	else
	{
		new->right = parent->right;
		new->right->parent = new;
		parent->right = new;
		new->parent = parent;
	}

	return (new);
}
