typedef struct np_pool_s np_pool_t;

// this vvv is the memory
struct np_pool_s {
    char *unused; // <- 4 bits
    char *stop; // <- 4 bits
    size_t node_size; // 12 bits
    void* free_node; // <- 4 bits?
};

void np_initialize(np_pool_t *node_pool, size_t node_size, void *memory, size_t memory_size);
void *np_allocate(np_pool_t *node_pool);
void np_free(np_pool_t *node_pool, void *memory);
