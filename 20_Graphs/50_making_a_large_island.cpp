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

int largestIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    
    DisjointSet ds(n*n);

    int drow[2] = {-1,0};
    int dcol[2] = {0,-1};

    int maxSize = 0;

    for (int i=0 ; i<n ; i++) {
        for (int j=0 ; j<n ; j++) {
            if (grid[i][j]) {
                int row = i;
                int col = j;
                for (int k=0 ; k<2 ; k++) {
                    int nrow = row + drow[k];
                    int ncol = col + dcol[k];

                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol]) {
                            ds.unionBySize(nrow*n + ncol, row*n + col);
                        }
                }
                maxSize = max(maxSize, ds.componentSize[ds.findParent(row*n + col)]);
            }
        }
    }

    int dRow[4] = {-1,0,1,0};
    int dCol[4] = {0,1,0,-1};

    for (int i=0 ; i<n ; i++) {
        for (int j=0 ; j<n ; j++) {
            int row = i;
            int col = j;

            if (!grid[i][j]) {
                unordered_set<int> st;
                for (int k=0 ; k<4 ; k++) {
                    int nrow = row + dRow[k];
                    int ncol = col + dCol[k];

                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n &&
                        grid[nrow][ncol]) {
                            st.insert(ds.findParent(nrow*n + ncol));
                        }
                }
                int tempSize = 1;
                for (auto it : st) {
                    tempSize += ds.componentSize[it];
                }
                maxSize = max(maxSize, tempSize);
            }
        }
    }

    return maxSize;
}

int main() {
    vector<vector<int>> grid = {{1,0},{0,1}};
    cout << largestIsland(grid) << endl; // Output: 3
    return 0;
}