#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include "node_pool.h"

// vvv should I make this both the function that adds the value
node_t * new_node (int *data, node_t *node)
{
    node->data = data;
    return node;
}

node_t * add (node_t * head, int * value, node_t * node)
{
    node_t * temp = head;
    node->data = value;

    if (head ==  NULL) {
        head = node;
        return head;
    } else {
        //temp = head;
        while (head->right != NULL) {
           head = head->right;
        }
        head->right = node;
    }

    return temp; //<- temp has the same address as node
}
