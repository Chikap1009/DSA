#include <bits/stdc++.h>
using namespace std;

bool bfs(vector<int> adj[], int n, int vis[], int start) {
    vis[start] = 1;
    queue<pair<int, int>> q;
    q.push({start, -1});

    while(!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (int adjNode : adj[node]) {
            if (!vis[adjNode]) {
                vis[adjNode] = 1;
                q.push({adjNode, node});
            } 
            else if (adjNode != parent) {
                // If the neighbor is visited and is not the parent, we found a cycle
                return true;
            }
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
            if (bfs(adj, n, vis, i)) return true;
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