#include <vector>
#include <utility>
#include <string>

class KantenListe {
private:
    int m, n;
    std::vector<std::pair<int, int>> kantenArray;

public:
    KantenListe(const std::string &fileName);

    KantenListe();

    KantenListe(const KantenListe &kl);

    KantenListe komplement();

    void print();

    bool isEdge(int node1, int node2);
};