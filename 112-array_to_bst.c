#include "binary_trees.h"

/**
 * array_to_bst - bulids BST from array
 *
 * @array: the array to convert
 * @size: the size of the array
 * Return: the tree
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t index;

	if (array == NULL)
		return (NULL);

	for (index = 0; index < size; index++)
		bst_insert(&tree, array[index]);

	return (tree);
}
