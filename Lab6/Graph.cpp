#include "Graph.h"
#include <fstream>
#include <iostream>
#include <queue>

Graph::Graph(const string &fileName) {
    ifstream file(fileName);

    if (!file.is_open()) throw invalid_argument("File not found");

    file >> edgeCount >> nodeCount;
    matrix = vector<vector<int>>(nodeCount, vector<int>(nodeCount, 0));

    int node1, node2;
    while (file >> node1 >> node2) {
        matrix[node1][node2] = 1;
        matrix[node2][node1] = 1;
    }

    file.close();
}

void Graph::print() {
    cout << '\n';
    for (int i = 0; i < nodeCount; i++) {
        for (int j = 0; j < nodeCount; j++) cout << matrix[i][j] << ' ';
        cout << '\n';
    }
    cout << '\n';
}

bool Graph::isBipartite() const {
    vector<int> distance(nodeCount, -1);
    vector<int> partition1, partition2;

    queue<int> q;
    q.push(0);
    distance[0] = 0;

    // BFS for the distance to every node from the starting node
    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int u = 0; u < nodeCount; u++)
            if (matrix[v][u] != 0 && distance[u] == -1) {
                distance[u] = distance[v] + 1;
                q.push(u);
            }
    }

    // partition the nodes: even and odd distances
    for (int v = 0; v < nodeCount; v++)
        if (distance[v] % 2 == 0) partition2.push_back(v);
        else partition1.push_back(v);

    // check if the graph is  bipartite
    for (int v = 0; v < nodeCount; v++)
        for (int u = 0; u < nodeCount; u++)
            if (matrix[v][u] == 1 && (distance[v] % 2 == distance[u] % 2)) {
                cout << "Graph is not bipartite.\n";
                return false;
            }

    // print the partitions
    cout << "\npartition1: ";
    for (int v: partition1) cout << v << " ";

    cout << "\npartition2: ";
    for (int v: partition2) cout << v << " ";
    cout << '\n';

    return true;
}