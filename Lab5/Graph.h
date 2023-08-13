#include <string>
#include <set>
#include <vector>

using namespace std;

struct Edge {
    string city1{}, city2{};
    int distance{};
};

struct Node {
    Edge edge{};
    Node *next = nullptr;
};

class Graph {
private:
    Node *head = nullptr;
    int cityCount{}, edgeCount{};
    set<string> cities{};

public:
    Graph(const string &fileName);

    void print() const;

    void shortestPath(const string &startCity, const string &endCity);

    vector<Edge> adjEdges(const string &city);

    ~Graph();
};