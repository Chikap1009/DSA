#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> parent, componentSize;

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
    
int removeStones(vector<vector<int>>& stones) {
    int n = stones.size();
    int maxRow = 0;
    int maxCol = 0;
    for (auto it : stones) {
        maxRow = max(maxRow, it[0]);
        maxCol = max(maxCol, it[1]);
    }

    DisjointSet ds(maxRow + maxCol + 2);
    for (auto it : stones) {
        ds.unionBySize(it[0], it[1] + maxRow + 1);
    }

    int count = 0;
    for (int i=0 ; i<maxRow + maxCol + 2 ; i++) {
        if (ds.parent[i] == i && ds.componentSize[i] > 1) count++;
    }
    return n-count;
}

int main() {
    vector<vector<int>> stones = {{0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}};
    int result = removeStones(stones);
    cout << "Maximum number of stones that can be removed: " << result << endl;
    return 0;
}