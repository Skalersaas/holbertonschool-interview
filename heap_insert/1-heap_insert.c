#include <stdlib.h>
#include "binary_trees.h"

/**
 * heap_insert - new node
 *
 * @parent: pointer to the parent node
 * @value: value of the new node
 *
 * Return: pointer to the new node
 */
binary_tree_t *heap_insert(binary_tree_t *root, int value)
{
    while(1)
    {
        if(root->n > value)
        {
            if(!root->left)
            {
                root->left = binary_tree_node(root, value);
                return root->left;
            }
            
            root = root->left;
        }
        else {
            if(!root->right)
            {
                root->right=binary_tree_node(root,value);
                return root->right;
            }
            root = root->right;
        }
    }
    return NULL;
}
