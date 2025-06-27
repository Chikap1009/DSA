#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent, rank;

public:
    DisjointSet(int n) {
        rank.resize(n, 0);
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

    void unionByRank(int u, int v) {
        int parentU = findParent(u);
        int parentV = findParent(v);

        if (parentU == parentV) return; // They are already in the same set

        if (rank[parentU] < rank[parentV]) {
            parent[parentU] = parentV; // Attach smaller rank tree under larger rank tree
        } else if (rank[parentU] > rank[parentV]) {
            parent[parentV] = parentU; // Attach smaller rank tree under larger rank tree
        } else {
            parent[parentV] = parentU; // Arbitrarily choose one as the new root
            rank[parentU]++; // Increase the rank of the new root
        }
    }
};

int main() {
    DisjointSet ds(7); // Create a disjoint set with 7 elements
    ds.unionByRank(0, 1);
    ds.unionByRank(1, 2);
    ds.unionByRank(3, 4);
    ds.unionByRank(4, 5);
    ds.unionByRank(5, 6);

    if (ds.findParent(0) == ds.findParent(6)) {
        cout << "0 and 7 are in the same set." << endl;
    } else {
        cout << "0 and 7 are in different sets." << endl;
    }

    ds.unionByRank(3, 7); // Now all elements are connected

    if (ds.findParent(0) == ds.findParent(6)) {
        cout << "0 and 7 are in the same set." << endl;
    } else {
        cout << "0 and 7 are in different sets." << endl;
    }

    return 0;
}