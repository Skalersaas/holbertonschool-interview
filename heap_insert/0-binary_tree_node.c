#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - new node
 *
 * @parent: pointer to the parent node
 * @value: value of the new node
 *
 * Return: pointer to the new node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	node = malloc(sizeof(binary_tree_t));
	if (!node)
		return (NULL);
	node->parent = parent;
	node->n = value;
	node->left = node->right = NULL;
	return (node);
}
