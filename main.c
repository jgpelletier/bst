#include <stdio.h>
#include <stdlib.h>
#include "node_pool.h"
#include "bst.h"

int min (head_t * head) {
   return min_value(head->right);
}

int max (head_t * head) {
   return max_value(head->right);
}

void print(head_t *head) {
    print_tree(head->right);
}

int main ()
{
    static node_t nodes[16]; // 2219 seg fault with 15 nodes. added another node to make it 16.
    int i;
    head_t head;
    initialize_head(&head);
    np_pool_t node_pool;
    np_initialize(&node_pool, sizeof(node_t), nodes, sizeof(nodes));
    static int arr[15] = { 9, 4, 8, 7, 0, 10, 5, 14, 1, 11, 24, 19, 18, 34, 17 };

    for ( i = 0; i < 15; ++i) {
         add(&head, &arr[i], np_allocate(&node_pool));
    }

    print(&head);

    printf("The min value is %d\n", min(&head));
    printf("The max value is %d\n", max(&head));

    return 0;
}
