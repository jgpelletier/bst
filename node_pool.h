typedef struct np_pool_s np_pool_t;
typedef struct bst_node_s node_t;

struct bst_node_s {
    int *data; // does void allow the data value to be multiple types?
    struct bst_node_s* right, *left;//, *parent;
};

struct np_pool_s {
    char *unused;
    char *stop;
    size_t node_size;
    void* free_node;
};

void np_initialize(np_pool_t *node_pool, size_t node_size, void *memory, size_t memory_size);
void * np_allocate(np_pool_t* node_pool);
