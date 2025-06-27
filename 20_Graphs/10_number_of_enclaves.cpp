#include <bits/stdc++.h>
using namespace std;

int numEnclaves(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> visited (m, vector<int> (n,0));
    queue<pair<int,int>> q;

    for (int j=0 ; j<n ; j++) {
        if (grid[0][j] == 1) {
            q.push({0,j});
            visited[0][j] = 1;
        }
        if (grid[m-1][j] == 1) {
            q.push({m-1,j});
            visited[m-1][j] = 1;
        }
    }

    for (int i=1 ; i<m-1 ; i++) {
        if (grid[i][0] == 1) {
            q.push({i,0});
            visited[i][0] = 1;
        }
        if (grid[i][n-1] == 1) {
            q.push({i,n-1});
            visited[i][n-1] = 1;
        }
    }

    while(!q.empty()) {
        int row = q.front().first;
        int column = q.front().second;
        q.pop();

        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};

        for (int i=0 ; i<4 ; i++) {
            int nrow = row + drow[i];
            int ncol = column + dcol[i];

            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1 && !visited[nrow][ncol]) {
                visited[nrow][ncol] = 1;
                q.push({nrow,ncol});
            }
        }
    }

    int count = 0;
    for (int i=0 ; i<m ; i++) {
        for (int j=0 ; j<n ; j++) {
            if (!visited[i][j] && grid[i][j] == 1) count++;
        }
    }

    return count;
}

int main() {
    vector<vector<int>> grid = {
        {0, 0, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 1, 0, 0}
    };

    int result = numEnclaves(grid);
    cout << "Number of enclaves: " << result << endl;

    return 0;
}