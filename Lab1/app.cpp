#include "Graph.h"
#include "GraphAdiazenzListe.h"

#include<iostream>
#include<fstream>

using namespace std;

int main() {

//    Graph g;
//    cout << g.isEdge(0, 1) << endl;
//    g.printGraph();
//
//    cout << "Max Grad = " << g.maxGradMat() << endl;
//    cout << "Min Grad = " << g.minGradMat() << endl;
//
//    g.addEdge(0, 3);
//    cout << "Edge added [0, 3]." << endl;
//
//    cout << "Max Grad = " << g.maxGradMat() << endl;
//    cout << "Min Grad = " << g.minGradMat() << endl;
//
//    cout << endl << endl;

    GraphAdiazenzListe gl;
    gl.printGraph();

    cout << gl.isEdge(0, 1) << endl;

    cout << "Max Grad = " << gl.maxGradListe() << endl;
    cout << "Min Grad = " << gl.minGradListe() << endl;
}