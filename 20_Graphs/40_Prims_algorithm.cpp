#include <bits/stdc++.h>
using namespace std;

int primsAlgorithm(int n, vector<vector<pair<int,int>>>& graph) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> visited(n, 0);
    int sum = 0;

    pq.push({0, 0}); // {weight, node}

    while (!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second;

        pq.pop();
        if (visited[node]) continue; // If the node is already visited, skip it

        visited[node] = 1; // Mark the node as visited
        sum += weight; // Add the weight to the total sum

        for (auto it : graph[node]) {
            int adjNode = it.first;
            int edgeWeight = it.second;

            if (!visited[adjNode]) {
                pq.push({edgeWeight, adjNode}); // Push the adjacent node and its edge weight into the priority queue
            }
        }
    }

    return sum; // Return the total weight of the minimum spanning tree
}

int main() {
    int n = 5; // Number of nodes
    vector<vector<pair<int,int>>> graph(n);

    // Example graph represented as an adjacency list
    graph[0] = {{1, 2}, {3, 6}};
    graph[1] = {{0, 2}, {2, 3}, {4, 5}};
    graph[2] = {{1, 3}, {4, 1}, {3, 3}};
    graph[3] = {{0, 6}, {2, 3}};
    graph[4] = {{1, 5}, {2, 1}};

    int result = primsAlgorithm(n, graph);
    cout << "Total weight of the minimum spanning tree: " << result << endl;

    return 0;
}