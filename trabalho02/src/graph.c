#include <stdlib.h>
#include "graph.h"

struct vertex_node* insert_vertex(struct vertex_node *start, int vertex) {
    struct vertex_node* new_vertex;
    new_vertex = (struct vertex_node*) malloc(sizeof(struct vertex_node));

    new_vertex->adjacency_list = NULL;
    new_vertex->vertex = vertex;
    new_vertex->next = start;

    return new_vertex;
}

Graph new_graph(int vertex_count) {
    Graph g;

    g = (Graph) malloc(sizeof(Graph));
    g->edge_count = 0;
    g->vertex_count = 0;

    for (int i = vertex_count-1; i >= 0; i--) {
        g->vertices = insert_vertex(g->vertices, i);
        g->vertex_count++;
    }

    return g;
}
