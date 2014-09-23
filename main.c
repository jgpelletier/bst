#include <stdio.h>
#include <stdlib.h>
#include "node_pool.h"


int main ()
{
    node_t nodes[15];
    int x = 1111;

    np_pool_t node_pool;
    node_t node;

    np_initialize(&node_pool, sizeof(node_t), nodes, sizeof(nodes));

    (node_t*) new_node(&x, np_allocate(&node_pool));

    node = nodes[0];

    printf("node value %d\n", *node.data);

    return 0;
}
