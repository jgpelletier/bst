typedef struct bst_node_s node_t;
typedef struct bst_head_s head_t;

struct bst_node_s {
    int *data; // does void allow the data value to be multiple types?
    struct bst_node_s* right, *left;//, *parent;
};

struct bst_head_s {
    struct bst_node_s* right;
};


head_t* initialize_head(head_t * head);
head_t * add (head_t * head, int * value, node_t * node);
void print_tree(node_t * node);
int min_value(node_t* node);
int max_value(node_t* node);
int max_depth(node_t* node);
void find (node_t * node, int num);
void delete_node (node_t * node, int num);
// find
// insertion
// deletion
