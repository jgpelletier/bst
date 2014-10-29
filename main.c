#include <stdio.h>
#include <stdlib.h>
#include "node_pool.h"
#include "bst.h"

int min (head_t *head) {
   return min_value(head->right);
}

int max (head_t *head) {
   return max_value(head->right);
}

int depth (head_t *head) {
   return max_depth(head->right);
}

void tree_search(head_t *head, int num) {
    find(head->right, num);
}

void deletion(head_t *head, int num) {
    delete_node(head->right, num);
}

void print(head_t *head) {
    print_tree(head->right);
}

head_t *insert(head_t *head, int *num, node_t *node) {
    insertion(head->right, num, node);
    return head;
}

int main ()
{
    static node_t nodes[16]; // 2219 seg fault with 15 nodes. added another node to make it 16.
    int i;
    head_t head;
    initialize_head(&head);
    np_pool_t node_pool;
    np_initialize(&node_pool, sizeof(node_t), nodes, sizeof(nodes));
    // ^^^ what is going on in here?
    static int arr[15] = { 9, /*4,*/ 8, 7, 0, 10, 5, 14, 1, 11, 24, 19, 23, 18, 34, 17 };

    for ( i = 0; i < 15; ++i) {
         add(&head, &arr[i], np_allocate(&node_pool));
    }

    //print(&head);

    //printf("The min value is %d\n", min(&head));
    //printf("The max value is %d\n", max(&head));
    //printf("The max depth is %d\n", depth(&head));

    //tree_search(&head, 13);
    //tree_search(&head, 17);
    //deletion(&head, 13);
    //printf("Deleting 11.\n");
    //deletion(&head, 11);
    //printf("Printing tree n order.\n");
    //print(&head);
    //printf("Deleting 34.\n");
    //deletion(&head, 34);
    //printf("Printing tree in order.\n");
    //print(&head);
    printf("Deleting 14.\n");
    deletion(&head, 14); // <- should this be arr[6];
    //printf("Deleting 19.\n");
    print(&head);
    np_free(&node_pool, &nodes); // <-- the addition of this causes a seg fault
    printf("Deleting 19.\n");
    deletion(&head, 19); //<-adds nodes
    print(&head);
    //np_free(&node_pool, nodes);

    //insert(&head, &arr[7], np_allocate(&node_pool));
    //printf("Inserting 14.\n");
    //print(&head);

    return 0;
}
