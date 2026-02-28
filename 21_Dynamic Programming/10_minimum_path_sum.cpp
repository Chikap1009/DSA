#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int recursion(vector<vector<int>>& grid, int r, int c) {
    if (r == 0 && c == 0) return grid[0][0];
    int up = INT_MAX, left = INT_MAX;
    if (r-1 >= 0) up = grid[r][c] + recursion(grid, r-1, c);
    if (c-1 >= 0) left = grid[r][c] + recursion(grid, r, c-1);
    return min(up, left);
}

int minPathSumRecursion(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    return recursion(grid, m-1, n-1);
}

int memoization(vector<vector<int>>& grid, vector<vector<int>>& dp, int r, int c) {
    if (r == 0 && c == 0) return grid[0][0];
    if (dp[r][c] != -1) return dp[r][c];
    int up = INT_MAX, left = INT_MAX;
    if (r-1 >= 0) up = grid[r][c] + memoization(grid, dp, r-1, c);
    if (c-1 >= 0) left = grid[r][c] + memoization(grid, dp, r, c-1);
    return dp[r][c] = min(up, left);
}

int minPathSumMemoization(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int> (n,-1));
    return memoization(grid, dp, m-1, n-1);
}

int minPathSumTabulation(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int> (n,-1));
    for (int r = 0 ; r < m ; r++) {
        for (int c = 0 ; c < n ; c++) {
            if (r==0 && c==0) dp[r][c] = grid[0][0];
            else {
                int up = INT_MAX, left = INT_MAX;
                if (r-1 >= 0) up = grid[r][c] + dp[r-1][c];
                if (c-1 >= 0) left = grid[r][c] + dp[r][c-1];
                dp[r][c] = min(up, left);
            }
        }
    }
    return dp[m-1][n-1];
}

int minPathSumSpaceOptimized(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<int> prevRow(n, INT_MAX);
    for (int r = 0 ; r < m ; r++) {
        vector<int> currRow(n, 0);
        for (int c = 0 ; c < n ; c++) {
            if (r==0 && c==0) currRow[c] = grid[0][0];
            else {
                int up = INT_MAX, left = INT_MAX;
                if (r-1 >= 0) up = grid[r][c] + prevRow[c];
                if (c-1 >= 0) left = grid[r][c] + currRow[c-1];
                currRow[c] = min(up, left);
            }
        }
        prevRow = currRow; 
    }
    return prevRow[n-1];
}

int main() {
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    cout << "Minimum path sum in the grid: " << minPathSumRecursion(grid) << endl;
    cout << "Minimum path sum in the grid (with memoization): " << minPathSumMemoization(grid) << endl;
    cout << "Minimum path sum in the grid (with tabulation): " << minPathSumTabulation(grid) << endl;\
    cout << "Minimum path sum in the grid (space optimized): " << minPathSumSpaceOptimized(grid) << endl;
    return 0;
}