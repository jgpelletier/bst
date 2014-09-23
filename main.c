#include <stdio.h>
#include <stdlib.h>
#include "node_pool.h"


int main ()
{
    static node_t nodes[15];
    int x = 0;

    np_pool_t node_pool;

    np_initialize(&node_pool, sizeof(node_t), nodes, sizeof(nodes));

    // vvv this doesn't work.
    node_t* node = (node_t*) new_node(&x, np_allocate(&node_pool));

    //printf("node value %d\n", nodes->data);

    return 0;
}
