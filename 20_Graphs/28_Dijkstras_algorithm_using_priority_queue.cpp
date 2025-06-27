#include <bits/stdc++.h>
using namespace std;

// Function to perform Dijkstra's algorithm using a priority queue
vector<int> dijkstra(vector<vector<pair<int,int>>> graph, int source) {
    int n = graph.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n, 1e9);

    dist[source] = 0;
    pq.push({0, source});

    while(!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        for(auto edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if(d + weight < dist[v]) {
                dist[v] = d + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    vector<vector<pair<int,int>>> graph = {
        {{1, 4}, {2, 1}}, // Node 0: edges to node 1 with weight 4 and node 2 with weight 1
        {{0, 4}, {2, 2}, {3, 5}}, // Node 1: edges to node 0 with weight 4, node 2 with weight 2, and node 3 with weight 5
        {{0, 1}, {1, 2}, {3, 8}}, // Node 2: edges to node 0 with weight 1, node 1 with weight 2, and node 3 with weight 8
        {{1, 5}, {2, 8}} // Node 3: edges to node 1 with weight 5 and node 2 with weight 8
    };

    int source = 0; // Starting node
    vector<int> distances = dijkstra(graph, source);

    cout << "Distances from source node " << source << ":\n";
    for(int i = 0; i < distances.size(); i++) {
        cout << "Node " << i << ": " << (distances[i] == 1e9 ? -1 : distances[i]) << endl;
    }

    return 0;
}