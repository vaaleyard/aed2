
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


Graph graph_new(int vertex_count);
void graph_add_edge(Graph g, int vertex_1, int vertex_2);
void graph_add_vertex(Graph g, int new_vertex);
void graph_print(Graph g);
