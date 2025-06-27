#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> parent, componentSize;

    DisjointSet(int n) {
        componentSize.resize(n, 0);
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

vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
    DisjointSet ds(m*n);
    vector<vector<int>> visited(m, vector<int> (n,0));

    vector<int> ans;

    int drow[4] = {-1,0,1,0};
    int dcol[4] = {0,1,0,-1};

    int islands = 0;

    for (auto it : positions) {
        int row = it[0];
        int col = it[1];

        if (visited[row][col]){
            ans.push_back(islands);
            continue;
        }

        islands++;
        visited[row][col] = 1;

        for (int i=0 ; i<4 ; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            int nodeNo = row * n + col;

            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n) {
                int adjNodeNo = nrow * n + ncol;

                if (visited[nrow][ncol]) {
                    if (ds.findParent(adjNodeNo) != ds.findParent(nodeNo)) {
                        islands--;
                        ds.unionBySize(adjNodeNo, nodeNo);
                    }
                }
            } 
        }

        ans.push_back(islands);
    }

    return ans;
}

int main() {
    int m = 3, n = 3;
    vector<vector<int>> positions = {{0,0}, {0,1}, {1,2}, {2,1}, {1,1}, {2,2}};
    
    vector<int> result = numIslands2(m, n, positions);
    
    for (int count : result) {
        cout << count << " ";
    }
    cout << endl;

    return 0;
}