#include <bits/stdc++.h>
using namespace std;

vector<int> findShortestPath(vector<vector<pair<int,int>>>& graph, int src, int dest) {
    int n = graph.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n, 1e9);
    vector<int> parent(n);
    for (int i=0 ; i<n ; i++) {
        parent[i] = i;
    }

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        for (auto edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (d + weight < dist[v]) {
                dist[v] = d + weight;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[dest] == 1e9) {
        return {-1}; // No path found
    }

    vector<int> path;
    int node = dest;
    while (node != src) {
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(src);
    reverse(path.begin(), path.end());

    return path;
}

int main() {
    vector<vector<pair<int,int>>> graph = {
        {{1, 4}, {2, 1}}, // Node 0
        {{0, 4}, {2, 2}, {3, 5}}, // Node 1
        {{0, 1}, {1, 2}, {3, 8}}, // Node 2
        {{1, 5}, {2, 8}} // Node 3
    };

    int src = 0, dest = 3;

    vector<int> shortestPath = findShortestPath(graph, src, dest);

    if (shortestPath.size() == 1 && shortestPath[0] == -1) {
        cout << "No path found from " << src << " to " << dest << endl;
    } else {
        cout << "Shortest path from " << src << " to " << dest << ": ";
        for (int node : shortestPath) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}