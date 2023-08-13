#include "graph.h"
#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

AdjList::AdjList(string fileName) {
    ifstream f;
    f.open(fileName);
    f >> nrNodes;
    f >> nrLinks;
    adjVector = new std::vector<int>[nrNodes];
    int x, y;
    for (int i = 0; i < nrLinks; i++) {
        f >> x >> y;
        addEdge(x, y);
    }
}

void AdjList::addEdge(int x, int y) {
    adjVector[x].push_back(y);
    adjVector[y].push_back(x);
}

void AdjList::BFS(int startNode) {
    std::vector<bool> visited(nrNodes, false);
    std::queue<int> nodeQueue;

    nodeQueue.push(startNode);
    visited[startNode] = true;

    while (!nodeQueue.empty()) {
        int currentNode = nodeQueue.front();
        nodeQueue.pop();

        cout << currentNode << " ";

        for (int adjNode: adjVector[currentNode]) {
            if (!visited[adjNode]) {
                visited[adjNode] = true;
                nodeQueue.push(adjNode);
            }
        }
    }
}

int AdjList::weg(int startNode, int endNode) {
    std::vector<bool> visited(nrNodes, false);
    std::vector<int> distances(nrNodes, -1);
    std::queue<int> nodeQueue;

    nodeQueue.push(startNode);
    visited[startNode] = true;
    distances[startNode] = 0;

    while (!nodeQueue.empty()) {
        int currentNode = nodeQueue.front();
        nodeQueue.pop();

        if (currentNode == endNode) return distances[endNode];

        for (int node: adjVector[currentNode]) {
            if (!visited[node]) {
                visited[node] = true;
                nodeQueue.push(node);
                distances[node] = distances[currentNode] + 1;
            }
        }
    }
    cout << "Kein Weg ";
    return -1;
}

AdjList::~AdjList() {
    delete[] adjVector;
}