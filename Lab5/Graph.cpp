#include "Graph.h"
#include <fstream>
#include <iostream>
#include <map>
#include <queue>

Graph::Graph(const string &fileName) {
    ifstream inputFile(fileName);
    string line;
    Edge edge;

    while (inputFile >> edge.city1 >> edge.city2 >> edge.distance) {
        edgeCount++;

        cities.insert(edge.city1);
        cities.insert(edge.city2);

        auto newNode = new Node{edge};
        if (!head) {
            head = newNode;
        } else {
            auto current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    cityCount = cities.size();
}

void Graph::print() const {
    cout << "List: ";
    Node *current = head;
    while (current) {
        cout << "(" << current->edge.city1 << ", "
             << current->edge.city2 << ", "
             << current->edge.distance << ")";
        if (current->next) {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << "\nCities: " << cityCount << " Edges: " << edgeCount << '\n';
}

void Graph::shortestPath(const string &startCity, const string &endCity) {
    set<string> visited;
    map<string, int> distances;
    map<string, string> previous;

    for (const auto &city: cities) distances[city] = INT32_MAX;
    distances[startCity] = 0;

    queue<string> q;
    q.push(startCity);

    while (!q.empty()) {
        // Get the next city from the queue
        string currentCity = q.front();
        q.pop();

        // Check if we have reached the end city
        if (currentCity == endCity) break;

        // Visit all adjacent cities
        for (auto adjEdge: adjEdges(currentCity)) {
            string neighborCity;
            if (currentCity == adjEdge.city1)
                neighborCity = adjEdge.city2;
            else neighborCity = adjEdge.city1;

            int neighborDistance = adjEdge.distance;

            // Calculate the new distance to the adjEdge
            int newDistance = distances[currentCity] + neighborDistance;

            // If the new distance is shorter than the current distance to the adjEdge,
            // update the distances and add the adjEdge to the queue
            if (newDistance < distances[neighborCity]) {
                distances[neighborCity] = newDistance;
                previous[neighborCity] = currentCity;
                q.push(neighborCity);
            }
        }
    }

    // Check if a citiesPath was found
    if (previous[endCity].empty()) {
        cout << "No path found\n";
        return;
    }

    // Reconstruct the citiesPath
    string currentCity = endCity;
    vector<string> citiesPath;

    while (currentCity != startCity) {
        citiesPath.insert(citiesPath.begin(), currentCity);
        currentCity = previous[currentCity];
    }
    citiesPath.insert(citiesPath.begin(), startCity);

    cout << "Shortest path:\n";
    for (int i = 0; i < citiesPath.size(); i++) {
        cout << citiesPath[i];
        if (i < citiesPath.size() - 1) {
            cout << " -> ";
        }
    }
    cout << "\nTotal distance: " << distances[endCity] << "\n";
}

vector<Edge> Graph::adjEdges(const string &city) {
    vector<Edge> neighbours;

    Node *current = head;
    while (current->next) {
        if (current->edge.city1 == city || current->edge.city2 == city)
            neighbours.push_back(current->edge);

        current = current->next;
    }

    return neighbours;
}

Graph::~Graph() {
    Node *current = head;
    while (current) {
        Node *next = current->next;
        delete current;
        current = next;
    }
}
