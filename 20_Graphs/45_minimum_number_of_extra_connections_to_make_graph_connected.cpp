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

int makeConnected(int n, vector<vector<int>>& connections) {
    DisjointSet ds(n);

    int extras = 0;
    for (auto it : connections) {
        int u = it[0];
        int v = it[1];

        if (ds.findParent(u) == ds.findParent(v)) extras++;
        else ds.unionBySize(u,v);
    }

    int count = 0;
    for (int i=0 ; i<n ; i++) {
        if (ds.findParent(i) == i) count++;
    }

    int ans = count-1;

    if (extras >= ans) return ans;
    return -1;
}


int main() {
    int n = 4;
    vector<vector<int>> connections = {{0,1},{0,2},{1,2}};

    cout << makeConnected(n, connections) << endl; // Output: 1

    return 0;
}