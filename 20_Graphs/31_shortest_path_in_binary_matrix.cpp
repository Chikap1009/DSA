#include <bits/stdc++.h>
using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    if (grid[0][0] == 1) return -1;
    int n = grid.size();
    if (n==1) return 1;
    vector<vector<int>> dist(n, vector<int> (n, 1e9));
    queue<pair<int,pair<int,int>>> q;

    dist[0][0] = 1;
    q.push({1,{0,0}});

    while(!q.empty()) {
        int d = q.front().first;
        int row = q.front().second.first;
        int col = q.front().second.second;
        q.pop();

        int drow[8] = {-1,0,1,0,-1,-1,1,1};
        int dcol[8] = {0,1,0,-1,-1,1,1,-1};

        for (int i=0 ; i<8 ; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n &&
                grid[nrow][ncol] == 0 &&
                d + 1 < dist[nrow][ncol]) {
                    if (nrow == n-1 && ncol == n-1) return d+1;
                    dist[nrow][ncol] = d + 1;
                    q.push({dist[nrow][ncol],{nrow,ncol}});
                }
        }
    }

    return -1;
}

int main() {
    vector<vector<int>> grid = {{0,1},{1,0}};
    cout << shortestPathBinaryMatrix(grid) << endl; // Output: 2
    return 0;
}