#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& visited, string& path, char dir) {
    int m = grid.size();
    int n = grid[0].size();
    visited[row][col] = 1;
    path += dir;

    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};
    char moves[4] = {'U', 'R', 'D', 'L'};

    for (int i = 0; i < 4; i++) {
        int nrow = row + drow[i];
        int ncol = col + dcol[i];
        if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
            grid[nrow][ncol] == 1 && !visited[nrow][ncol]) {
            dfs(nrow, ncol, grid, visited, path, moves[i]);
        }
    }

    path += 'B';
}


int numDistinctIslands(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> visited(m, vector<int>(n, 0));
    set<string> shapes;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                string path = "";
                dfs(i, j, grid, visited, path, 'S');
                // cout << "Path for island starting at (" << i << ", " << j << "): " << path << endl;
                shapes.insert(path);
            }
        }
    }

    return shapes.size();
}

int main() {
    vector<vector<int>> grid = {
        {1, 1, 0, 0, 0},
        {1, 0, 0, 1, 1},
        {0, 0, 0, 1, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 0, 1}
    };

    cout << "Number of distinct islands: " << numDistinctIslands(grid) << endl;

    return 0;
}