#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define INF INT_MAX

// Define a structure to represent edges
struct Edge {
    int source;
    int destination;
    int weight;
};

// Define a function to add an edge to the graph
void addEdge(vector<Edge>& edges, int source, int destination, int weight) {
    Edge edge = {source, destination, weight};
    edges.push_back(edge);
}

// Define a function to find the shortest path from source to destination using Bellman-Ford algorithm
vector<int> bellmanFord(const vector<Edge>& edges, int numNodes, int source, int destination) {
    vector<int> distance(numNodes, INF); // Initialize distances with infinity
    vector<int> parent(numNodes, -1); // Initialize parent array to track the shortest path
    distance[source] = 0;

    // Relax all edges (numNodes - 1) times
    for (int i = 0; i < numNodes - 1; ++i) {
        for (const Edge& edge : edges) {
            int u = edge.source;
            int v = edge.destination;
            int weight = edge.weight;

            if (distance[u] != INF && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                parent[v] = u;
            }
        }
    }

    // Check for negative-weight cycles
    for (const Edge& edge : edges) {
        int u = edge.source;
        int v = edge.destination;
        int weight = edge.weight;

        if (distance[u] != INF && distance[u] + weight < distance[v]) {
            cout << "Graph contains a negative-weight cycle" << endl;
            return {};
        }
    }

    // Reconstruct the shortest path from source to destination
    vector<int> shortestPath;
    int current = destination;
    while (current != -1) {
        shortestPath.push_back(current);
        current = parent[current];
    }
    reverse(shortestPath.begin(), shortestPath.end());

    return shortestPath;
}

int main() {
    int numNodes, numEdges;
    cout << "Enter the number of nodes and edges: ";
    cin >> numNodes >> numEdges;

    vector<Edge> edges;
    cout << "Enter the edges (source destination weight):" << endl;
    for (int i = 0; i < numEdges; ++i) {
        int source, destination, weight;
        cin >> source >> destination >> weight;
        addEdge(edges, source, destination, weight);
    }

    int source, destination;
    cout << "Enter the source and destination nodes: ";
    cin >> source >> destination;

    vector<int> shortestPath = bellmanFord(edges, numNodes, source, destination);

    if (!shortestPath.empty()) {
        cout << "Shortest path from " << source << " to " << destination << " is: ";
        for (int node : shortestPath) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}

