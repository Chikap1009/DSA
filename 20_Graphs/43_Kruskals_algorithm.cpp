#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent, componentSize;

public:
    DisjointSet(int n) {
        componentSize.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i; // Initially, each element is its own parent
        }
    }

    int findParent(int node) {
        if (parent[node] == node) return node;

        parent[node] = findParent(parent[node]); // Path compression
        return parent[node];
    }

    void unionBySize(int u, int v) {
        int parentU = findParent(u);
        int parentV = findParent(v);

        if (parentU == parentV) return; // They are already in the same set

        if (componentSize[parentU] < componentSize[parentV]) {
            parent[parentU] = parentV; // Attach smaller rank tree under larger rank tree
            componentSize[parentV] += componentSize[parentU]; // Update the size of the new root
        } else {
            parent[parentV] = parentU; // Arbitrarily choose one as the new root
            componentSize[parentU] += componentSize[parentV]; // Increase the rank of the new root
        }
    }
};

int kruskalsAlgorithm(int n, vector<vector<pair<int,int>>>& graph) {
    vector<pair<int, pair<int, int>>> edges;
    for (int i=0 ; i<n ; i++) {
        for (auto it : graph[i]) {
            int u = i;
            int v = it.first;
            int weight = it.second;
            if (u < v) edges.push_back({weight, {u, v}});
        }
    }
    
    sort(edges.begin(), edges.end()); // Sort edges based on weight
    int sum = 0;

    DisjointSet ds(n);
    for (auto edge : edges) {
        int weight = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if (ds.findParent(u) != ds.findParent(v)) { // If u and v are in different sets
            sum += weight; // Add the weight to the total cost
            ds.unionBySize(u, v); // Union the sets
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

    int result = kruskalsAlgorithm(n, graph);
    cout << "Total weight of the minimum spanning tree: " << result << endl;

    return 0;
}