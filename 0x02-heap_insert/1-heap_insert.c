#include "binary_trees.h"
/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: value store in the node to be inserted
 * Return: a pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	binary_tree_t *node = NULL, *tempNode = NULL;
	int temp = 0;

	if (!*root || !root)
	{
		node = binary_tree_node(*root, value);
		*root = node;
		return (node);
	}

	node = insertNode(*root, value);
	tempNode = node;

	while (node != NULL && node->parent != NULL)
	{
		if (node->parent->n < node->n)
		{
			temp = node->parent->n;
			node->parent->n = node->n;
			node->n = temp;
			tempNode = tempNode->parent;
		}
		node = node->parent;
	}
	return (tempNode);
}

/**
 * insertNode - inserts a node node
 * @root: root node of the heap
 * @value: value to be inserted
 * Return: pointer to node
 */
heap_t *insertNode(heap_t *root, int value)
{
	heap_t *tree[1024] = {NULL}, *node = NULL;
	int i = 0, tail = 0;

	tree[0] = root;
	while (tree[i] != NULL)
	{
		if (!tree[i]->left)
		{
			node = binary_tree_node(tree[i], value);
			tree[i]->left = node;
			break;
		}
		else
		{
			tree[++tail] = tree[i]->left;
		}
		if (!tree[i]->right)
		{
			node = binary_tree_node(tree[i], value);
			tree[i]->right = node;
			break;
		}
		else
		{
			tree[++tail] = tree[i]->right;
		}
		i++;
	}
	return (node);
}
