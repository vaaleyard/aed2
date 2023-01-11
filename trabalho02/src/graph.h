
struct adjacency_node {
    int vertex;
    int weight;
    struct adjacency_node *next;
};

struct vertex_node {
    int vertex;
    struct vertex_node *next;
    struct adjacency_node *adjacency_list;
};

struct graph {
    int vertex_count;
    int edge_count;   // Quantidade de arcos
    struct vertex_node *vertices;
};
typedef struct graph *Graph;


Graph graph_new(int vertex_count);
void graph_add_edge(Graph g, int vertex_1, int vertex_2, int weight);
void graph_print(Graph g);
