#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<int>& visited) {
    visited[node] = 1;
    cout << node << " ";

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited);
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
    
    cout << "DFS starting from node 0: ";
    dfs(0, graph, visited);
    cout << endl;

    return 0;
}