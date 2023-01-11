#include "src/graph.h"
#include <stdio.h>

int main (int argc, char *argv[]) {
    Graph g;
    g = graph_new(5);

    graph_add_edge(g, 0, 1, 2);
    graph_add_edge(g, 0, 2, 3);
    graph_add_edge(g, 2, 1, 1);
    graph_add_edge(g, 2, 4, 5);
    graph_add_edge(g, 2, 4, 5);
    graph_add_edge(g, 4, 3, 8);
    graph_add_edge(g, 1, 3, 9);

    graph_print(g);

    return 0;
}
