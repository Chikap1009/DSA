#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<int> adj[], int n, int vis[], int node, int parent) {
    vis[node] = 1;

    for (auto it : adj[node]) {
        if (!vis[it]) {
            if (dfs(adj, n, vis, it, node)) return true;
        } else if (it != parent) {
            // If the adjacent node is visited and is not the parent of the current node,
            // then a cycle is detected.
            return true;
        }
    }

    return false;
}

bool isCycle(vector<int> adj[], int n) {
    int vis[n];
    for (int i = 0; i < n; i++) {
        vis[i] = 0;
    }

    for (int i=0 ; i<n ; i++) {
        if (!vis[i]) {
            if (dfs(adj, n, vis, i, -1)) return true;
        }
    }

    return false;
}

int main() {
    vector<int> adj[5];
    adj[0] = {1, 2};
    adj[1] = {0, 2, 3};
    adj[2] = {0, 1};
    adj[3] = {1, 4};
    adj[4] = {3};
    int n = 5; // Number of vertices

    if (isCycle(adj, n)) {
        cout << "Cycle detected in the undirected graph." << endl;
    } else {
        cout << "No cycle detected in the undirected graph." << endl;
    }

    return 0;
}