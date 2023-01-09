#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

struct vertex_node*
graph_create_vertex(struct vertex_node *start, int vertex)
{
    struct vertex_node* new_vertex;
    new_vertex = (struct vertex_node*) malloc(sizeof(struct vertex_node));

    new_vertex->adjacency_list = NULL;
    new_vertex->vertex = vertex;
    new_vertex->next = start;

    return new_vertex;
}

Graph
graph_new(int vertex_count)
{
    Graph g;

    g = (Graph) malloc(sizeof(Graph));
    g->edge_count = 0;
    g->vertex_count = 0;

    for (int i = vertex_count-1; i >= 0; i--) {
        g->vertices = graph_create_vertex(g->vertices, i);
        g->vertex_count++;
    }

    return g;
}

struct adjacency_node*
graph_add_adjacent_node(int vertex_dest, struct adjacency_node *adjnode) {
    struct adjacency_node *anode = (struct adjacency_node*) malloc(sizeof(struct adjacency_node));
    anode->vertex = vertex_dest;
    anode->next = adjnode;

    return anode;
}

void
graph_add_edge(Graph g, int vertex_1, int vertex_2)
{
    struct vertex_node *vertex;
    struct adjacency_node *adj;

    if (g == NULL) {
        return;
    }

    for (vertex = g->vertices; vertex != NULL; vertex = vertex->next) {
        if (vertex->vertex == vertex_1) {
            for (adj = vertex->adjacency_list; adj != NULL; adj = adj->next) {
                if (adj->vertex == vertex_2) {
                    return;
                }
            }
            vertex->adjacency_list = graph_add_adjacent_node(vertex_2, vertex->adjacency_list);
            g->edge_count++;
        }
    }
}

void
graph_add_vertex(Graph g, int new_vertex)
{
    g->vertices = graph_create_vertex(g->vertices, new_vertex);
    g->vertex_count++;
}

void
graph_print(Graph g)
{
    struct vertex_node *vert;
    struct adjacency_node *adj;

    if (g == NULL) {
        return;
    }
    for (vert = g->vertices; vert != NULL; vert = vert->next) {
        printf("\nVertex %d:", vert->vertex);

        for (adj = vert->adjacency_list; adj != NULL; adj = adj->next) {
            printf("(%d)", adj->vertex);
        }
    }
}
