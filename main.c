#include <stdio.h>
#include <stdlib.h>
#include "node_pool.h"


int main ()
{
    static node_t nodes[15];

    np_pool_t node_pool;
    //node_t node;

    np_initialize(&node_pool, sizeof(node_t), nodes, sizeof(nodes));

    (node_t*) np_allocate(&node_pool);


    return 0;
}
