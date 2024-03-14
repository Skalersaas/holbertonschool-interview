#include <stdlib.h>
#include "binary_trees.h"
binary_tree_t* binary_tree_node(binary_tree_t* parent, int value) {
	binary_tree_t* node;
	node = (struct binary_tree_t*)malloc(sizeof(binary_tree_t));
	if (!node)
		return NULL;
	node->parent = parent;
	node->n = value;
	node->left = node->right = NULL;
	return node;
}