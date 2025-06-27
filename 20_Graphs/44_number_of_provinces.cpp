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

int numberOfProvinces(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    DisjointSet ds(n);

    for (int i=0 ; i<n ; i++) {
        for (int j=0 ; j<n ; j++) {
            if (isConnected[i][j] == 1 && i != j) {
                ds.unionBySize(i, j); // Union the two cities
            }
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (ds.findParent(i) == i) { // Count the number of unique parents
            count++;
        }
    }

    return count; // Return the number of provinces
}

int main() {
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    cout << "Number of provinces: " << numberOfProvinces(isConnected) << endl; // Output: 2
    return 0;
}