#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    queue<pair<pair<int,int>,int>> q;
    int visited[m][n];
    int fresh = 0;
    for (int i=0 ; i<m ; i++) {
        for (int j=0 ; j<n ; j++) {
            if (grid[i][j] == 2) {
                q.push({{i,j},0});
                visited[i][j] = 2;
            }
            else visited[i][j] = 0;
            
            if (grid[i][j] == 1) fresh++;
        }
    }

    int minutes = 0;
    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};
    while(!q.empty()) {
        int row = q.front().first.first;
        int column = q.front().first.second;
        int t = q.front().second;
        q.pop();
        minutes = max(minutes, t);
        for (int i=0 ; i<4 ; i++) {
            int nrow = row + drow[i];
            int ncolumn = column + dcol[i];
            if (nrow >= 0 && nrow < m &&
                ncolumn >= 0 && ncolumn < n &&
                grid[nrow][ncolumn] == 1 &&
                visited[nrow][ncolumn] == 0) {
                    
                    visited[nrow][ncolumn] = 2;
                    q.push({{nrow,ncolumn},t+1});
                    fresh--;
                }
        }
    }

    if (fresh != 0) return -1;
    return minutes;
}

int main() {
    vector<vector<int>> grid = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };
    int result = orangesRotting(grid);
    cout << "Minimum time to rot all oranges: " << result << endl;
    return 0;
}