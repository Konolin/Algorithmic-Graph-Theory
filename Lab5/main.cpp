#include "Graph.h"

int main() {
    Graph graph("cities.txt");
    graph.shortestPath("SanDiego", "Salina");
//    graph.print();

    Graph graphShort("Graph.txt");
    graphShort.shortestPath("Sibiu", "Arad");

    return 0;
}
