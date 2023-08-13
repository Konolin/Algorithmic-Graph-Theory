#include <iostream>
#include "Graph.h"

int main() {
    Graph graph1("liste1.txt");

    cout << "Liste 1:" << endl;
    cout << "Anzahl Komponenten: " << graph1.AnzahlKomponente() << endl;
//    cout << "Sind alle Komponenten Baume: " << graph1.allTrees() << endl << endl;

    Graph graph2("liste2.txt");

    cout << "Liste 2:" << endl;
    cout << "Anzahl Komponenten: " << graph2.AnzahlKomponente() << endl;
//    cout << "Sind alle Komponenten Baume: " << graph2.allTrees() << endl << endl;

    return 0;
}
