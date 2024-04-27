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

// Define a structure to represent nodes in the graph
struct Node {
    int vertex;
    int key;
};

// Define a custom comparator for priority_queue
struct Comparator {
    bool operator()(const Node& a, const Node& b) {
        return a.key > b.key;
    }
};

// Define a function to add an edge to the graph
void addEdge(vector<vector<Edge>>& graph, int source, int destination, int weight) {
    Edge edge = {destination, weight};
    graph[source].push_back(edge);
    edge.destination = source;
    graph[destination].push_back(edge);
}

// Define Prim's algorithm to find MST
vector<Edge> primMST(const vector<vector<Edge>>& graph) {
    int numVertices = graph.size();
    vector<bool> inMST(numVertices, false); // To keep track of vertices included in MST
    vector<Edge> MST; // To store the MST
    priority_queue<Node, vector<Node>, Comparator> pq; // Min-heap to select the minimum weight edge

    // Start with the first vertex
    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().vertex;
        pq.pop();

        // Add the vertex to MST
        inMST[u] = true;

        // Traverse all adjacent vertices of u
        for (const Edge& edge : graph[u]) {
            int v = edge.destination;
            int weight = edge.weight;

            // If v is not in MST and the weight of the edge (u,v) is smaller than the key of v
            if (!inMST[v] && weight < pq.top().key) {
                pq.push({v, weight});
                pq.top().key = weight;
            }
        }
    }

    // Construct MST from priority queue
    while (!pq.empty()) {
        int u = pq.top().vertex;
        int weight = pq.top().key;
        pq.pop();

        MST.push_back({u, weight});
    }

    return MST;
}

int main() {
    int numNodes, numEdges;
    cout << "Enter the number of nodes and edges: ";
    cin >> numNodes >> numEdges;

    vector<vector<Edge>> graph(numNodes);

    cout << "Enter the edges (source destination weight):" << endl;
    for (int i = 0; i < numEdges; ++i) {
        int source, destination, weight;
        cin >> source >> destination >> weight;
        addEdge(graph, source, destination, weight);
    }

    vector<Edge> MST = primMST(graph);

    cout << "Edges in the Minimum Spanning Tree (MST):" << endl;
    for (const Edge& edge : MST) {
        cout << edge.destination << " -- " << edge.weight << " --> " << edge.destination << endl;
    }

    return 0;
}

