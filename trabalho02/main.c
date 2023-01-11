#include "src/graph.h"
#include <stdio.h>

int main (int argc, char *argv[]) {
    // Graph g;
    // g = graph_new(5);

    // graph_add_edge(g, 0, 1, 2);
    // graph_add_edge(g, 0, 2, 3);
    // graph_add_edge(g, 2, 1, 1);
    // graph_add_edge(g, 2, 4, 5);
    // graph_add_edge(g, 2, 4, 5);
    // graph_add_edge(g, 4, 3, 8);
    // graph_add_edge(g, 1, 3, 9);

    // graph_print(g);

    FILE *fp = fopen("social_network.txt", "r");
    if (fp == NULL) {
        printf("Error reading social_network file");
        return -1;
    }
    char user_1[20];
    char user_2[20];
    int weight;

    while(fscanf(fp, "%s %s %d", user_1, user_2, &weight) != EOF)  {
        printf("%s %s %d\n", user_1, user_2, weight);
    }

    // TODO: make edges work with strings not integers

    return 0;
}
