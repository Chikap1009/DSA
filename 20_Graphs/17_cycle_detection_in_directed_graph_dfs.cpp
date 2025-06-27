#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<vector<int>>& graph, vector<int> &visited) {
    visited[node] = 2;
    for (auto it : graph[node]) {
        if (!visited[it]) {
            if (dfs(it, graph, visited)) return true;
        }
        else if (visited[it] == 2) {
            return true; // Cycle detected
        }
    }
    visited[node] = 1; // Mark the node as processed
    return false; // No cycle detected from this node
}

bool detectCycle(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> visited(n, 0);

    for (int i=0 ; i<n ; i++) {
        if (!visited[i]) {
            if (dfs(i,graph,visited)) return true;
        }
    }

    return false;
}

int main() {
    vector<vector<int>> graph = {
        {1},    // Node 0 points to Node 1
        {2},    // Node 1 points to Node 2
        {0},    // Node 2 points back to Node 0, creating a cycle
        {4},    // Node 3 points to Node 4
        {}      // Node 4 has no outgoing edges
    };

    if (detectCycle(graph)) {
        cout << "Cycle detected in the directed graph." << endl;
    } else {
        cout << "No cycle detected in the directed graph." << endl;
    }

    return 0;
}