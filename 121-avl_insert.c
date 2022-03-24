#include "binary_trees.h"

/**
 * avl_balance_check_left - Check if the left of a tree is balance
 * and rotate if not
 *
 * @tree: double pointer to the root node of the AVL tree
 */
void avl_balance_check_left(avl_t **tree)
{
	int balance;
	avl_t *tmp;

	balance = binary_tree_balance((*tree)->left);

	if (balance > 1)
	{
		if (binary_tree_balance((*tree)->left->left) < 0)
		{
			tmp = binary_tree_rotate_left((*tree)->left->left);
			tmp->parent = ((*tree)->left);
			(*tree)->left->left = tmp;
		}
		tmp = binary_tree_rotate_right((*tree)->left);
		tmp->parent = *tree;
		(*tree)->left = tmp;
	}
	else if (balance < -1)
	{
		if (binary_tree_balance((*tree)->left->right) > 0)
		{
			tmp = binary_tree_rotate_right((*tree)->left->right);
			tmp->parent = ((*tree)->left);
			(*tree)->left->right = tmp;
		}
		tmp = binary_tree_rotate_left((*tree)->left);
		tmp->parent = *tree;
		(*tree)->left = tmp;
	}
}

/**
 * avl_balance_check_right - Check if the right of a tree is balance
 * and rotate if not
 *
 * @tree: double pointer to the root node of the AVL tree
 */
void avl_balance_check_right(avl_t **tree)
{
	int balance;
	avl_t *tmp;

	balance = binary_tree_balance((*tree)->right);

	if (balance > 1)
	{
		if (binary_tree_balance((*tree)->right->left) < 0)
		{
			tmp = binary_tree_rotate_left((*tree)->right->left);
			tmp->parent = ((*tree)->right);
			(*tree)->right->left = tmp;
		}
		tmp = binary_tree_rotate_right((*tree)->right);
		tmp->parent = *tree;
		(*tree)->right = tmp;
	}
	else if (balance < -1)
	{
		if (binary_tree_balance((*tree)->right->right) > 0)
		{
			tmp = binary_tree_rotate_right((*tree)->right->right);
			tmp->parent = ((*tree)->right);
			(*tree)->right->right = tmp;
		}
		tmp = binary_tree_rotate_left((*tree)->right);
		tmp->parent = *tree;
		(*tree)->right = tmp;
	}
}

/**
 * avl_insertion - function to insert the node
 *
 * @tree: pointer to the root node of the tree to check
 * @new: the value to store
 * Return: 0 or 1
 */
int avl_insertion(avl_t *tree, avl_t *new)
{
	if (tree->n == new->n)
		return (0);
	if (tree->n > new->n)
	{
		if (tree->left)
			return (avl_insertion(tree->left, new));
		new->parent = tree;
		tree->left = new;
	}
	else if (tree->n < new->n)
	{
		if (tree->right)
			return (avl_insertion(tree->right, new));
		new->parent = tree;
		tree->right = new;
	}

	return (1);
}

/**
 * avl_insert - inserts a value in an AVL Tree
 *
 * @tree: double pointer to the root node of the AVL tree
 * @value: value to store in the node to be inserted
 * Return: The pointer to the new node, NULL on faillure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new;

	new = binary_tree_node(*tree, value);
	if (new == NULL)
		return (NULL);

	if (*tree == NULL)
		*tree = new;
	else if (avl_insertion(*tree, new) == 0)
	{
		free(new);
		return (NULL);
	}

	avl_balance_check_right(tree);
	avl_balance_check_left(tree);

	return (new);
}
