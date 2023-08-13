#include <vector>
#include <string>

class AdjList {
private:
    int nrNodes{};
    int nrLinks{};
    std::vector<int> *adjVector;

public:
    AdjList(std::string fileName);

    void addEdge(int x, int y);

    void BFS(int startNode);

    int weg(int start_node, int endNode);

    ~AdjList();
};