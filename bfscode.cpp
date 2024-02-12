#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void bfs(vector<vector<int>>& graph, int start) {
    int vertices = graph.size();
    vector<bool> visited(vertices, false);
    queue<int> q;


    visited[start] = true;
    q.push(start);

    while (!q.empty()) {

        int currentVertex = q.front();
        cout << currentVertex << " ";
        q.pop();


        for (int i = 0; i < graph[currentVertex].size(); ++i) {
            int adjacentVertex = graph[currentVertex][i];
            if (!visited[adjacentVertex]) {
                visited[adjacentVertex] = true;
                q.push(adjacentVertex);
            }
        }
    }
}

int main() {

    vector<vector<int>> graph = {
        {1, 2},
        {0, 3, 4},
        {0, 5},
        {1},
        {1},
        {2}
    };

    cout << "BFS starting from vertex 0: ";
    bfs(graph, 0);

    return 0;
}

