#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include "node_pool.h"

/*node_t */ void  append(node_t * head, node_t * node)
{
    int *a = head->data;
    int *b = node->data;

    if (*a > *b) {
        if (head->left == NULL) {
            /*return*/ head->left = node;
        } else  {
            /*return*/ append(head->left, node);
        }
    } else {
         if (head->right == NULL) {
            /*return*/ head->right = node;
        } else  {
            /*return*/ append(head->right, node);
        }
    }
}

/*node_t */ void  add (node_t * head, int * value, node_t * node)
{
    node->data = value;

    if (head ==  NULL) {
        head = &node;
        /*return head;*/
    } else {
        /*return*/ append(head, node);
    }
}

void print_tree(node_t * node)
{
    if (node == NULL) return;
    if(node->left) print_tree(node->left);
    printf("%d\n", *node->data);
    if (node->right) print_tree(node->right);}
