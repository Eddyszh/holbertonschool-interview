#include "binary_trees.h"
/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: the number of element in the array
 * Return: pointer to the root node of the created AVL tree, NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	int mid;
	avl_t *root = NULL;

	if (size == 0)
		return (NULL);
	if (size % 2 == 0)
		mid = (size / 2) - 1;
	else
		mid = size / 2;
	root = avl_node(NULL, array[mid]);
	avl_tree(array, 0, mid, root);
	avl_tree(array, mid + 1, size, root);
	return (root);
}

/**
 * avl_node - creates avl nodes
 * @parent: pointer to parent
 * @value: value of the node
 * Return: pointer to new node, NULL on failure
 */
avl_t *avl_node(avl_t *parent, int value)
{
	avl_t *new = NULL;

	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);
	new->n = value;
	new->left = NULL;
	new->right = NULL;
	new->parent = parent;
	if (parent != NULL)
	{
		if (new->n > parent->n)
			parent->right = new;
		else
			parent->left = new;
	}
	return (new);
}

/**
 * avl_tree - creates tree with recursion
 * @array: sorted array to create tree
 * @left: left index
 * @right: right index
 * @parent: parent of new node
 */
void avl_tree(int *array, size_t left, size_t right, avl_t *parent)
{
	int mid;
	size_t size;
	avl_t *new = NULL;

	size = (right + 1) - left;
	mid = left + (size / 2) - 1;
	if (left < right)
	{
		new = avl_node(parent, array[mid]);
		avl_tree(array, left, mid, new);
		avl_tree(array, mid + 1, right, new);
	}
}
