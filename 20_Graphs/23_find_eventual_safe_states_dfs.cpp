#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<int>& visited) {
    visited[node] = 2;

    for (auto it : graph[node]) {
        if (!visited[it]) {
            dfs(it, graph, visited);
            if (visited[it] == 2) return;
        }
        else if (visited[it] == 2) return;
    }

    visited[node] = 1;
}

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> visited (n,0);

    for (int i=0 ; i<n ; i++) {
        if (!visited[i]) {
            dfs(i,graph,visited);
        }
    }

    vector<int> ans;
    for (int i=0 ; i<n ; i++) {
        if (visited[i] == 1) ans.push_back(i);
    }
    return ans;
}

int main() {
    vector<vector<int>> graph = {{1,2},{2,3},{5},{0},{5},{},{}};
    vector<int> result = eventualSafeNodes(graph);
    
    cout << "Eventual Safe Nodes: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}