#include "binary_trees.h"
/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to the root node of the heap
 * Return: the value stored in the root node
 */
int heap_extract(heap_t **root)
{
	int n, size, bit;
	heap_t *node, *heap;

	if (!heap || !*root)
		return (0);
	heap = *root;
	n = heap->n;
	size = tree_size(heap);
	if (size == 1)
	{
		free(heap);
		*root = NULL;
		return (n);
	}
	for (bit = 1; bit <= size; bit <<= 1)
		;
	bit >>= 2;
	for (node = heap; bit > 0; bit >>= 1)
		node = size & bit ? node->right : node->left;
	heap->n = node->n;
	if (node->parent->left == node)
		node->parent->left = NULL;
	else
		node->parent->right = NULL;
	free(node);
	replace(heap);
	*root = heap;
	return (n);
}

/**
 * replace - replace with the last node of the heap
 * @root: pointer to heap
 */
void replace(heap_t *root)
{
	heap_t *node = root, *new;
	int tmp;

	while (1)
	{
		if (!node->left)
			break;
		if (!node->right)
			new = node->left;
		else
			new = node->left->n > node->right->n ? node->left : node->right;
		if (node->n > new->n)
			break;
		tmp = node->n;
		node->n = new->n;
		new->n = tmp;
		node = new;
	}
}

/**
 * tree_size - size of binary tree
 * @root: pointer to root
 * Return: size of tree
 */
int tree_size(heap_t *root)
{
	return (root ? 1 + tree_size(root->left) + tree_size(root->right) : 0);
}
