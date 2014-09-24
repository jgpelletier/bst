#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include "node_pool.h"


node_t * new_node (int *data, node_t *node)
{
    node->data = data;
    return node;
}
