#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define INF INT_MAX

// Define a structure to represent edges
struct Edge {
    int destination;
    int weight;
};

// Define a function to add an edge to the graph
void addEdge(vector<vector<Edge>>& graph, int source, int destination, int weight) {
    Edge edge = {destination, weight};
    graph[source].push_back(edge);
}

// Define a function to find the shortest path from source to destination using Dijkstra's algorithm
vector<int> dijkstra(const vector<vector<Edge>>& graph, int source, int destination) {
    int n = graph.size();
    vector<int> distance(n, INF); // Initialize distances with infinity
    vector<int> parent(n, -1); // Initialize parent array to track the shortest path

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    distance[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const Edge& edge : graph[u]) {
            int v = edge.destination;
            int weight = edge.weight;

            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                parent[v] = u;
                pq.push({distance[v], v});
            }
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
    int n, m; // n: number of nodes, m: number of edges
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    cout << "Enter the edges (source destination weight):" << endl;
    for (int i = 0; i < m; ++i) {
        int source, destination, weight;
        cin >> source >> destination >> weight;
        addEdge(graph, source, destination, weight);
    }

    int source, destination;
    cout << "Enter the source and destination nodes: ";
    cin >> source >> destination;

    vector<int> shortestPath = dijkstra(graph, source, destination);

    cout << "Shortest path from " << source << " to " << destination << " is: ";
    for (int node : shortestPath) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}

