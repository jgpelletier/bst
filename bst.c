#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include "node_pool.h"


head_t *initialize_head(head_t *head)
{
    head->right = NULL;
    return head;
}

node_t *append(node_t *head, node_t *node)
{
    int *a = head->data;
    int *b = node->data;

    if (*a > *b) {
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

head_t *add(head_t *head, int *value, node_t *node)
{
    node->data = value;

    if (&head->right->data ==  NULL) {
        head->right = node;
    } else {
        append(head->right, node);
    }
    return head;
}

void print_tree(node_t *node)
{
    if (node == NULL) return;
    if(node->left) print_tree(node->left);
    printf("%d\n", *node->data);
    if (node->right) print_tree(node->right);
}

int min_value(node_t *node)
{
    node_t *temp = node;

    while (temp->left != NULL) {
        temp = temp->left;
    }

    return *temp->data;
}

int max_value(node_t *node)
{
    node_t *temp = node;

    while (temp->right != NULL) {
        temp = temp->right;
    }

    return *temp->data;
}

int max_depth(node_t *node)
{
    int left_depth;
    int right_depth;

    if (node==NULL) {
        return(0);
    } else {
        left_depth = max_depth(node->left);
        right_depth = max_depth(node->right);
    }

    if (left_depth > right_depth) return(left_depth+1);
    else return(right_depth+1);

}

void find(node_t *node, int num)
{

    while (node && *node->data != num) {
        if (*node->data > num) node = node->left;
        else node = node->right;
    }

    if (node && *node->data == num) printf("%d found\n", num);
    else printf("%d not found\n", num);

}

node_t *transplant(node_t *head, node_t *prev, node_t *node, node_t *next_node)
{

    if (prev == NULL) {
        head = next_node;
    }
    else if (prev->left ==  node) {
        prev->left = next_node;
        //next_node->left = node->left;
        //next_node->right= node->right;
    } else {
        prev->right = next_node;
        //next_node->left = node->left; //<-- a segfault occurs. This is the
        //min.
        //next_node->right= node->right;
    }

    if (node->right != NULL && node->left != NULL) {
        if (node->right == next_node) {
            next_node->right = node->right->right;
        } else {
            delete_node(node, next_node->data);
            next_node->right = node->right;
            next_node->left = node->left;
        }
    }

    return head;
}

node_t *min_f (node_t *node)
{
    node_t *temp = node;

    while (temp->left != NULL) {
        temp = temp->left;
    }

    return temp;
}

void delete_node(node_t *node, int num)
{
    node_t *head, *prev, *min;
    head = node;

    while (node && *node->data != num) {
        prev = node;
        if (*node->data >  num) node = node->left;
        else node = node->right;
    }

    if (node == NULL || *node->data != num) {
         printf("%d not found. Process exited\n", num);
         return;
    }

    if (node->left == NULL) {
        transplant (head, prev, node, node->right);
    }
    else if (node->right == NULL) {
        transplant (head, prev, node, node->left);
    } else {
        min = min_f(node/*head*/); //<-- head is the wrong argument.

        if (node->right->data != min->data ) {
            transplant (head, prev, node, min);
        }

        transplant (head, prev, node, min); // <- should this be node->right
    }

}

// vvv error: conflicting types for insertion
node_t *insertion(node_t *node, int *value, node_t *temp)
{
    node_t *prev, *head;
    head = prev = node;
    temp->data = value;

    while (node) {
        prev = node;
        if (node->data > temp->data ) node = node->left;
        else node = node->right;
    }

    //if (prev == node) {
    if (prev->data > temp->data) {
        prev->left = temp;
    } else {
        prev->right = temp;
    }
    return head;
}
