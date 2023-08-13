#include "kantenListe.h"
#include <fstream>
#include <iostream>

KantenListe::KantenListe(const std::string &fileName) {
    std::ifstream file;
    file.open("../" + fileName);

    file >> n >> m;

    int node1, node2;
    for (int index = 0; index < m; index++) {
        file >> node1 >> node2;
        kantenArray.push_back(std::pair(node1, node2));
    }

    file.close();
}

KantenListe::KantenListe() {
    n = 0;
    m = 0;
}

KantenListe::KantenListe(const KantenListe &kl) {
    n = kl.n;
    m = kl.m;

    for (int index = 0; index < m; index++)
        kantenArray.push_back(kl.kantenArray[index]);
}

KantenListe KantenListe::komplement() {
    KantenListe komplementGraph;
    komplementGraph.n = n;

    for (int node1 = 0; node1 < n - 1; node1++)
        for (int node2 = node1 + 1; node2 < n; node2++)
            if (!isEdge(node1, node2)) {
                komplementGraph.m++;

                komplementGraph.kantenArray.push_back(std::make_pair(node1, node2));
            }

    return komplementGraph;
}

void KantenListe::print() {
    std::cout << "Knoten " << n << "; Kanten: " << m << std::endl;

    for (int index = 0; index < m; index++) {
        std::cout << "Kante " << index << " (" << kantenArray[index].first << " ," << kantenArray[index].second
                  << ")" << std::endl;
    }
}

bool KantenListe::isEdge(int node1, int node2) {
    for (int index = 0; index < m; index++)
        if (kantenArray[index] == std::pair(node1, node2) || kantenArray[index] == std::pair(node2, node1))
            return true;
    return false;
}
