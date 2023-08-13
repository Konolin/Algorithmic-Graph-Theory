#include <vector>

class GraphAdiazenzListe {
private:

    int n;
    int m;
    std::vector<int> array[100];

public:

    GraphAdiazenzListe();

    void addEdge(int x, int y);

    bool isEdge(int x, int y);

    void printGraph();

    int maxGradListe();

    int minGradListe();
};