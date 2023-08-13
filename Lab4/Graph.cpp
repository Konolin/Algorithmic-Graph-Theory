#include "Graph.h"
#include <fstream>
#include <iostream>

Graph::Graph(string fileName) {
    ifstream f;
    f.open(fileName);
    f >> nodes;
    f >> links;
    adjVector = new std::vector<int>[nodes + 1];
    int x, y;
    for (int i = 0; i < links; i++) {
        f >> x >> y;
        addEdge(x, y);
    }
}

void Graph::addEdge(int x, int y) {
    adjVector[x].push_back(y);
    adjVector[y].push_back(x);
}

int Graph::AnzahlKomponente() {
    vector<bool> visited(nodes + 1, false);

    int count = 0;

    for (int i = 1; i <= nodes; i++)
        if (!visited[i]) {
            startComps.push_back(i);
            dfs(i, visited);
            count++;
        }

    return count;
}

void Graph::dfs(int node, vector<bool>& visited) {
    visited[node] = true;

    for (auto neighbor : adjVector[node])
        if (!visited[neighbor])
            dfs(neighbor, visited);
}

// nu e ok :(((
bool Graph::dfsTree(int node, vector<bool>& visited) {
    visited[node] = true;
    int visitedNeighbours = 0;
    bool result = true;

    for (auto neighbor : adjVector[node])
        if (!visited[neighbor]) {
            visitedNeighbours++;
            result = result && dfsTree(neighbor, visited);
        }
        else visitedNeighbours++;

    return visitedNeighbours <= 1;
}

// nu e ok :(((
bool Graph::allTrees() {
    int count = 0;
//    cout << "size: " <<  startComps.size() << endl;

    for (int indexStart = 0; indexStart < startComps.size(); indexStart++) {
        vector<bool> visited(nodes + 1, false);

//        cout << "startcomp: " << startComps[indexStart] << endl;
        if (dfsTree(startComps[indexStart], visited))
            count++;
    }
    return count == startComps.size();
}

Graph::~Graph() {
    delete[] adjVector;
}