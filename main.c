#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include "node_pool.h"


int main ()
{
    node_t nodes[MAX_NODE];

    np_pool_t node_pool;

    np_initialize(&node_pool, sizeof(node_t), nodes, sizeof(nodes));

    return 0;
}
