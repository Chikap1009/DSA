#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int recursion(vector<vector<int>>& obstacleGrid, int r, int c) {
    if (r == 0 && c == 0) return 1;
    if (r < 0 || c < 0) return 0;
    if (obstacleGrid[r][c] == 1) return 0;
    int up = recursion(obstacleGrid, r-1, c);
    int left = recursion(obstacleGrid, r, c-1);
    return up + left;
}

int uniquePathsWithObstaclesRecursion(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    return recursion(obstacleGrid, m-1, n-1);
}

int memoization(vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp, int r, int c) {
    if (r == 0 && c == 0) return 1;
    if (r < 0 || c < 0) return 0;
    if (obstacleGrid[r][c] == 1) return 0;
    if (dp[r][c] != -1) return dp[r][c];
    int up = memoization(obstacleGrid, dp, r-1, c);
    int left = memoization(obstacleGrid, dp, r, c-1);
    return dp[r][c] = up + left;
}

int uniquePathsWithObstaclesMemoization(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int> (n, -1));
    return memoization(obstacleGrid, dp, m-1, n-1);
}

int uniquePathsWithObstaclesTabulation(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
            if (obstacleGrid[r][c] == 1) {
                dp[r][c] = 0;
                continue;
            }
            if (r == 0 && c == 0) {
                dp[r][c] = 1;
            } else {
                int up = (r > 0) ? dp[r-1][c] : 0;
                int left = (c > 0) ? dp[r][c-1] : 0;
                dp[r][c] = up + left;
            }
        }
    }
    return dp[m-1][n-1];
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<int> prevRow(n, 0);
    if (obstacleGrid[0][0] == 1) return 0;
    for (int r = 0 ; r < m ; r++) {
        vector<int> currRow(n, 0);
        for (int c = 0 ; c < n ; c++) {
            if (r == 0 && c == 0) currRow[0] = 1;
            else if (obstacleGrid[r][c] == 1) currRow[c] = 0;
            else {
                int up = prevRow[c];
                int left = 0;
                if (c > 0) left = currRow[c-1];
                currRow[c] = up + left;
            }
        }
        prevRow = currRow;
    }
    return prevRow[n-1];
}

int main() {
    vector<vector<int>> obstacleGrid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    cout << "Number of unique paths in a " << obstacleGrid.size() << "x" << obstacleGrid[0].size() << " grid: " << uniquePathsWithObstaclesRecursion(obstacleGrid) << endl;
    cout << "Number of unique paths in a " << obstacleGrid.size() << "x" << obstacleGrid[0].size() << " grid (with memoization): " << uniquePathsWithObstaclesMemoization(obstacleGrid) << endl;
    cout << "Number of unique paths in a " << obstacleGrid.size() << "x" << obstacleGrid[0].size() << " grid (with tabulation): " << uniquePathsWithObstaclesTabulation(obstacleGrid) << endl;
    cout << "Number of unique paths in a " << obstacleGrid.size() << "x" << obstacleGrid[0].size() << " grid (space optimized): " << uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}