#include <iostream>
#include "Graph.h"

int main() {
    Graph graph("input.txt");

    graph.print();

    graph.isBipartite();

    return 0;
}
