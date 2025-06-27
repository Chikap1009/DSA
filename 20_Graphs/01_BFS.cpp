#include <bits/stdc++.h>
using namespace std;

void bfs(int start, vector<vector<int>>& graph, vector<int>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n = 5; // Number of nodes
    vector<vector<int>> graph(n);
    
    // Example graph edges
    graph[0] = {1, 2};
    graph[1] = {0, 3};
    graph[2] = {0, 4};
    graph[3] = {1};
    graph[4] = {2};

    vector<int> visited(n, 0);
    
    cout << "BFS starting from node 0: ";
    bfs(0, graph, visited);
    cout << endl;

    return 0;
}