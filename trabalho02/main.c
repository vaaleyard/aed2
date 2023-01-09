#include "src/graph.h"
#include "src/util.h"
#include <stdio.h>

int main (int argc, char *argv[]) {
    // Graph g;
    // g = graph_new(5);

    // graph_add_edge(g, 0, 1);
    // graph_add_edge(g, 0, 2);
    // graph_add_edge(g, 2, 1);
    // graph_add_edge(g, 2, 4);
    // graph_add_edge(g, 4, 3);
    // graph_add_edge(g, 1, 3);
    // graph_print(g);
    char *social_network_filename = "social_network.txt";
    FILE *social_network_fd = fopen(social_network_filename, "r");

    parse_social_network_file(social_network_fd);

    return 0;
}
