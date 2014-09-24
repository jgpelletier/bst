typedef struct bst_node_s node_t;
//typedef struct bst_head_s head_t;

struct bst_node_s {
    int *data; // does void allow the data value to be multiple types?
    struct bst_node_s* right, *left;//, *parent;
};


node_t * add (node_t * head, int * value, node_t * node);
void print_tree(node_t * node);
