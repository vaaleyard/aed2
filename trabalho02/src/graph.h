
struct adjacency_node {
    int vertex;
    struct adjacency_node *next;
};

struct vertex_node {
    int vertex;
    struct vertex_node *next;
    struct adjacency_node *adjacency_list;
};

struct graph {
    int vertex_count; // Quantidade de vertices
    int edge_count;   // Quantidade de arcos
    struct vertex_node *vertices;
};
typedef struct graph *Graph;


Graph new_graph(int vertex_count);
