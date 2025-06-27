#include <bits/stdc++.h>
using namespace std;

int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size();

    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    vector<vector<int>> minTimePath(n, vector<int>(n, 1e9));

    pq.push({grid[0][0],{0,0}});
    minTimePath[0][0] = grid[0][0];

    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};

    while(!pq.empty()) {
        int timeTaken = pq.top().first;
        int row = pq.top().second.first;
        int col = pq.top().second.second;
        pq.pop();

        if (row == n-1 && col == n-1) return timeTaken;

        for (int i=0 ; i<4 ; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n &&
                max(timeTaken,grid[nrow][ncol]) < minTimePath[nrow][ncol]) {
                    minTimePath[nrow][ncol] = max(timeTaken,grid[nrow][ncol]);
                    pq.push({minTimePath[nrow][ncol],{nrow,ncol}});
                }
        }
    }

    return -1;
}

int main() {
    vector<vector<int>> grid = {{0,2},{1,3}};
    cout << swimInWater(grid) << endl; // Output: 3
    return 0;
}