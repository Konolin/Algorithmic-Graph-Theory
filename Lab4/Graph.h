#pragma once

#include <vector>
#include <string>

using namespace std;

class Graph {
private:
    int nodes{};
    int links{};
    vector<int> *adjVector{};
    vector<int> startComps{};

public:
    Graph(string fileName);

    void addEdge(int x, int y);

    int AnzahlKomponente();

    void dfs(int node, vector<bool>& visited);

    bool dfsTree(int node, vector<bool>& visited);

    bool allTrees();

    ~Graph();
};