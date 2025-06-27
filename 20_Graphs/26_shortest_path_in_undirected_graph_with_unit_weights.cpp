#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<vector<int>>& graph, int src)  {
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    queue<int> q;
    q.push(src);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : graph[node]) {
            if (dist[node] + 1 < dist[neighbor]) {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }

    return dist;
}

int main() {
    vector<vector<int>> graph = {
        {1, 3},    // Neighbors of node 0
        {0, 2, 3}, // Neighbors of node 1
        {1, 6},    // Neighbors of node 2
        {0, 1, 4},       // Neighbors of node 3
        {3, 5}, // Neighbors of node 4
        {4, 6},    // Neighbors of node 5
        {2, 5, 7, 8},     // Neighbors of node 6
        {6, 8},    // Neighbors of node 7
        {6, 7}     // Neighbors of node 8
    };

    int src = 0; // Starting node
    vector<int> distances = shortestPath(graph, src);

    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < distances.size(); ++i) {
        if (distances[i] == INT_MAX) {
            cout << "Node " << i << ": Unreachable\n";
        } else {
            cout << "Node " << i << ": " << distances[i] << "\n";
        }
    }

    return 0;
}