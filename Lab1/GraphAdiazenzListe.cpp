#include "GraphAdiazenzListe.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

GraphAdiazenzListe::GraphAdiazenzListe() {

    ifstream f;
    f.open("data.in");
    f >> n;
    f >> m;
    int x, y;
    for (int i = 0; i < m; i++) {
        f >> x >> y;
        addEdge(x, y);
    }

}

void GraphAdiazenzListe::addEdge(int x, int y) {
    array[x].push_back(y);
    array[y].push_back(x);
}

bool GraphAdiazenzListe::isEdge(int x, int y) {
    for (int i = 0; i < n; i++)
        if (array[x][i] == y)
            return true;

    return false;
}

void GraphAdiazenzListe::printGraph() {
    for (int i = 0; i < n; i++) {
        cout << i << " : ";
        for (int j = 0; j < array[i].size(); j++)
            cout << array[i][j] << " ";
        cout << endl;
    }
}

int GraphAdiazenzListe::maxGradListe() {
    int max = 0;
    int sum;

    for (int node = 0; node < n; node++) {
        sum = array[node].size();

        if (sum > max) max = sum;
    }

    return max;
}

int GraphAdiazenzListe::minGradListe() {
    int min = INT_MAX;
    int sum;

    for (int node = 0; node < n; node++) {
        sum = array[node].size();

        if (sum < min) min = sum;
    }

    return min;
}
