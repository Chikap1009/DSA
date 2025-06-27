#include <bits/stdc++.h>
using namespace std;

void topoSort(int node, vector<vector<pair<int, int>>>& graph, vector<int>& visited, stack<int>& st) {
    visited[node] = 1;
    for (auto it : graph[node]) {
        int v = it.first;
        if (!visited[v]) {
            topoSort(v, graph, visited, st);
        }
    }
    st.push(node);
}

vector<int> shortestPath(vector<vector<int>>& edges, int n, int src) {
    vector<vector<pair<int, int>>> graph(n);
    for (int i=0 ; i<edges.size() ; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        graph[u].push_back({v, wt});
    }

    vector<int> dist(n, 1e9);
    dist[src] = 0;

    vector<int> visited(n, 0);
    stack<int> st;

    for (int i=0 ; i<n ; i++) {
        if (!visited[i]) {
            topoSort(i, graph, visited, st);
        }
    }

    while(!st.empty()) {
        int node = st.top();
        st.pop();

        for (auto it : graph[node]) {
            int v = it.first;
            int wt = it.second;
            if (dist[node] + wt < dist[v]) {
                dist[v] = dist[node] + wt;
            }
        }
    }

    for (int i=0 ; i<n ; i++) {
        if (dist[i] >= 1e9) {
            dist[i] = -1; // If no path exists, return -1
        }
    }

    return dist;
}

int main() {
    int n = 5; // Number of nodes
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 2, 4},
        {1, 2, 1},
        {1, 3, 7},
        {2, 3, 3},
        {3, 4, 1}
    };
    int src = 0; // Starting node

    vector<int> result = shortestPath(edges, n, src);
    
    for (int i = 0; i < n; i++) {
        cout << "Shortest path from " << src << " to " << i << " is: " << result[i] << endl;
    }

    return 0;
}