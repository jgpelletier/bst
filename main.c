#include <stdio.h>
#include <stdlib.h>
#include "node_pool.h"


int main ()
{
    static node_t nodes[15]; // 2219 seg fault with 15 nodes. added another node to make it 16.
                             // is this bc it points to the beginning of the 16th node?
    int i;

    np_pool_t node_pool;

    np_initialize(&node_pool, sizeof(node_t), nodes, sizeof(nodes));

    static int arr[15] = { 9, 4, 8, 7, 0, 10, 5, 14, 1, 11, 24, 19, 18, 34, 17 };

    for ( i = 0; i < 15; ++i) {
        (node_t*) new_node(&arr[i], np_allocate(&node_pool));
         printf("i value %d and node value %d\n", i, *nodes[i].data);

    }



    return 0;
}
