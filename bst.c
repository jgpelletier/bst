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

node_t * append(node_t * head, node_t * node)
{
    int *a = head->data; // check variables.
    int *b = node->data;

    if (*a > *b) { //<- w/o the & before all nodes in right w & all nodes left
        if (head->left == NULL) {
            return head->left = node;
        } else  {
            return append(head->left, node);
        }
    } else {
         if (head->right == NULL) {
            return head->right = node;
        } else  {
            return append(head->right, node);
        }
    }
}

node_t * add (node_t * head, int * value, node_t * node)
{
    //node_t * temp = head;
    node->data = value;

    if (head ==  NULL) {
        head = node;
        return head;
    } else {
        return append(head, node);
        //      upon the first call to append the address is not passed.
    /*
        //return append(node_t * head, node_t * node); <- does this need a return
        //temp = head;
        while (head->right != NULL) {
           head = head->right;
        }
        head->right = node;
        */
    }
}
