#pragma onceonce

#include <string>
#include <vector>

using namespace std;

class Graph {
private:
    string filename;
    vector<vector<int>> matrix;
    int edgeCount{};
    int nodeCount{};

public:
    explicit Graph(const string &filename);

    void print();

    bool isBipartite() const;
};